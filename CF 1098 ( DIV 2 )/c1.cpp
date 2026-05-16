#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln '\n'

ll a, n;
vector<int> ar(2);
ll ans;

void fun(ll b, int sz) {

    if (sz > 18) return;

    if (sz > 0) {
        ans = min(ans, llabs(a - b));
    }
    fun(b * 10 + ar[0], sz + 1);
    fun(b * 10 + ar[1], sz + 1);
}

void solve() {
    cin >> a >> n;

    for (int i = 0; i < 2; i++) {
        cin >> ar[i];
    }

    ans = 1e18;

    fun(0, 0);

    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}