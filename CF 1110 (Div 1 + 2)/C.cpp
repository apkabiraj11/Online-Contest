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
vector<int> construct(int n, int k) {

   int target = k ^ n;

    int m = 1;
    while ((m << 1) <= n - 1) m <<= 1;

    if (target >= (m << 1)) return {};

    vector<int> ans = {};

    for (int p = 1; p <= m; p <<= 1) {
        if (target & p) ans.push_back(p);
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

	if(n == 1 && k == 0){
		no;
		return;
	}	
    auto x = construct(n, k);

    multiset<int>st;
    for(auto v : x)
    	st.insert(v);


    vector<int>ar;
    for(int i = n - 1; i > 0; i--){
    	if(st.find(i) == st.end()){
    		ar.push_back(i);
    	}
    }
	ar.push_back(0);
	for(auto xx : st){
		ar.push_back(xx);
	}

    // for(auto v : x){
    // 	cout << v << " ";
    // }
    // cout << ln;
    // for(auto v : st){
    // 	cout << v << " ";
    // }
    // cout << ln;
    // for(auto v : ar){
    // 	cout << v << " ";
    // }
    // cout << ln;

	int xorr = 0;
	set<int>tt;
	int mex = 0;
	for(int i = 0; i < n; i++){
		tt.insert(ar[i]);
		
		while(tt.find(mex) != tt.end()){
			mex++;
		}

		xorr ^= mex;
		// cout << i << " -> " << xorr << ln;
	}
	
	if(xorr == k){
		yes;
		for(auto x : ar){
			cout << x << " ";
		}
		cout << ln;
	}
	else no;


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

