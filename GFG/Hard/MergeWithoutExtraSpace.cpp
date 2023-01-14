// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // --------------------------                                  ---------------------------------

        // priority_queue<int, vector<int> ,greater<int>> minH;
        // for(int i=0;i<n;i++)
        //     minH.push(arr1[i]);

        // for(int i=0;i<m;i++)
        //     minH.push(arr2[i]);
        // int i = 0;
        // while(n--){
        //     arr1[i++] = minH.top();
        //     minH.pop();
        // }

        // i = 0;
        // while(m--){
        //     arr2[i++] = minH.top();
        //     minH.pop();
        // }

        // --------------------------                                  ---------------------------------

        // int i = n - 1;
        // int j = 0;
        // while(i >= 0 && j < m){
        //     if(arr1[i] > arr2[j]){
        //         swap(arr1[i],arr2[j]);
        //         i--;
        //         j++;
        //     }
        //     else
        //         break;
        // }
        // sort(arr1,arr1 + n);
        // sort(arr2,arr2 + m);

        // --------------------------                                  ---------------------------------

        int gap = ceil((float)(n + m) / 2);

        while (gap > 0)
        {
            int i = 0;
            int j = gap;

            while (j < (n + m))
            {
                if (j < n && arr1[i] > arr1[j])
                    swap(arr1[i], arr1[j]);
                else if (j >= n && i < n && arr1[i] > arr2[j - n])
                    swap(arr1[i], arr2[j - n]);
                else if (j >= n && i >= n && arr2[i - n] > arr2[j - n])
                    swap(arr2[i - n], arr2[j - n]);

                i++;
                j++;
            }

            if (gap == 1)
                gap = 0;
            else
                gap = ceil((float)gap / 2);
        }
        return;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends