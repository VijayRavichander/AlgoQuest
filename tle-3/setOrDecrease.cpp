// https://codeforces.com/problemset/problem/1622/C
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



bool possible(ll operations, vector<ll>& nums, ll n, ll rSum, ll cSum){

    if(cSum - operations <= rSum) return true;

    for(ll i = n - 1; i >= max(1ll, (ll)n - operations); i--){

        cSum -= nums[i];
        ll operationsLeft = operations - (n - i);
        ll tempSum = cSum - nums[0]  + (n - i + 1) * (nums[0] - operationsLeft);

        if(tempSum <= rSum) return true;
    }

    return false;
}



void solve(){
    ll n; cin>>n;
    ll k; cin>>k;
    vector<ll> nums(n);
    ll sum = 0;

    for(auto &it: nums) cin>>it;

    sort(nums.begin(), nums.end());
    sum = accumulate(nums.begin(), nums.end(), 0ll);
    debug(sum);
    ll low = 0, high = 1e15, mid, ans;

    while(low <= high){
        mid = (high + low) / 2;

        if(possible(mid, nums, n, k, sum)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1; 
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