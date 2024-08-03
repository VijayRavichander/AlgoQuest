#include<iostream>
using namespace std;

int main(){
    int t; 
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;
        
        if(n % 2 == 1){
            int l = 0, r = n - 1;
            while(l < r && s[l] != s[r]){
                l++;
                r--;
            }
            if (l == r) cout<<"1"<<endl;
            else cout<<r-l+1<<endl;

        }else{
            int l = 0;
            int r = n - 1;
            while(l < r && s[l] != s[r]) {
                l++;
                r--;
            }

            if (l == r) cout<<"0"<<endl;
            else cout<<r-l+1<<endl;
        }
        
    }
}