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

const int N = 200001;
int spf[N];

void sieve(){

    for(int i = i; i < N; i++) spf[i] = i;

    for(int i = 2; i < N; i++){
        for(int j = i * 2; j < N; j+=i){
            if(spf[j] == j) spf[j] = i;
        }
    }
}

void solve(){
    sieve();

    ll n; cin >> n;
    vector<int> a(n), primes[N];
    ll LCM = 1;

    for(auto &it: a){
        cin >> it;
    }

    for(auto i: a){
        while(i != 1){
            int p = spf[i], count = 0;
            while(i % p == 0){
                i /= p, count++;
            }
            primes[p].push_back(count);
        }
    }

    for(int i = 0; i < N; i++){
        sort(primes[i].begin(), primes[i].end());
        if(primes[i].size() < n - 1) continue;
        else{
            if(primes[i].size() == n){
                LCM *= pow(i, primes[i][1]);
            }else{
                LCM *= pow(i, primes[i][0]);
            }
        }
    }

    cout << LCM << nline;



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