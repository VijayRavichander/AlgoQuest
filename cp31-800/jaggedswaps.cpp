#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        vector<int> nums;
        int n, num;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>num;
            nums.emplace_back(num);
    }
        if (nums.front() == 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
