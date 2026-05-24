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
    vector<int>ar(n);
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    }
    sort(ar.begin(),ar.end());

	set<ll> temp2;
   	for(int i = 0; i < n; i++){
   		ll small = ar[i];
	    temp2.insert(small);
	    while(small > 1){
	    	temp2.insert(small);
	    	if(small % 2 == 0){
	    		small /= 2;
	    	}
	    	else small++;
	    }
	    temp2.insert(small);
   	}
   	vector<ll>temp(temp2.begin(),temp2.end());
   	// for(auto x : temp){
   	// 	cout << x << " ";
   	// }
    ll ans = 1e18;
    for(int i = 0; i < temp.size(); i++){
    	ll temp_ans = 0;
    	for(int j = 0; j < n; j++){
    		ll res = 0;
    		bool paisi = false;
    		ll x = ar[j];
    		while(x){
		    	if(x == temp[i]){
		    		paisi = true;
		    		break;
		    	}
		    	if(x % 2 == 0){
		    		x /= 2;
		    	}
		    	else x++;
		    	res++;

		    	if(x == 1){
		    		break;
		    	}
		    }
		   	// cout << temp[i] << " " << ar[j] << " " << res << ln;
		    if(x == temp[i]){
	    		paisi = true;
		    }

		    if(!paisi){
		    	temp_ans = 1e18;
		    	break;
		    }
		    else temp_ans += res;

    	}
    	ans = min(ans, temp_ans);
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

