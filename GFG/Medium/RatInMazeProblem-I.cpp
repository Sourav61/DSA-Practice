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
    
    void solve(int x, int y, vector<vector<int>> &m, vector<string> &ans, vector< vector<bool>> visited, int n, string path, int di[],int dj[])
    {
        // // base case
        // if(x == n-1 && y == n-1)
        // {
        //     ans.push_back(path);
        //     return;
        // }
        
        // 4 path
        // D L R U
        
        // Down
        //     if(isSafe(x+1, y, m, visited, n))
        //     {
        //         visited[x][y] = 1;
        //         solve(x+1, y, m, ans, visited, n, path + 'D');
        //         visited[x][y] = 0;
        //     }
            
        //     // Left
        //     if(isSafe(x, y-1, m, visited, n))
        //     {
        //         visited[x][y] = 1;
        //         solve(x, y-1, m, ans, visited, n, path + 'L');
        //         visited[x][y] = 0;
        //     }
            
        //     // Right
        //     if(isSafe(x, y+1, m, visited, n))
        //     {
        //         visited[x][y] = 1;
        //         solve(x, y+1, m, ans, visited, n, path + 'R');
        //         visited[x][y] = 0;
        //     }
            
        //     // UP
        //     if(isSafe(x-1, y, m, visited, n))
        //     {
        //         visited[x][y] = 1;
        //         solve(x-1, y, m, ans, visited, n, path + 'U');
        //         visited[x][y] = 0;
        //     }

    // =================                Approach-2            =================================
        // base case
        // if(x == n-1 && y == n-1)
        // {
        //     ans.push_back(path);
        //     return;
        // }
        // // Moving in downward direction
        // if(x+1<n && !visited[x+1][y] && m[x+1][y] == 1){
        //     visited[x][y] = 1;
        //     solve(x+1,y,m,ans,visited, n,path+ 'D');
        //     visited[x][y] = 0;
        // }

        // // Moving in Leftward Direction

        // if(y-1 >= 0 && !visited[x][y-1] && m[x][y-1] == 1){
        //     visited[x][y] = 1;
        //     solve(x,y-1,m,ans,visited,n,path+'L');
        //     visited[x][y] = 0;
        // }

        // // Moving in RightWard Direction

        // if(y+1 < n && !visited[x][y+1] && m[x][y+1] == 1){
        //     visited[x][y] = 1;
        //     solve(x,y+1,m,ans,visited,n,path+'R');
        //     visited[x][y] = 0;
        // }

        // // Moving in Upward Direction

        // if(x-1 >= 0 && !visited[x-1][y] && m[x-1][y] == 1){
        //     visited[x][y] = 1;
        //     solve(x-1,y,m,ans,visited,n,path + 'U');
        //     visited[x][y] = 0;
        // }

    // ======================= Approach-3 (Ideal) ======================================
        // base case

        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        string dir = "DLRU";

        for(int i=0;i<4;i++){
            int nexti = x + di[i];
            int nextj = y + dj[i];

            if((nexti >= 0 && nexti <= n) && (nextj >= 0 && nextj <= n) && !visited[nexti][nextj] && m[nexti][nextj] == 1){
                visited[x][y] = 1;
                solve(nexti, nextj, m, ans ,visited, n ,path+dir[i], di, dj);
                visited[x][y] = 0;
            }
        }
    }


    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector< vector<bool>> visited(n, vector<bool>(n, 0));
        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,+1,0};
        string path="";
        if(m[0][0] == 1)
            solve(0, 0, m, ans, visited, n, path, di,dj);
        
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