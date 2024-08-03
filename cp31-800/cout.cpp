#include<iostream>
#include<string>
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;
        string x, s;
        cin>>s>>x;
        int c = 0;

        while(c < 6){

            if(s.find(x) != string::npos){
                break;
            }
            else{
                s.append(s);
                c++;
            }
        }

        if(c >= 6){
            cout<<-1<<endl;
        }
        else{
            cout<<c<<endl;
        }

    }


    return 0;
}