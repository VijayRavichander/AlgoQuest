// There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
// For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].

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


// Function to perform modular multiplication
long long mod_mul(long long a, long long b, long long mod) {
    return (a * b) % mod;
}

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp /= 2;
    }
    return result;
}

void precompute_factorials(int maxN, vector<long long>& fact, vector<long long>& ifact) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        fact[i] = mod_mul(fact[i - 1], i, MOD);
    }
    ifact[maxN] = mod_exp(fact[maxN], MOD - 2, MOD); // Inverse of fact[maxN] mod MOD
    for (int i = maxN - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, MOD);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;

    ll p = 1e7;
    vector<long long> fact(p), ifact(p);
    precompute_factorials(p, fact, ifact);

    ll ans;
    ans = mod_mul(fact[m + n - 1], ifact[n - 1], MOD);
    ans = mod_mul(ans, ifact[m], MOD);

    cout<<ans<<"\n";
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