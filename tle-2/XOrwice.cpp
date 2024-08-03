// https://codeforces.com/problemset/problem/1421/A

#include <iostream>
#include <vector>
using namespace std;

void solve(){
    long long a, b;
    long x = 0;
    cin>>a>>b;

    for(int i = 0; i < 64; i++){

        if((a & 1<<i) && (b & 1<<i)){
            x |= 1<<i;
        }
    }

    cout<<(a ^ x) + (b ^ x)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}