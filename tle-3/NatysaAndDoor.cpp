// https://codeforces.com/contest/1341/problem/B
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
    int n; cin>>n;
    int k; cin>>k;

    vector<int> m(n);
    queue<int> q;

    for(auto &it: m) cin>>it;

    int maxPeaks = 0;
    int minL = 0;


    int L = 0; 
    int R = k-1;


    for(int i = L; i <= R; i++){
        if(i > L && i < R && m[i] > m[i-1] && m[i] > m[i+1]){
            q.push(i);
        }
    }

    if(maxPeaks < q.size()){
        minL = L;
        maxPeaks = q.size();
    }


    while(R < n){

        // Add new element to the Window
        if(R+1 < n && m[R] > m[R-1] && m[R] > m[R+1]){
            q.push(R);
        }

        // Move the Sliding Window
        L++;
        R++;

        // Remove Out of Window Elements
        if(!q.empty() && q.front() <= L){
            q.pop();
        }  

        // Check the current state to be most optimal state ? 
        if(maxPeaks < q.size()){
            minL = L;
            maxPeaks = q.size();
        }
        
            

    }

    cout<<maxPeaks+1<<" "<<minL+1<<endl;

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