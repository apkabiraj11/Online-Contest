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
 
    ll n; 
    cin >> n; 
    vector<ll>ar(n); 
    for(ll i = 0; i < n; i++){ 
        cin >> ar[i]; 
    } 
    sort(ar.begin(),ar.end()); 
    vector<vector<ll>>br(n + 2, vector<ll>(101, 0)); 
   
 
    for(ll i = 0; i < n; i++){ 
        ll x = ar[i]; 
        ll cnt = 0; 
        while(cnt <= 100){ 
 
            br[i][cnt] = x; 
 
            ll temp = 0; 
            while(x){ 
                ll d = x % 10; 
                temp += (d * d); 
                x /= 10; 
            } 
            x = temp; 
            cnt++; 
        } 
    } 

    ll ans = 0; 

    for(ll i = 0; i <= 100; i++){ 
        map<ll, ll> mp; 

        for(ll j = 0; j < n; j++){ 
            mp[br[j][i]]++; 
        } 

        ll cur = 0;

        for(auto [x, y] : mp){ 
            ll pair = 1LL * y * (y - 1) / 2; 
            cur += pair; 
        } 

        ans = max(ans, cur); 
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
 
***************/ 