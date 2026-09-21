#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using LL = long long;
using PLL = pair<LL, LL>;

#define faster {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ordered_set tree<LL, null_type,less<LL>, rb_tree_tag,tree_order_statistics_node_update>
#define all(v) v.begin(), v.end()

const LL mod = 998244353;
const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const LL INF = 1e18 + 10;

void pre() {
    
}

void solve (int tc) {
	LL n, m, k; cin >> n >> m >> k;
	LL x, y; cin >> x >> y;
	vector<LL> a(n), b(m);
	for(auto &u: a)
		cin >> u;
	for(auto &u: b)
		cin >> u;
	sort(all(a));
	sort(all(b));
	for(int i = 1; i < n; i++){
		a[i] += a[i - 1];
	}
	auto get = [&](LL rem){
		int it = upper_bound(all(a), rem) - a.begin();
		return it;
	};
	int ans = get(x + y * k);
	for(int i = 0; i < m; i++){
		int need = (b[i] + k - 1) / k;
		if(need > y) break;
		y -= need;
		x += (k - b[i] % k) % k;
		ans = max(ans, i + 1 + get(x + y * k));
	}
	cout << ans << '\n';
}

signed main() {
    faster
    pre();
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
    return signed{};
}

/*
 
 * WRITE STUFFS DOWN
 * DON'T GET STUCK ON ONE APPROACH
 
*/