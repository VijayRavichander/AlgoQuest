// https://codeforces.com/edu/course/2/lesson/6/4/practice/contest/285069/problem/A
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



pair<int, int> anySubArraywithPositiveSum(vector<lld> nums, int d, int n){
    vector<lld> preFix(n);
    preFix[0] = nums[0];

    for(int i = 1; i < n; i++){
        preFix[i] = preFix[i-1] + nums[i];
    }

    lld minValue = 0;
    lld ans = -1e18;
    lld subArraySum;
    int minValueIdx = -1;
    for(int i = d-1; i < n; i++){
        subArraySum = preFix[i] - minValue;
        ans = max(ans, subArraySum);

        if(ans >= 0){
            return make_pair(minValueIdx + 1, i);
        }
        if(minValue > preFix[i - d + 1]){
            minValue = preFix[i - d + 1];
            minValueIdx = i - d + 1;
        }
    }

    return {-10, -10};
}

pair<int, int> bestSubArray(lld mean, vector<lld> nums, int n, int d){
    vector<lld> transformed(n);
    for(int i = 0; i < n; i++){
        transformed[i] = nums[i] - mean;
    }

    return anySubArraywithPositiveSum(transformed, d, n);
}   



lld maximumSum(vector<lld> nums, int d, int n){
    vector<lld> preFix(n);
    preFix[0] = nums[0];

    for(int i = 1; i < n; i++){
        preFix[i] = preFix[i-1] + nums[i];
    }

    lld minValue = 0;
    lld ans = -1e18;
    lld subArraySum;
    for(int i = d-1; i < n; i++){
        subArraySum = preFix[i] - minValue;
        minValue = min(minValue, preFix[i - d + 1]);
        ans = max(ans, subArraySum);
    }

    return ans;
}

bool possible(lld mean, vector<lld> nums, int n, int d){
    vector<lld> transformed(n);
    for(int i = 0; i < n; i++){
        transformed[i] = nums[i] - mean;
    }

    return maximumSum(transformed, d, n) >= 0;
}   


void solve(){
    int n, d; 
    cin>>n>>d;
    vector<lld> nums(n);
    for(auto &it: nums) cin>>it;
    pair<int, int> ans;
    lld low = 0, high = 100;
    lld mid;
    for(int iterations = 0; iterations < 100; iterations++){
        mid = (low + high) / 2;
        if(possible(mid, nums, n, d)){
            low = mid;
        }else{
            high = mid;
        }
    }
    // cout<<low<<endl;
    ans = bestSubArray(low, nums, n, d);
    cout << ans.first + 1 <<" "<< ans.second + 1 << endl;
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