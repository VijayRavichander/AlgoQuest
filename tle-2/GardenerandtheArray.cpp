// https://codeforces.com/problemset/problem/1775/B

#include <iostream>
#include <vector>
using namespace std;

void solve(){

    long long n;
    cin>>n;

    vector<int>freq(32);
    vector<vector<int>>v(n, vector<int>());
    for(int i = 0; i < n; i++){
        int c;
        cin>>c;
        for(int j = 0; j < c; j++){
            int a; cin>>a;
            freq[a]++;
            v[i].push_back(a);
        }
    }

    for(int i = 0; i < n; i++){
        int flag = true;
        for(auto it: v[i]){
            if(freq[it] == 1){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}