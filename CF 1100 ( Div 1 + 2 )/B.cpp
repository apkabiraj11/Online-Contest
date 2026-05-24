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
    vector<int>ar(n), br(n);
    for(int i = 0; i < n;i++) cin >> ar[i];
    for(int i = 0; i < n; i++) cin >> br[i];

    for(int i = 0; i < n; i++){
    	if(br[i] < ar[i]){
    		swap(ar[i], br[i]);
    	}
    }

    ll tot = 0;
    for(int i = 0; i < n; i++){
    	tot += br[i];
    }

    multiset<int>st(ar.begin(),ar.end());
    ll ans = tot + (*st.rbegin());
    for(int i = 0; i < n;i++){

    	int a = ar[i], b = br[i];
    	st.insert(b);
    	st.erase(st.find(a));

    	int mx = *st.rbegin();
    	ll tempsum = tot - b + a;

    	ans = max(ans, mx + tempsum);

    	st.insert(a);
    	st.erase(st.find(b));
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

