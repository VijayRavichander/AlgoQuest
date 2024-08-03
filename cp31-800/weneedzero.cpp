#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

int main() {
    int t; 
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;
        vector<int> nums(n);
        
        for(int i = 0; i < n; i++) cin>>nums[i];

        int xor_sum = accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        if(n % 2 == 1){
            cout<<xor_sum<<endl;
        }else{
            if (xor_sum == 0) cout<<"0"<<endl;
            else cout<<"-1"<<endl;
        }
    }
    return 0;
}