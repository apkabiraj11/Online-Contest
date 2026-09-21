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
    int n, x, y;
    cin >> n >> x >> y;

    if(x > y)
    	swap(x, y); // x < y


    vector<int>ar(n + 2);
    for(int i = 1; i <= n;i++)
    	cin >> ar[i];

    int z = gcd(x, y);

    for(int i = 1; i <= n; i++){
    	int dif = abs(ar[i] - i);
    	if(dif % x == 0 || dif % y == 0){
    		continue;
    	}
    	else if(z > 0 && dif % z == 0){
    		continue;
    	}
    	else {
    		no; 
    		return;
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

