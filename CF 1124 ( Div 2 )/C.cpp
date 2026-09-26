#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
// 1. find_by_order(k) -> returns iterator to the k-th element (0-indexed)
// 2. order_of_key(x) -> returns number of elements strictly smaller than x


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>ar(n + 1);
    for(int i = 1; i <= n; i++)
    	cin>> ar[i];
    ordered_set<int> st;
    for(int i = 1; i <= n; i++){
    	st.insert(i);
    }
    ll ans = 0;
    while(st.size() >= k){

    	int left = *st.find_by_order(k - 1);
    	int right = *st.find_by_order((int)st.size() - k);

    	if(ar[left] >= ar[right]){
    		ans += ar[left];
    		st.erase(left);
    	}
    	else {
    		ans += ar[right];
    		st.erase(right);
    	}
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
