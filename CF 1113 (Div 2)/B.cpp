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
    int n, m;
    cin >> n >> m;
    vector<int>ar(n), br(m);
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 0; i < m; i++) cin >> br[i];

    if(n < m){
    	no;
    	return;
    }
    if(n == m){
    	for(int i = 0; i < n; i++){
    		if(ar[i] != br[i]){
    			no;
    			return;
    		}
    	}
    	yes;
    	return;
    }

    multiset<int>st(ar.begin(),ar.end());
    multiset<int>bt(br.begin(),br.end());
    multiset<int>ct = st;

    for(auto x : ct){
    	if(st.count(x) && bt.count(x)){
    		st.erase(st.find(x));
    		bt.erase(bt.find(x));
    	}
    }

    for(auto x : bt){
    	if(st.empty()){
    		no;
    		return;
    	}

    	int begin = *st.begin();
    	if(begin > x){
    		no;
    		return;
    	}
    	st.erase(st.begin());
    }

    for(auto x : bt){
    	if(st.empty()){
    		no;
    		return;
    	}

    	int begin = *st.begin();
    	if(begin < x){
    		while(!st.empty() && *st.begin() < x){
    			st.erase(st.begin());
    		}
    		if(!st.empty()){
    			st.erase(st.begin());
    		}
    		else {
    			no;
    			return;
    		}
    	}
    	else {
    		st.erase(st.begin());
    	}
    }
    yes;


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

