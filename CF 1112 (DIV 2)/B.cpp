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
    int n, k;
    cin >> n >> k;


    int zero = (k + 1) / 2;
    int one = k - zero;

    string ans = "";
    if(zero){
    	ans += "00";
    	zero--;
    	while(zero){
    		ans += "0";
    		zero--;
    	}
    }
    if(one){
    	ans += "11";
    	one--;
    	while(one){
    		ans += "1";
    		one--;
    	}
    }

    if(ans.size() < n){
    	ans = "1" + ans;
    }

    if(ans.back() == '0'){
    	while(ans.size() < n){
    		ans += "1";
    		if(ans.size() < n){
    			ans += "0";
    		}
    	}
    }
    else {
    	while(ans.size() < n){
    		ans += "0";
    		if(ans.size() < n){
    			ans += "1";
    		}
    	}
    }
    int cnt = 0;
    int sunno = 0, ek = 0;
    for(int i = 0; i < ans.size() - 1; i++){
    	if(ans[i] == '1')
    		ek++;
    	else sunno++;
    	if(ans[i] == ans[i + 1]){
    		cnt++;
    	}
    }

    if(ans.back() == '1')
    		ek++;
    	else sunno++;


    if(ans.size() == n && cnt == k && abs(sunno - ek) <= 1){
    	cout << ans << ln;
    }
    else cout << -1 << ln;
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

