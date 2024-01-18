// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-searching/problem/missing-number-in-array1416

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int missingNumber(vector<int> &a, int n)
    {
        int sum = 0;
        int ans;
        for (int i = 0; i < n - 1; i++)
        {
            sum += a[i];
        }

        int originalsum = n * (n + 1) / 2;
        // cout << "sum " << sum <<endl<<"original sum: " << originalsum<<endl;
        ans = originalsum - sum;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends