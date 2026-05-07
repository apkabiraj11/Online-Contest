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
    vector<int>ar, br;
    for(int i = 0; i < 2 * n; i++){
        int x;
        cin >> x;
        ar.push_back(x);
        if(x == 0)
            br.push_back(i);
    }

    auto get_mex = [&](auto v){

        set<int>st(v.begin(),v.end());
        int mex = 0;
        for(auto x : st){
            if(x == mex)
                mex++;
            else break;
        }

        return mex;
    };

    //left 0 as centre
    int idx = br[0];
    deque<int>dq;
    int l = idx, r = idx;
    while(l >= 0 && r < 2 * n && ar[l] == ar[r]){
        dq.push_back(ar[l]);
        l--, r++;
    }
    int ans = get_mex(dq);

    dq.clear();
    idx = br[1];
    l = idx, r = idx;
    while(l >= 0 && r < 2 * n && ar[l] == ar[r]){
        dq.push_back(ar[l]);
        l--, r++;
    }

    ans = max(ans, get_mex(dq));

    bool ok = true;

    dq.clear();
    l = br[0], r = br[1];
    while(l <= r){
        if(ar[l] == ar[r]){
            dq.push_back(ar[l]);
            l++, r--;
        }
        else {
            ok = false;
            break;
        }
    }    

    l = br[0], r = br[1];
    while(l >= 0 && r < 2 * n && ar[l] == ar[r]){
        dq.push_back(ar[l]);
        l--, r++;
    }
    if(ok)
        ans = max(ans, get_mex(dq));

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

