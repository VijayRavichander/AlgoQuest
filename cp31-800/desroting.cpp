#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int main(){
    int t; 
    cin>>t;
    while(t--){
       int n, x;
       bool flag = false; 
       cin>>n;
       vector<int>nums;
       
       for(int i = 0; i<n; i++){
            cin>>x;
            nums.emplace_back(x);
       }
       int diff = INT_MAX, res;
       for(int i = 1; i<n; i++){
            if(nums[i-1] <= nums[i]){
                diff = min(diff, nums[i] - nums[i-1]);
            }else{
                flag = true;
                break;
            }
       }

       if(flag){
        cout<<"0"<<endl;
       }else{
        res = diff/2 + 1;
        cout<<res<<endl;
       }

    }
    return 0;
}