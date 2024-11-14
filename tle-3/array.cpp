#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"

typedef long long ll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

const int N = 2e6;  // Increase N to avoid out-of-bounds access
 
int mod(int a, int m = MOD) {
    return (a % m + m) % m;  
}

template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mod(1LL * i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = mod(1LL * res * base, m);
            base = mod(1LL * base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(1LL * ans * invfact[n - k]);
        ans = mod(1LL * ans * invfact[k]);

        return ans;
    }
};

void solve(){
    int n;
    cin>>n;
    Math<int> m(N);

    ll ans = 0;
    cout << m.choose(3, 1) << nline;  // Debug to confirm working `choose()`

    for(int i = 0; i < n; i++){
        if (i + n - 1 >= N) {  // Ensure within bounds
            cerr << "Index out of bounds for choose(" << i + n - 1 << ", " << i << ")" << nline;
            continue;
        }
        
        ll val = m.choose(i + n - 1, i);
        ans = (ans + 2 * val) % MOD;
    }

    cout << (ans - n + MOD) % MOD << nline;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
