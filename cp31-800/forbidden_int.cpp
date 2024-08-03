#include <iostream>
#include <vector>

using namespace std;

bool solve(vector<int> &nums, int target, int pos, vector<int> ans)
{
    if (pos == nums.size() || target < 0)
    {
        return false;
    }

    if (target == 0)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return true;
    }

    for (int i = pos; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);
        if (solve(nums, target - nums[i], i, ans))
        {
            return true;
        }
        ans.pop_back();
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> k >> x;
        if (x != 1)
        {   
            cout<<"YES"<<endl;
            cout<<k<<endl;
            for (int i = 1; i <= n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else
        {
            vector<int> ans;
            vector<int> nums;
            for (int i = 1; i <= k; i++)
            {
                if (i != x)
                {
                    nums.push_back(i);
                }
            }
            if (solve(nums, n, 0, ans) == false)
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}