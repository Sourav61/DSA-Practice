// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> ans; 
	bool isSafe(int row, int col, vector<int> &path)
	{
		for (int i = row - 2; i >= 0; i--) 
		{
			if (path[i] == col)
				return false;
		}
		for (int i = row - 2; i >= 0; i--) 
		{
			if(path[i] == i - row + col + 1)
			    return false;
		}
		for (int i = row - 2; i >= 0; i--) 
		{
			if(path[i] == row + col - i - 1)
			    return false;
		}
		return true;
	}

	void helper(int row, int n, vector<int> path)
	{
		if (path.size() == n) // base case
		{
			ans.push_back(path);
		}

		for (int col = 1; col <= n; col++)
		{
			if (isSafe(row, col, path))
			{
				path.push_back(col);
				helper(row + 1, n, path);
				path.pop_back();
			}
		}
	}

	vector<vector<int>> nQueen(int n)
	{
		if (n == 0 || n == 2 || n == 3)
			return ans; //return empty 2d vector
		if (n == 1)
			return {{1}};
		vector<int> path;
		helper(1, n, path);
		return ans;
	}

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends