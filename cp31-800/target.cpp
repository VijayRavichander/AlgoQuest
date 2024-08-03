#include <iostream>
#include <vector>
using namespace std;

int board[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, 
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, 
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}, 
    {1, 2, 3, 4, 5, 5, 4, 3, 2, 1}, 
    {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, 
    {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, 
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int point = 0;
        char x;
        for(int i = 0; i<10; i++){
            for(int j = 0; j < 10; j++){
                cin>>x;
                if (x == 'X'){
                    point += board[i][j];
                }
            }
        }

        cout<<point<<endl;
    }


    return 0;
}