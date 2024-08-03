#include <iostream>
#include <vector>
using namespace std;


int main () {
    int tc; 
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int x, n;
        cin >> n >> x;

        int max_diff = 0, curr_diff = 0, item, last_item = 0;

        for(int idx = 0; idx < n; idx ++){ 
            cin >> item;
            curr_diff = item - last_item;
            max_diff = max(max_diff, curr_diff);
            // cout<< "Item, Curr_Diff, Max_Diff " << item << curr_diff << max_diff<<endl;
            last_item = item;
        }   
            last_item = 2 * (x - item);
            max_diff = max(max_diff, last_item);
            cout<<max_diff<<endl;
    }
    return 0;
}