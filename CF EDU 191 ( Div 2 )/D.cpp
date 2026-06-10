#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
void solve() {
    int n;
    cin >> n;

    vector<int> ar(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    map<int, pair<int,int>> mp;

    for (int i = 1; i <= n; i++) {
        if (!mp.count(ar[i])) {
            mp[ar[i]] = {i, i};
        } else {
            mp[ar[i]].second = i;
        }
    }

    // BIT
    BIT bit(n);

    // activate each value at its last position (simple version)
    vector<int> last(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        last[ar[i]] = i;
    }

    for (auto &it : mp) {
        int l = it.second.first;
        int r = it.second.second;

        // mark contribution at r only (last occurrence idea)
        bit.add(r, 1);
    }

  	for(auto [x,y] : mp){
  		cout << bit.query(y.first, y.second) << ln;
  	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

