#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

int main() {
    int n, item, min = INT_MAX;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>item;
        if(min > abs(item)){
            min = abs(item);
        }
    }

    cout<<min<<endl;
    return 0;
}