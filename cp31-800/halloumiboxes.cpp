#include <iostream>
#include <vector>
using namespace std;


int main() {
    int tc; 
    cin >> tc;
    vector<int> tmp;

    for(int i = 0; i < tc; i++){
        int n, k, flag = false;
        cin >> n >> k;
        int num;
        for(int idx = 0; idx < n; idx++){
            cin >> num;
            if((tmp.size() > 0) && (k == 1) && (tmp.back() > num)){
                flag = true;
            }
            tmp.emplace_back(num);
        }
        tmp.clear();
        if(flag){
            cout << "NO" <<endl;
        }else{
            cout << "YES" <<endl;
        }
    }
    return 0;
}