// A. Unit Array

#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int, int> count;
        int n, temp, res = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>temp;
            count[temp]++;
        }

        if(count[1] >= count[-1] && count[-1] % 2 == 0){
            cout<<0<<endl;
        }else{
            while(count[1] < count[-1]){
                res++;
                count[-1]--;
                count[1]++;
            }

            if(count[-1] % 2 == 0){
                cout<<res<<endl;
            }else{
                cout<<res + 1<<endl;
            }
        }
    }

    return 0;
}