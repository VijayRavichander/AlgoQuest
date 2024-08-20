// https://codeforces.com/problemset/problem/1623/C
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



bool possible(vector<int> heaps, int n, int w){

    vector<int> fuHeaps(n);
    copy(heaps.begin(), heaps.begin() + n, fuHeaps.begin());
    debug(heaps)
    debug(fuHeaps)

    for(int i = n - 1; i > -1; i--){
        if(fuHeaps[i] < w) return false;

        int y = (fuHeaps[i] - w) / 3;
        
        y = min(y, heaps[i]/3);

        fuHeaps[i] -= y * 3;

        if(i >= 2){
            fuHeaps[i-1] += y;
            fuHeaps[i-2] += 2*y;
        }
    }

    return true;
}



void solve(){
    int n;
    cin>>n;
    vector<int> heaps(n);
    for(auto &it: heaps){
        cin>>it;
    }


    int low = 1, high = 1e9;
    int mid, ans;
    while(low <= high){
        mid = (low + high) / 2;

        if(possible(heaps, n, mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
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