#include <iostream>
#include <vector>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n, item, min, prev;
        vector<int> arr;
        vector<int> res;
        cin>>n;

        for(int i = 0; i < n; i++){
            cin>>item;
            arr.emplace_back(item);
            
            if(i == 0){
                min = item;
            }else{
                prev = arr[i-1];
                if(item < prev){
                    res.emplace_back(item);
                }

            }

            res.emplace_back(item);
        }
        
        cout<<res.size()<<endl;
        for(auto it: res){
            cout<<it<<" ";
        }
        cout<<endl;
    }


    return 0;
}