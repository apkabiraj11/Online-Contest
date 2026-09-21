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

void solve() {
    int n;
    cin >> n;
    vector<int> ar(2 * n + 2);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> ar[i];
    }

    vector<int> L(2 * n + 2);
   	vector<ll> dp(2 * n + 2);

   	for(int i = 1; i <= 2 * n; i++){
   		dp[i] = dp[i - 1] + 1;

   		if(L[ar[i]] > 0){
   			ll len = i - L[ar[i]] + 1;
			dp[i] = max(dp[i], dp[L[ar[i]] - 1] + len * len);
   		}
   		L[ar[i]] = i;
   	}

   	cout << dp[2 * n] << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT

***************/