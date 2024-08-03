// https://codeforces.com/problemset/problem/1634/B

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    long long n, x, y, x1, odd_nums = 0;
    cin>>n>>x>>y;
    vector<long long> arr(n);

    for(auto &it: arr) {
        cin>>it;
        if(it&1){
            odd_nums++;
        }
    }

    if(!(odd_nums&1)){
        if((x & 1) == (y & 1)){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }else{
        if((x & 1) != (y & 1)){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
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