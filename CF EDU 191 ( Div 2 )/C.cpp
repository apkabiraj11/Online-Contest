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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cost = mod;
    string res;
    for(int i = 0; i <= k; i++){

        int left = i, right = k - i;

        string ans(n, '0');  
        for(int j = 0; j < n; j++){
            if(s[j] == '(' && left){
                ans[j] = '1';
                left--;
            }
        }
        for(int j = n - 1; j >= 0; j--){
            if(s[j] == ')' && right){
                ans[j] = '1';
                right--;
            }
        }

        
        
         int cur = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            if(ans[i] == '1') continue;
            if(s[i] == '(') cur++;
            else if(cur) cur--, cnt++;
        }
        cnt *= 2;
        if(cnt < cost) res = ans, cost = cnt;
    }
    cout << res << ln;
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

