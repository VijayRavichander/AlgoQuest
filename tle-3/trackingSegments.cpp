// https://codeforces.com/problemset/problem/1843/E
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



bool possible(vector<pair<int, int>>& checks, vector<int>& qu, int mid, int n){
    vector<int> state(n);
    vector<int> prefix(n, 0);

    for(int i = 0; i < mid; i++){
        state[qu[i]] = 1;
    }

    prefix[0] = state[0];

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + state[i];
    }

    for(int i = 0; i < checks.size(); i++){
        int l = checks[i].first;
        int r = checks[i].second;
        int numOnes = prefix[r] - (l > 0 ? prefix[l-1] : 0);
        int segmentSize = r - l + 1;
       
        if(numOnes > segmentSize / 2) return true;
    }

    return false;
}


void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> checks(m);
    for(auto &it: checks){
        cin>>it.first>>it.second;
        it.first--;
        it.second--;
    }
    int q; cin>>q;
    vector<int> qu(q);
    for(auto &it: qu){
        cin>>it;
        it--;
    }
    int l = 1, r = q, mid;
    int ans = -1;
    while(l<=r){
        mid = (l + r) / 2;
        if(possible(checks, qu, mid, n)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }   

    cout<<ans<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}