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
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar.begin(),ar.end());
    swap(ar[0], ar[n - 1]);
    vector<int>extra;
    set<int>st;
    for(int i = 1; i < n; i++){
        if(st.count(ar[i])){
            extra.push_back(ar[i]);
        }
        else st.insert(ar[i]);
        // cout << ar[i] << " ";
    }

    // for(auto x : extra)
    //     cout << x << " ";
    // cout << ln;

    vector<int>final;
    final.push_back(ar[0]);
    for(auto x : st)
        final.push_back(x);
    for(auto x : extra)
        final.push_back(x);

    ll ans = 0;
    set<int>temp;
    int mex = 0, mx = 0;
    for(auto x : final){
        mx = max(mx, x);
        temp.insert(x);
        while(temp.count(mex)) mex++;
        ans += (mx + mex);
        // cout << x << " ";
    }
    cout << ans <<ln;

    

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

