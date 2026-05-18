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
    string s;
    cin >> s;

    int n = s.size();
    s = "#" + s;

    vector<ll>preone(n + 2), prethree(n + 2), pretwo(n + 2);
    ll cnt = 0;

    for(int i = 1; i <= n; i++){
    	if(s[i] == '4')
    		cnt++;
    	if(s[i] == '1')
    		preone[i] = preone[i - 1] + 1;
    	else preone[i] = preone[i - 1];

    	if(s[i] == '2')
    		pretwo[i] = pretwo[i - 1] + 1;
    	else pretwo[i] = pretwo[i - 1];

    	if(s[i] == '3')
    		prethree[i] = prethree[i - 1] + 1;
    	else prethree[i] = prethree[i - 1];
    }
    ll ans = mod;
    for(int i = 1; i <= n; i++){
    	ll left13 = preone[i - 1] + prethree[i - 1];
    	ll right2 = pretwo[n] - pretwo[i];

    	ans = min(ans, (left13 + right2 + cnt));
    }
    cout << ans << ln;


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

