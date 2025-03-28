// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
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
template <class T> void _print(queue<T> v) { cerr << "[ "; queue<T> copy = v; while (!copy.empty()) { _print(copy.front()); cerr << " "; copy.pop(); } cerr << "]"; }

void solve(){
    ll n, m;
    cin>>n>>m;
    vector<ll> num1(n);
    vector<ll> num2(m);
    for(auto &it: num1) cin>>it;
    for(auto &it: num2) cin>>it;

    ll ans = 0;
    ll p1 = 0, p2 = 0;

    while(p1 < n && p2 < m){
        
        if(num1[p1] > num2[p2]){
            p2++;
        }
        else if(num1[p1] < num2[p2]){
            p1++;
        }else{
            ll temp = num1[p1];
            ll c1 = 0, c2 = 0;

            while(num1[p1] == temp && p1 < n){
                c1++;
                p1++;
            }
            while(num2[p2] == temp && p2 < m){
                c2++;
                p2++;
            }

            ans += c1 * c2;
        }
    }

    cout<<ans<<endl;

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