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
    for(int i = 0; i < n; i++)
    	cin>> ar[i];

    for(int i = 0; i < n; i++)
    	cin>> br[i];

    auto check = [&](int mid){
    	int zero = 0, two = 0;
    	int last = 1;
    	for(int i = 0; i < n; i++){
    		int cnt = 0;
    		if(ar[i] >= mid)
    			cnt++;
    		if(br[i] >= mid)
    			cnt++;

    		if(cnt == 2){
    			two++;
    			last = 2;
    		}
    		else if(cnt == 0 && last != 0){
    			zero++;
    			last = 0;
    		}
    	}

    	return two > zero;

    };


    int l = 0, r = 2 * n + 1;
    int ans = 0;
    while(l <= r){
    	int mid= (l + r ) / 2;
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}
    	else r = mid - 1;
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

6
3 6 12 4 10 12
2 3 2 7 8 9

	0 1 1 
	0 1 1 
----------------------
	2


0 0 -> 0
0 1 -> 0
0 2 -> 1
1 0 -> 0
1 1 -> 1
1 2 -> 2
2 0 -> 1
2 1 -> 2
2 2 -> 2


***************/

