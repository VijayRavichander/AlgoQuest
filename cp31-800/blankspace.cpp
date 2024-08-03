#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; 
    cin>>t;
    while(t--){
        int n, x, maxres = 0, res = 0;
        cin>>n;
        vector<int> nums;
        for(int i = 0; i < n; i++){
            cin>>x;
            nums.push_back(x);
            if(x == 0){
                res++;
                maxres = max(res, maxres);
            }else{
                res = 0;
            }
        }
        cout<<maxres<<endl;
    }

    return 0;
}