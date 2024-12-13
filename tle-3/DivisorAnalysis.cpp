// https://codeforces.com/contest/2007/problem/A
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


ll expo(ll base, ll pow){
    ll ans = 1;
    while(pow){
        if(pow & 1) ans = ans * base % MOD;
        base = base * base % MOD;
        pow >>= 1;
    }

    return ans;
}

void solve(){
    ll n; cin >> n;
    vector<ll> p(n), k(n);
    for(ll i = 0; i < n; i++) cin >> p[i] >> k[i];
    ll div_cnt = 1, div_sum = 1, div_prod = 1, div_cnt2 = 1;
    for(ll i = 0; i < n; i++){
        div_cnt = div_cnt * (k[i] + 1) % MOD;

        div_sum = div_sum * (expo(p[i], k[i] + 1) - 1) % MOD * expo(p[i] - 1, MOD - 2) % MOD;

        div_prod = expo(div_prod, k[i] + 1) * (expo(expo(p[i], (k[i] * (k[i] + 1)) / 2), div_cnt2)) % MOD;

        div_cnt2 = div_cnt2 * (k[i] + 1) % (MOD - 1);

    }

    cout << div_cnt << " " << div_sum << " " << div_prod << nline;

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