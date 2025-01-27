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
    string s; cin >> s;
    ll n; 
    n = s.size();

    sort(s.begin(), s.end());

    vector<char> ans(n);
    int left = 0, right = n - 1;

    for(int i = 0; i < n; i += 2){

        if(i == n - 1){
            ans[left] = s[i];
        }
        else if(s[i] == s[i + 1]){
            ans[left] = s[i]; left++;
            ans[right] = s[i+1]; right--;
        }
        else{
            if(s[i+1] == s[n - 1]){
                int len = n - i - 1;
                int firstHalf = ceil(len/2.0);
                int secondHalf = len - firstHalf;
                // --abbb -> -bbab-
                while(firstHalf--){
                    ans[left] = s[i+1];
                    left++;
                }

                ans[left] = s[i];

                while(secondHalf--){
                    ans[right] = s[i+1];
                    right--;
                }

                break;

            }else{
                for(int j = i + 1; j < n; j++){
                    ans[left] = s[j];
                    left++;
                }
                ans[right] = s[i];
                break;
            }
        }
    }

    string answer = "";
    for(auto it: ans){
        answer += it;
    }

    cout << answer << nline; 


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