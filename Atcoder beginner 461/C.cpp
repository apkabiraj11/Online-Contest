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
    int n, k, m;
    cin >> n >> k >> m;
    vector<multiset<int>> ar(n + 2);
    for(int i = 0; i < n; i++){
    	int c, v;
    	cin >> c >> v;
    	ar[c].insert(v);
    }
    vector<int>last;
    for(auto &st : ar){
    	if(st.size()){
    		last.push_back(*st.rbegin());
    		st.erase(prev(st.end()));
    	}
    }
    sort(last.begin(),last.end());
    ll ans = 0;
    while(m && k){
    	ans += last.back();
    	last.pop_back();
    	m--, k--;
    }
     for(auto &st : ar){
    	if(st.size()){
    		for(auto x : st){
    			last.push_back(x);
    		}
    	}
    }

    sort(last.begin(),last.end());

    while(k){
    	ans += last.back();
    	last.pop_back();
    	k--;
    }

    cout << ans << ln;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
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

