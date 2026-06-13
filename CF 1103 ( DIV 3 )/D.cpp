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
    vector<int>ar(n);
    vector<int> freq(n + 1);
    for(int i = 0; i < n; i++)
    	cin >> ar[i], freq[ar[i]]++;


    if(n == 1){
    	no;
    	return;
    }

    sort(ar.begin(),ar.end());

    int last = ar[n - 1];
    vector<int>blocks(n + 2);
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
    	if(last - k <= ar[i]){
    		cnt++;
    		blocks[i] = cnt;
    		last = ar[i];
    	}
    	else {
    		cnt = 1;
    		last = ar[i];
    		blocks[i] = cnt;
    	}
    }
   	for(int i = n - 2; i >= 0; i--){
   		if(ar[i] != ar[i + 1]){
   			if(blocks[i + 1] % 2 == 0){
   				yes;
   				return;
   			}
   		}
   		if(ar[i + 1] - k > ar[i]){
   			if(blocks[i + 1] % 2 == 0){
   				yes;
   				return;
   			}
   		}
   		else {
   			if(ar[i + 1] != ar[i] && blocks[i + 1] % 2){
   				yes;
   				return;
   			}
   		}
   	}
   	if(freq[ar.front()] % 2 == 0){
   		yes;
   		return;
   	}
   	no;

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

