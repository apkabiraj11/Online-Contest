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
    int a= 0, b = 0;
    for(int i = 0; i < n; i++){
    	cin >> ar[i];
    	a += ar[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> br[i];
    	b += br[i];
    }

    bool ok = true;
    for(int i= 0; i < n; i++){
    	if(ar[i] != br[i]){
    		ok = false;
    		break;
    	}
    }
    if(ok){
    	cout << 0 << ln;
    	return;
    }

    if (a == 0) {
        cout << -1 << ln;
        return;
    }

    if (b == n) {
        cout << -1 << ln;
        return;
    }

    int one = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] != br[i]) {
            one += ar[i];
        }
    }

    if (one % 2) cout << 1 << ln;
    else cout << 2 << ln;



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

