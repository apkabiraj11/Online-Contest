#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x
const ll N = 2e5 + 9, inf = 2e9;
string a, b;
ll n, dp[2][N];
 
ll f(ll type, ll i) {
   if (i >= n) {
      return 0;
   }
 
   if (dp[type][i] != -1) {
      return dp[type][i];
   }
 
   ll ans = inf;
   if ((i + 1 < n) && (type == 0)) {
      ll cnt = 0;
      if (a[i] != a[i + 1]) {
         cnt++;
      }
      if (b[i] != b[i + 1]) {
         cnt++;
      }
      ans = min(ans, cnt + f(type, i + 2));
      ans = min(ans, cnt + f(type ^ 1, i + 2));
   }
   if (a[i] != b[i]) {
      ans = min(ans, 1 + f(type, i + 1));
      ans = min(ans, 1 + f(type ^ 1, i + 1));
   }
   if (a[i] == b[i]) {
      ans = min(ans, f(type, i + 1));
      ans = min(ans, f(type ^ 1, i + 1));
   }
 
   return dp[type][i] = ans;
}
 
void solve() {
   cin >> n;
   cin >> a;
   cin >> b;
 
   for (ll i = 0;i < 2;i++) {
      for (ll j = 0;j <= n;j++) {
         dp[i][j] = -1;
      }
   }
 
   cout << f(0, 0) << '\n';
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