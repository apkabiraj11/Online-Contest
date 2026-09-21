#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 2e5 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

int dp[N];
int n, k;
vector<bool> prime(N, true);
vector<vector<int>> primediv(N);


void sieve() {
    for(int i = 2; i < N; i++) {
        if(primediv[i].empty()) {
            for(int j = i; j < N; j += i) {
                primediv[j].push_back(i);
            }
        }
    }
}

void solve() {

    cin >> n >> k;

    vector<int>ar(n);

    int mx = 0;

    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        mx = max(mx, ar[i]);
    }

    for(int x = 1; x <= k; x++) {
        dp[x] = 0;
    }

    for(int x = k + 1; x <= mx; x++) {

        dp[x] = INT_MAX;

        for(auto p : primediv[x]) {
            dp[x] = min(dp[x], 1 + p * dp[x / p]);
        }
    }

    ll ans = 0;

    for(auto x : ar) {
        ans += dp[x];
    }

    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t = 1;
    cin >> t;

    // int casee = 1;
    while(t--) {
        // cout << "Case " << casee << ": ";
        solve();
        // casee++;
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT

***************/