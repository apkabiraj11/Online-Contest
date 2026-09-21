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
    string s;
    cin >> s;
    vector<int> pref(n);
   	pref[0] = (s[0] == '0');
   	for(int i = 1; i < n; i++){
   		pref[i] = pref[i - 1] + (s[i] == '0');
   		
   	}

   	if(s[0] == '1'){
   		int i = 0;
   		while(i < n && s[i] == '1'){
   			i++;
   		}

   		int j = i;
   		i = 0;
   		while(j < n){
   			if(s[j] == '0')
   				i++;

   			j++;
   		}

   		cout << i << ln;
   		return;
   	}

   	int ans = pref[n - 1];
   	int one = 0;
   	bool consecutive = true;
   	for(int i = 0; i < n; i++){
   		int zero = pref[n - 1] - pref[i];
   		one += (s[i] == '1');
   		ans = min(ans, zero + one);
   		
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

