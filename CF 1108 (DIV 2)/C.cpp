//this was a testing code. tested after the contest

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long power_mod(long long base, long long exp, long long mod) {
    base %= mod;
    if (base < 0) base += mod;
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Group into runs of equal values (array is non-decreasing)
        vector<pair<long long,int>> groups; // (value, count)
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            groups.push_back({a[i], j - i});
            i = j;
        }

        int g = (int)groups.size();
        bool has_neg1 = (groups[0].first == -1);

        // collect positive values in increasing order
        vector<long long> positive_values;
        for (auto &pr : groups) {
            if (pr.first > 0) positive_values.push_back(pr.first);
        }

        int count_pairs = 0;
        for (int k = 0; k + 1 < (int)positive_values.size(); k++) {
            if (positive_values[k+1] - positive_values[k] == 1) {
                count_pairs++;
            }
        }

        long long N = 1 + (has_neg1 ? count_pairs : 0);
        N %= MOD;

        long long ans = power_mod(2, n - g, MOD) * N % MOD;
        cout << ans << "\n";
    }

    return 0;
}