// https://codeforces.com/problemset/problem/1251/C
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


void solve(){
    ll a, b, c; cin >> a >> b >> c;
    ll m; cin >> m;
    deque<ll> u, p, combined;

    for(int i = 0; i < m; i++){
        ll x; string s; cin >> x >> s;
        if(s == "USB"){
            u.push_back(x);
        }else{
            p.push_back(x);
        }
    }


    sort(u.begin(), u.end());
    sort(p.begin(), p.end());

    ll u_size = u.size();
    ll p_size = p.size();

    vector<ll> ans;

    for(int i = 0; i < a && i < u_size; i++) {
        debug(u[0]);
        ans.push_back(u[0]);
        u.pop_front();
    }

    for(int i = 0; i < b && i < p_size; i++) {
        debug(p[0]);
        ans.push_back(p[0]);
        p.pop_front();
    }

    for(auto it: u){
        combined.push_back(it);
    }

    for(auto it: p){
        combined.push_back(it);
    }

    sort(combined.begin(), combined.end());

    ll c_size = combined.size();

    for(int i = 0; i < c && i < c_size; i++){
        ans.push_back(combined[0]);
        combined.pop_front();
    }
    ll sum = 0;

    debug(ans);
    for(auto it: ans) sum += it;

    cout << ans.size() << " " << sum << nline;

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