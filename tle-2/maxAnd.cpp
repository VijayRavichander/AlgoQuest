#include <iostream>
#include <vector>
using namespace std;


class comp{
    public: 
        bool operator()(pair<long long, long long>& p1, pair<long long, long long>& p2){
            if(p1.first != p2.first){
                return p1.first > p2.first;
            }else{
                return p1.second < p2.second;
            }
        }
};

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int> arr(n);
    vector<pair<long long, long long> > hm;

    for(auto &it: arr)cin>>it;

    for(int i = 30; i>=0; i--){
        long long cnt = 0;
        for(auto it: arr){
            if(it & (1 << i)){
                cnt++;
            }
        }

        hm.push_back({(1<<i) * cnt, i});
    }
    sort(hm.begin(), hm.end(), comp());

    long long x = 0;
    for(int i = 0; i < k; i++){
        int t = hm[i].second;
        x |= 1<<t;
    }

    cout<<x<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}