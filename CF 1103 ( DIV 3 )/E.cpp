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
    for(int i= 0; i < n; i++) cin >> ar[i];
    if(n == 1){
        cout << 0 << ln;
        return;
    }

    auto check = [&](int mid){
        if (mid == 0) 
        	return true;
        auto valid = [&](multiset<int> &st) {
            vector<int> v(st.begin(), st.end());
            for (int i = 1; i < (int)v.size(); i++) {
                if (v[i] - v[i - 1] != 1) 
                    return false;
            }
            return true;
        };

        multiset<int> st1;
        for (int i = 0; i < mid; i++) {
            st1.insert(ar[i]);
        }
        for (int i = 0; i + mid <= n; i++) {
            if (i > 0) {
                st1.erase(st1.find(ar[i - 1])); 
                st1.insert(ar[i + mid - 1]);   
            }
            if (!valid(st1)) 
            	continue;
            
            multiset<int> st2;
            int start = i + mid;
            if (start + mid > n) 
                continue;
            for (int j = start; j < start + mid; j++) {
                st2.insert(ar[j]);
            }
            for (int j = start; j + mid <= n; j++) {
                if (j > start) {
                    st2.erase(st2.find(ar[j - 1]));     
                    st2.insert(ar[j + mid - 1]);     
                }
                if (!valid(st2)) 
                    continue;
                vector<int> a(st1.begin(), st1.end());
                vector<int> b(st2.begin(), st2.end());
           
                if (a.back() + 1 == b.front() || b.back() + 1 == a.front()) {
                    return true;
                }
            }
        }
        return false;
    };

    int ans = 0;
    for(int k = 0; k * 2 <= n; k++){
        if(check(k)) ans = k;
    }
    cout << ans << ln;
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