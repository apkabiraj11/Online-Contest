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
    int x, y;
    cin >> x >> y;

    int s = x + y;
    int a = 0;

    for(int i = 28; i >= 0; i--) {
        if((x >> i & 1) && !(s >> i & 1)) {
            a = x >> (i + 1) << (i + 1);
            a |= s & ((1 << i) - 1);
            break;
        }
    }

    if((x & ~s) == 0)
        a = x;

    cout << s << " " << x - a << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

/**************

LEARNING IS FUN
SO ENJOY IT

***************/