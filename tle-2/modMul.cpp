#include<iostream>
using namespace std;

#define ll long long
#define mod (ll)(1e9+7)

ll helper(ll a, ll b){
	if(b == 0) return 1;
	if(b == 1) return a;
	
	ll res = helper(a, b/2);
	res *= res;
	res %= mod;
	if(b&1){
	res *= a;
	res %= mod;
	}
	
	return res;
}

ll gcd(ll a, ll b){
	if(a > b) return gcd(b, a);
	
	if(a == 0) return b;
	
	return gcd(b % a, a);
}

ll lcm(vector<int> nums){
	ll temp = nums[0];
	for(int i = 1; i < nums.size(); i++){
		temp = (temp * nums[i]) / gcd(temp, nums[i]);
	}
	return temp;
}


int main(){
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	for(auto &it: arr) cin>>it;
	cout<<lcm(arr);
    return 0;
}