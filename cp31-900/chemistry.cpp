#include<iostream>
#include<map>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    map<char, int> m;
    for(auto ch: s){
        m[ch]++;
    }

    int odds = 0;
    for(auto idx: m){
        if(idx.second & 1){
            odds++;
        }
    }

    if(odds - k > 1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}