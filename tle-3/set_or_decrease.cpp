#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>
bool check(int mid,vector<int> &arr, long long sum, int maxSum)
{
    if(sum - mid <= maxSum) return true;

    // sum-=arr[0];
    // if(( sum + (arr[0] - mid)) <= maxSum ) return true;

    for(int i=arr.size()-1;i>=max(1ll, (long long)arr.size()-mid);i--)
    {
        sum-=arr[i];    
        long long new_sum=sum - arr[0]+ (arr.size() - i + 1) * (arr[0] - (mid- (arr.size() - i)))        ;
        if(new_sum<=maxSum)
            return true;
    }
    return false;
}
void solve(int n, int k)
{
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;

    sort(arr.begin(),arr.end());
    long long sum=accumulate(arr.begin(),arr.end(), 0ll);
    int s=0, e=1e9, ans=1e9;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(check(mid, arr, sum,k))
        {
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        solve(n,k);

    }
    return 0;
}