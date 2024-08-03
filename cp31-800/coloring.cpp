#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int n, x,res = 0;
        cin>>n;
        for(int i = 0; i<n; i++){
            cin>>x;
            if(x%2 == 1)
                res++;
        }

        if(res % 2 == 0 && n > 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}