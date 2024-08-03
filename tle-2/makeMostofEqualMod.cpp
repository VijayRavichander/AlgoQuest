// https://codeforces.com/problemset/problem/1909/B
#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it: arr) cin>>it;

    for(int i = 0; i<64; i++){
        bool flag1 = false, flag2 = false;
        for(auto it: arr){
            if(it & 1LL<<i){
                flag1 = true;
            }else{
                flag2 = true;
            }

            if(flag1 && flag2){
                cout<<(1LL<<(i+1))<<endl;
                return;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}




