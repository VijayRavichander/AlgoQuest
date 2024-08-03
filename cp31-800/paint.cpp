#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        int n, x;
        bool flag = false;
        vector<int> nums;
        unordered_map<int, int> ht;
        cin>>n;

        for(int i = 0; i<n; i++){
            cin>>x;
            nums.emplace_back(x);
        }

        
        for(int i = 0; i<n; i++){
            ht[nums[i]]++;

            if(ht.size() > 2){
                flag = true;
                break;
            }
        }

        if(ht.size() == 1){
            flag = false;
        }else if(ht.size() == 2){
            int f1 = begin(ht) -> second;
            if(f1 != n/2 && f1 != (n+1)/ 2){
                flag = true;
            }
        }else{
            flag = true;
        }

        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }

    return 0;
}