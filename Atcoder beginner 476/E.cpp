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
 
struct SegmentTree { 
    struct Node { 
        ll mn, mx; 
    }; 
 
    int n; 
    vector<Node> tree; 
 
    SegmentTree(vector<ll>& a) { 
        n = a.size(); 
        tree.resize(4 * n); 
        build(1, 0, n - 1, a); 
    } 
 
    void build(int node, int l, int r, vector<ll>& a) { 
        if (l == r) { 
            tree[node] = {a[l], a[l]}; 
            return; 
        } 
 
        int mid = (l + r) / 2; 
 
        build(node * 2, l, mid, a); 
        build(node * 2 + 1, mid + 1, r, a); 
 
        tree[node].mn = min(tree[node * 2].mn, tree[node * 2 + 1].mn); 
        tree[node].mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx); 
    } 
 
    void update(int node, int l, int r, int pos, ll val) { 
        if (l == r) { 
            tree[node] = {val, val}; 
            return; 
        } 
 
        int mid = (l + r) / 2; 
 
        if (pos <= mid) 
            update(node * 2, l, mid, pos, val); 
        else 
            update(node * 2 + 1, mid + 1, r, pos, val); 
 
        tree[node].mn = min(tree[node * 2].mn, tree[node * 2 + 1].mn); 
        tree[node].mx = max(tree[node * 2].mx, tree[node * 2 + 1].mx); 
    } 
 
    Node query(int node, int l, int r, int ql, int qr) { 
        if (qr < l || r < ql) 
            return {LLONG_MAX, LLONG_MIN}; 
 
        if (ql <= l && r <= qr) 
            return tree[node]; 
 
        int mid = (l + r) / 2; 
 
        Node left = query(node * 2, l, mid, ql, qr); 
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr); 
 
        return { 
            min(left.mn, right.mn), 
            max(left.mx, right.mx) 
        }; 
    } 
 
    void update(int pos, ll val) { 
        update(1, 0, n - 1, pos, val); 
    } 
 
    Node query(int l, int r) { 
        return query(1, 0, n - 1, l, r); 
    } 
}; 

void solve() { 
    int n, m; 
    cin >> n >> m; 

    vector<ll> ar(n); 
    vector<int> idx(n + 2); 

    for(int i = 0; i < n; i++) { 
        cin >> ar[i]; 
        idx[ar[i]] = i; 
    } 
 
    SegmentTree st(ar); 

    while(m--) { 
        int l, r; 
        cin >> l >> r; 
        l--, r--; 
 
        auto [x, y] = st.query(l, r); 

        int ix = idx[x]; 
        int iy = idx[y];

        st.update(ix, y);
        st.update(iy, x);

        idx[x] = iy;
        idx[y] = ix;
    } 

    vector<int>ans(n + 1);
    for(int i = 1; i <= n; i++){
    	ans[idx[i]] = i;
    }

    for(int i = 0; i < n; i++){
    	cout << ans[i] << " ";
    }
    
} 
 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int t = 1; 
    // cin >> t; 
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