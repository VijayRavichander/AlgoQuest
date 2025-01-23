#include<bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Function to calculate x^y % mod
long long modExp(long long x, long long y, long long mod) {
    long long result = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) {
            result = (result * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return result;
}

// Function to calculate modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long mod) {
    return modExp(a, mod - 2, mod);
}

// Function to calculate nCr % mod
long long nCrMod(long long n, long long r, long long mod) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    // Precompute factorials and modular inverses
    long long fact[n + 1];
    fact[0] = 1;
    for (long long i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    // nCr = n! / (r! * (n-r)!) % mod
    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % mod;
    return (numerator * modInverse(denominator, mod)) % mod;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans; 
    ans = modExp(2,m, MOD);
    ans--;
    ans = modExp(ans, n, MOD);
    cout << ans << nline;


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