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

int mul(int x, int y) {
    return (x * 1LL * y) % MOD;
}
int power(int x, int y){
    int ans = 1;
    while(y > 0){
        if(y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y = y >> 1;
    }
    return ans;
}
int divide(int x, int y){
    return mul(x, power(y, (MOD - 2)));
}
void solve(){
   int n; cin>>n;
   int m; cin>>m;
   vector<int> nums(n);
   set<int> s;
   unordered_map<int, int> hm;
   for(auto &it: nums){
        cin>>it;
        s.insert(it);
        hm[it]++;
   }

   vector<int> distinct(s.begin(), s.end());
   int p = 0, prod = 1, ans = 0;

   for(int i = 0; i < distinct.size(); i++){
        while(p < distinct.size() && distinct[p] - distinct[i] < m){
            prod = (prod * 1LL * hm[distinct[p]]) % MOD;
            p++;
        }
        if(p - i == m){
            ans = (ans + prod) % MOD;
        }

        prod = divide(prod, hm[distinct[i]]);
   }

   cout<<ans<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}