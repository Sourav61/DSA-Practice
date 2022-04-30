// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
        bool isSafe(int x, int y, vector<vector<int>> &m, vector< vector<bool>> visited, int n )
    {
        if( (x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y]==0) && (m[x][y]==1) )
        {
            return true;
        }
        return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &m, vector<string> &ans, vector< vector<bool>> visited, int n, string path )
    {
        // base case
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // 4 path
        // D L R U
        
        // Down
        if(isSafe(x+1, y, m, visited, n))
        {
            visited[x][y] = 1;
            solve(x+1, y, m, ans, visited, n, path + 'D');
            visited[x][y] = 0;
        }
        
        // Left
        if(isSafe(x, y-1, m, visited, n))
        {
            visited[x][y] = 1;
            solve(x, y-1, m, ans, visited, n, path + 'L');
            visited[x][y] = 0;
        }
        
        // Right
        if(isSafe(x, y+1, m, visited, n))
        {
            visited[x][y] = 1;
            solve(x, y+1, m, ans, visited, n, path + 'R');
            visited[x][y] = 0;
        }
        
        // UP
        if(isSafe(x-1, y, m, visited, n))
        {
            visited[x][y] = 1;
            solve(x-1, y, m, ans, visited, n, path + 'U');
            visited[x][y] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector< vector<bool>> visited(n, vector<bool>(n, 0));
        string path="";
        if(m[0][0] == 0)
            return ans;
        
        solve(0, 0, m, ans, visited, n, path);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Endss