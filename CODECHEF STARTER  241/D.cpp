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
    ll n, m, k;
    cin >> n >>m >> k;
    ll ful = 0;
    vector<ll>extra;
    for(int i = 1; i <= n;i++){
    	int x;
    	cin >> x;
    	ful += (x / k);
    	extra.push_back(x % k);
    }
    ll roses = 0;
   	ll l = 0, r = ful;
   	ll block = 0;
   	while(l <= r){
   		ll mid = (l + r) / 2;
   		ll pots = mid * (k + 1);
   		if(pots <= m){
   			block = mid;
   			l = mid + 1;
   		}
   		else r = mid - 1;
   	}

   	roses += (block * k);
   	m -= (block * (k + 1));
   	ful -= block;
   	if(ful)
   		extra.push_back(k);
   	sort(extra.rbegin(), extra.rend());
   	for(int i = 0; i < extra.size(); i++){
   		if(m > extra[i]){
   			roses += extra[i];
   			m -= extra[i];
   			if(m)
   				m--;
   		}
   		else {
   			roses += m;
   			break;
   		}
   	}
   	cout << roses << ln;

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

