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
    vector<int>ar(n), br(n);
    int c = 0;
    for(int i = 0;i <n; i++){
        cin>> ar[i];
        c ^= ar[i];
    }
    for(int i= 0; i < n; i++){
        cin >> br[i];
        c ^= br[i];
    }
    if(c == 0){
        cout << "tie" << ln;
        return;
    }
    for(int k = 20; k >= 0; k--){
        if((c>> k & 1)){
            for(int i = n- 1; i >= 0; i--){
                if((ar[i] ^ br[i]) >> k & 1){
                    if(i % 2 == 0){
                        cout << "Ajisai" << ln;
                    }
                    else cout << "Mai" << ln;
                    return;
                }
            }
        }
    }
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

