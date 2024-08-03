// https://www.codechef.com/practice/course/number-theory/INTNT01/problems/STRNG

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve(){
    int n, result = 0;
    cin>>n;
    vector<int> arr(n, 0);
    for(auto& it: arr){
        cin>>it;
    }

    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);

    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];

    for(int i = 1; i < n; i++){
        prefix[i] = gcd(prefix[i-1], arr[i]);
    }
    
    for(int i = n-2; i > -1; i--){
        suffix[i] = gcd(suffix[i+1], arr[i]);

    }

    for(int i = 0; i < n; i++){ 

        if(i == 0){
            if(suffix[i+1] > 1) result++;
            continue;
        }
        if(i == n-1){
            if(prefix[i-1] > 1) result++;
            continue;
        }
        if(gcd(prefix[i-1], suffix[i+1]) > 1) result++;
    }
    cout<<result<<endl;
    return; 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}