#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, x;
        vector<int> a;  
        vector<int> b;
        cin>>n;
        
        for(int i = 0; i < n; i++){
            cin>>x;
            a.push_back(x);
            b.push_back(n+1-x);
        }

        for(int i = 0; i < n; i++) cout<<b[i]<<" ";
        cout<<endl;
    }

    return 0;
}