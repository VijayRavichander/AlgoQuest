#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        unordered_map<int, int> ht;
        vector<int> arr;
        int n, k, tmp;
        bool flag = false;
        cin>>n>>k;

        for(int i = 0; i < n; i++){
            cin>>tmp;
            if(tmp == k) flag = true;
            arr.emplace_back(tmp);
        } 

        // int max = 0;
        // for(auto itr: arr) {
        //    ht[itr]++;

        //    if(ht[itr] > max){
        //     max = ht[itr];
            
        //     if(itr == k){
        //         flag = true;
        //         break;
        //     }
        //    }

        // }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }







    return 0;
}