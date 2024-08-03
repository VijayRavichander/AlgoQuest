#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        long long int a, b, c, d, x, y, count = 0;
        cin>>a>>b>>c>>d;
        if (d < b)
        cout<<-1<<endl;
        else{
            if( (a + d - b) < c) cout<<-1<<endl;
            else cout<<(2 * (d - b) + a - c)<<endl;
        }

    }


    return 0;
}