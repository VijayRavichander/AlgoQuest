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
    ll n, m; cin >> n >> m;
    vector<ll> nums(n); for(auto &it: nums) cin>> it;

    vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));

    // Base Case
    for(ll k = 1; k <= m; k++){
        if(nums[0] == 0 || nums[0] == k){
            dp[1][k] = 1;
        }
    }

    for(ll i = 2; i <= n; i++){
        if(nums[i-1] != 0){
            dp[i][nums[i-1]] = (((dp[i-1][nums[i-1]-1] + dp[i-1][nums[i-1]]) % MOD) + dp[i-1][nums[i-1]+1]) % MOD;
        }else{
            for(ll k = 1; k <= m; k++){
            dp[i][k] = (((dp[i-1][k-1] + dp[i-1][k]) % MOD) + dp[i-1][k+1]) % MOD;
        }
        }

    }

    ll result = 0;

    for(int i = 0; i < m+1; i++) result = (result +  dp[n][i]) % MOD;

    cout << result << nline;

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