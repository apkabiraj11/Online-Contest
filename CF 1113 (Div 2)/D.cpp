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
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;

    vector<int> pref[3];
    pref[0].resize( n + 2); // 0 = equal
    pref[1].resize( n + 2); // 10
    pref[2].resize( n + 2); // 01


    for(int i = 0; i < n; i++){
        if(s[i] == t[i]){
            pref[0][i + 1] = pref[0][i] + 1;
            pref[1][i + 1] = pref[1][i];
            pref[2][i + 1] = pref[2][i];
        }
        else if(s[i] == '0' && t[i] == '1'){
            pref[0][i + 1] = pref[0][i];
            pref[1][i + 1] = pref[1][i] + 1;
            pref[2][i + 1] = pref[2][i];
        }
        else {
            pref[0][i + 1] = pref[0][i];
            pref[1][i + 1] = pref[1][i];
            pref[2][i + 1] = pref[2][i] + 1;
        }
    }


    while(q--){
        int l, r;
        cin >> l >> r;
        int eq = pref[0][r] - pref[0][l - 1];
        int a = pref[1][r] - pref[1][l - 1];
        int b = pref[2][r] - pref[2][l - 1];    

        if(abs(a - b) <= eq){
            yes;
        }
        else no;
    }


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

