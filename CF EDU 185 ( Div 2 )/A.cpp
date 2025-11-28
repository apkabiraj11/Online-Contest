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


void solve() {
   int n;
   cin >> n;
   int ar[n][n];
   int x = 1;
   for(int i = 0; i < n; i++){
   	for(int j = 0; j < n; j++){
   		ar[i][j] = x;
   		x++;
   	}
   }
   ll res = 0;
   for(int i = 0; i < n; i++){
   	for(int j = 0; j < n; j++){
   		ll ans = ar[i][j];
   		if(i - 1 >= 0)
   			ans += ar[i - 1][j];
   		if(i + 1 < n)
   			ans += ar[i + 1][j];
   		if(j - 1 >= 0)
   			ans += ar[i][j - 1];
   		if(j + 1 < n)
   			ans += ar[i][j + 1];
   		res = max(res, ans);
   	}
   }
   cout << res << ln;
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

