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
  int n; cin>>n;
  int m; cin>>m;
  vector<int> r(n);
  for(auto &it: r) cin>>it;
  vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
  dp[0][0] = 0;
  vector<int> v1, v2;
  int tot = 0;
  for(int i = 0; i < n; i++){
    if(r[i] < 0){
        v2.push_back(-1 * r[i]);
    }
    else if(r[i] > 0){
        v1.push_back(r[i]);
    }else{
        tot++;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for(int j = 0; j < tot + 1; j++){

            if(j != 0){
                int c1 = j - 1, c2 = tot - j;
                int val = (upper_bound(all(v1), c1) - v1.begin()) + 
                          (upper_bound(all(v2), c2) - v2.begin());
                
                // Choosing Intel
                dp[tot][j] = max(dp[tot][j], dp[tot-1][j-1] + val);
            }
            if(j < tot){
                int c1 = j, c2 = tot - j - 1;
                int val = (upper_bound(all(v1), c1) - v1.begin()) +
                          (upper_bound(all(v2), c2) - v2.begin());

                // Choosing Strength
                dp[tot][j] = max(dp[tot][j], dp[tot-1][j] + val);
            }
        }

        v1.clear();
        v2.clear();
    }
  }

  sort(all(v1));
  sort(all(v2));

  int ans = 0;
  
  for(int j = 0; j < m + 1; j++){
    int c1 = j; int c2 = m - j;
    int val = (upper_bound(all(v1), c1) - v1.begin()) + 
              (upper_bound(all(v2), c2) - v2.begin());
    ans = max(ans, dp[m][j] + val);
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