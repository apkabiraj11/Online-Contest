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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> grid(h + 2, vector<int>(w + 2));
    for(int i = 1; i <= h; i++){
    	string temp;
    	cin >> temp;
    	for(int j = 0; j < w; j++){
    		if(temp[j] == '0'){
    			grid[i][j + 1] = 0;
    		}
    		else grid[i][j + 1] = 1;
    	}
    }
    vector<vector<ll>> pref(h + 1, vector<ll>(w + 1, 0));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            pref[i][j] = grid[i][j]
                       + pref[i - 1][j]
                       + pref[i][j - 1]
                       - pref[i - 1][j - 1];
        }
    }

    ll cnt = 0;

    for (int r1 = 1; r1 <= h; r1++) {
        for (int c1 = 1; c1 <= w; c1++) {
            for (int r2 = r1; r2 <= h; r2++) {
                for (int c2 = c1; c2 <= w; c2++) {

                    ll sum = pref[r2][c2]
                           - pref[r1 - 1][c2]
                           - pref[r2][c1 - 1]
                           + pref[r1 - 1][c1 - 1];

                    cnt += (sum == k);
                }
            }
        }
    }

    cout << cnt << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
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

