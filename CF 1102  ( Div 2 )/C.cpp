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
    vector<int>ar(n + 1);
    for(int i= 1; i <= n;i++)
    	cin>> ar[i];

    for(int i = 1; i <= n; i++){
    	vector<int>empty(n + 1, -1);
    	// cout << i << " -> "  << " ";
    	empty[i] = 0;
    	if(i + 1 > n) {
    		empty[1] = ar[n];
    		for(int j = 1; j < i; j++){
    			if(empty[j] > ar[j] && (j + 1) != i){
    				empty[j + 1] = empty[j];
    			}
    			else {
    				if(empty[j + 1] != 0)
    					empty[j + 1] = max(ar[j], empty[j]);
    				else empty[j] = ar[j];
    			}
    		}
    	}
    	else{
    		empty[i + 1] = ar[i];
    		for(int j = i + 1; j < n; j++){
    			if(empty[j] > ar[j]){
    				empty[j + 1] = empty[j];
    			}
    			else {
    				if(empty[j + 1] != 0)
    					empty[j + 1] = max(ar[j], empty[j]);
    				else empty[j] = ar[j];
    			}
    		}
    		if(empty[1] != 0){
    			if(empty[n] > ar[1]){
    				empty[1] = empty[n];
    			}
    			else {
    				empty[1] = max(ar[1], empty[n]);
    			}
    			for(int j = 1; j < i; j++){
	    			if(empty[j] > ar[j] && (j + 1) != i){
	    				empty[j + 1] = empty[j];
	    			}
	    			else {
	    				if(empty[j + 1] != 0)
	    					empty[j + 1] = max(ar[j], empty[j]);
	    				else empty[j] = ar[j];
	    			}
	    		}

    		}
    	}
    	
		if(i > 1){
			empty[i - 1] = ar[i - 1];
			for(int j = i - 1; j > 1; j--){
				if(empty[j] > ar[j - 1] ){
    				empty[j - 1] = empty[j];
    			}
    			else {
    				empty[j - 1] = max(ar[j - 1], empty[j]);
    				
    			}
			}
		}

    	ll sum = 0;
    	for(int i = 1; i <= n; i++){
    		sum += empty[i];
    		// cout << empty[i] << " ";
    	}
    	// cout << ln;
    	cout << sum << " ";
    }
    cout << ln;

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

