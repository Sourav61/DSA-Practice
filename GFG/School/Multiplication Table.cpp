// https://practice.geeksforgeeks.org/problems/print-table0303/1/?problemStatus=solved&difficulty[]=-2&page=1&query=problemStatussolveddifficulty[]-2page1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> getTable(int N)
    {
        for(int i = 1; i <= 10; ++i){
            int ans=1;
            vector<int> result;
    	    for(int i=1;i<=10;i++)
    	    {
    	        ans=N*i;
    	        result.push_back(ans);
    	    }
    	    return result;
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.getTable(N);
        for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
