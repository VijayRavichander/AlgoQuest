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



bool possible(ll totalTickets, vector<ll>& tickets, ll x, ll a, ll y, ll b, ll k){


    ll both, first, second;
    ll lcm = a / gcd(a, b) * b;
    ll sum = 0;
    ll itr = 0;


    both = totalTickets / lcm;
    first = (totalTickets / a) - totalTickets / lcm;
    second = (totalTickets / b) - totalTickets / lcm;


    while(both--) sum += tickets[itr++] / 100 * (x + y);
    while(first--) sum += tickets[itr++] / 100 * (x);
    while(second--) sum += tickets[itr++] / 100 * (y);

    
    return sum >= k;

}
void solve(){
    ll n;
    cin>>n;

    vector<ll> tickets(n);
    for(auto &it: tickets){
        cin>>it;
    }

    sort(tickets.begin(), tickets.end(), greater());
    
    ll x, a, y, b, k;

    cin>>x>>a;
    cin>>y>>b;
    cin>>k;

    if(x < y) swap(x, y), swap(a, b);


    ll low = 1, high = n;
    ll mid, ans = -1;


    while(low <= high){
        mid = (low + high) / 2;
        debug(mid);
        if(possible(mid, tickets, x, a, y, b, k)){
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

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}