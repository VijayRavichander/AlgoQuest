// https://codeforces.com/problemset/problem/1381/A2
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


const ll N = 1e7 + 1;
ll spf[N];

void sieve(){
    for(ll i = 1; i < N; i++) spf[i] = i;

    for(ll i = 2; i < N; i++){
        if(spf[i] == i){
            for(ll j = i * i; j < N; j+=i) if(spf[j] == j) spf[j] = i;
        }
    }
}


void solve(){
    ll n, m; cin >> n >> m;

    map<ll, ll> p1, p2, p3;
    vector<ll> a, b;
    sieve();

    for(ll i = 0; i < n; i++){
        ll x; cin>>x; a.push_back(x);
        while(x > 1){
            ll p = spf[x], cnt = 0;
            while(x % p == 0) cnt++, x/= p;
            p1[p] += cnt;
        }
    }

    for(ll j = 0; j < m; j++){
        ll y; cin>>y; b.push_back(y);
        while(y > 1){
            ll q = spf[y], cnt2 = 0;
            while (y % q == 0) cnt2++, y/= q;
            p2[q] += cnt2;
        }
    }
    
    for(auto &i: p1){
        p3[i.first] = min(p1[i.first], p2[i.first]);
    }

    p1 = p2 = p3;

    for(ll i = 0; i < n; i++){
        ll x = a[i];
        while(x > 1){
            ll p = spf[x], cnt = 0;
            while(x % p == 0) cnt++, x/= p;
            cnt = min(p1[p], cnt);
            p1[p] -= cnt;
            while(cnt--) a[i] /= p;
        }
    }

    for(ll i = 0; i < m; i++){
        ll x = b[i];
        while(x > 1){
            ll p = spf[x], cnt = 0;
            while(x % p == 0) cnt++, x/= p;
            cnt = min(cnt, p2[p]);
            p2[p] -= cnt;
            while(cnt--) b[i] /= p;
        }
    }

    cout << n << " " << m << nline;
    for(auto &it: a) cout << it << " ";
    cout << nline;
    for(auto &it: b) cout << it << " ";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

    ll t = 1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}