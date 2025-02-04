// C++ implementation to find the next
// greater element using a stack
#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> stk;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack that are less
        // than or equal to the current element
        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        // If the stack is not empty, the top element
        // is the next greater element
        if (!stk.empty()) {
            result[i] = stk.top();
        }

        // Push the current element onto the stack
        stk.push(arr[i]);
    }

    return result;
}


int main() {

    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> result = nextLargerElement(arr);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}