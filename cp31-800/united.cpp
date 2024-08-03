#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NthRoot(int n, int m) {
  // Write your code here.
  vector<int>range;
  for(int i = 1; i <=n; i++){
    range.push_back(i);
  }

  int left = 0, right = m - 1, p, mid;
  while(left < right){
    cout<<left<<" "<<right;
    
    mid = right - left + 1;

    p = pow(range[mid], n);

    if(p == m){
      return mid;
    }

    else if(p < m){
      right = mid - 1;
    }
    
    else{
      left = mid + 1;
    }
  }
  
  return -1;
}

int main() {
    int n, m, x; 
    cin>>n>>m;
    x = NthRoot(n, m);
    cout<<x;

}
// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         vector<int> a, b, c;
//         int n, x, temp; 

//         cin>>n;

//         for(int i = 0; i < n; i++){
//             cin>>x;
//             a.emplace_back(x);
//         }
        
//         sort(a.begin(), a.end());

//         for(int i = 0; i < n; i++){
//             x = a[i];
//             b.emplace_back(x);
//         }

//         int l, r;
//         l = n-2;
//         r = n-1;

//         while(l > - 1){
//             if(b[l] == b[r]){
//                 l--;
//                 r--;
//             }
//             else{
//                 break;
//             }
//         }

//         if(l != -1){
//             for(int i = r; i < n; i++){
//             c.emplace_back(b.back());
//             b.pop_back();
//         }
//         }
//         if(c.size() == 0){
//             cout<<"-1"<<endl;
//         }else{
//             cout<<b.size()<<" "<<c.size()<<endl;
//             for(auto& it: b){
//                 cout<<it<<" ";
                
//             }
//             cout<<endl;
//             for(auto& it: c){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//         }

//     }


//     return 0;
// }