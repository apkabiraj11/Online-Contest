#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ln '\n'
#define yes cout << "YES" << ln
#define no cout << "NO" << ln
const int N = 1e6 + 9, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int>ar(n);
    for(int i = 0; i < n;i++)
        cin >> ar[i];
    vector<int>mn(n), mx(n);
    mn[0] = ar[0];
    for(int i = 1; i < n; i++){
        mn[i] = min(mn[i-1], ar[i]);
    }
    mx[n - 1] = ar[n - 1];
    for(int i = n - 2; i >= 0; i--){
        mx[i] = max(mx[i + 1], ar[i]);
    }
    for(int i = 1; i < n; i++){
        if(mn[i - 1] > mx[i]){
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
    //int casee = 1;
    while(t--) {
        //cout<<"Case "<<casee<<": ";

        solve();

        // casee++;
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT 

***************/

