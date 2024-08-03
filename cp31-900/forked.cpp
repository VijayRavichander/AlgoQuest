#include <iostream>
#include <set>
#include <utility> 
using namespace std;


int main() {
    int t; 
    cin>>t;
    while(t--){
        int a, b, kx, ky, qx, qy, result = 0;
        cin>>a>>b;
        cin>>kx>>ky;
        cin>>qx>>qy;

        set<pair<int, int>> plays = {
            {a, b}, {-a, b}, {a, -b}, {-a, -b},
            {b, a}, {-b, a}, {b, -a}, {-b, -a} 
        };

        set<pair<int, int>> positions;

        for(auto itr = plays.begin(); itr != plays.end(); itr++){
            int px = kx + itr->first;
            int py = ky + itr->second;
            positions.insert({px, py});
        }

        for(auto itr = positions.begin(); itr != positions.end(); itr++){
            for(auto it = plays.begin(); it != plays.end(); it++){
                int rx = itr->first + it->first;
                int ry = itr->second + it->second;

                if(rx == qx && ry == qy){
                    result++;
                }
            }
        }

        cout<<result<<endl;

    }
    return 0; 
}