// https://practice.geeksforgeeks.org/problems/c-2-d-arrays0708/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2page1category[]Arrays#

// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
#define M 101

vector<vector<int>> transpose(int a[][M], int n);

int main()
{
    int t;
    cin>>t;
    int a[M][M];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        vector<vector<int>> b;
        b = transpose(a, n);
        for(int i=0;i < n;i++)
        {
            for(int j=0;j<n;j++){
                cout << b[i][j] << " ";
            }
        }
        cout<<endl;
    }
}


// } Driver Code Ends



vector<vector<int>> transpose(int a[][M], int n)
{
    vector<vector<int>> b(n, vector<int>(n, 0));    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j] = a[j][i];
        }
    }
    
    return b;
    
}
