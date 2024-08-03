#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int x, y;
        // second player turns in common
        x = c / 2;

        // first player turns in common
        y = abs(c - x);

        if(a+y > b + x){
            cout<<"First"<<endl;
        }else{
            cout<<"Second"<<endl;
        }
    }

    return 0;
}