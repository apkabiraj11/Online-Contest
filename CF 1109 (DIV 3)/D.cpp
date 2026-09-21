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
    int n, m;
    cin >> n >> m;
    vector<int>ar(n + 1), br(m);
    for(int i = 1; i <= n; i++)
        cin >> ar[i];
    for(int i= 0; i < m; i++){
        cin >> br[i];
    }

    sort(br.begin(),br.end());

    vector<ll> neg(n + 2), pos(n + 2);
    ll minus = 0, plus = 0;
    for(int i = 1; i <= n; i++){
        if(ar[i] < 0){
            minus += abs(ar[i]);
        }
        else {
            plus += ar[i];
        }

        neg[i] = minus;
        pos[i] = plus;
    }

    // for(int i = 0; i < n; i++){
    //     cout << neg[i] << " ";
    // }
    // cout << ln;
    // for(int i = 0; i < n; i++){
    //     cout << pos[i] << " ";
    // }
    // cout << ln;
    vector<int> check(n + 2);
    int sign = 0;
    for(int i = m - 1; i >= 0; i--){
        int r = br[i];
        int l = 0;
        if(i > 0)
            l = br[i - 1];

        // l--, r--;
        ll rightneg = neg[r] - neg[l];
        ll rightpos = pos[r] - pos[l];

        if(sign % 2)
            swap(rightneg, rightpos);

        // cout << sign << ln;

        // cout << rightneg << " "<< rightpos << ln;

        if(rightneg > rightpos){
            sign++;
            check[r] = 1;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << check[i] << " ";
    // }
    // cout << ln;
    ll sum = 0;
    sign = 1;
    for(int i = n; i >= 1; i--){
        if(check[i])
            sign = sign * (-1);

        sum += (sign * ar[i]);
    }

    cout << sum << ln;

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

