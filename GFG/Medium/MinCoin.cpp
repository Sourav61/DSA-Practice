// https://practice.geeksforgeeks.org/problems/min-coin5549/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int x)
	{
	    int n = nums.size();
        vector<int> prev(x+1,0),cur(x+1,0);
        
        for(int T=0;T<=x;T++){
            if(T%nums[0] == 0){
                prev[T] = T/nums[0];
            }else{
                prev[T] = 1e9;
            }
        }
        
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=x;T++){
                int notTake = prev[T];
                int take = INT_MAX;
                if(nums[ind] <= T){
                    take = 1 + cur[T-nums[ind]];
                }
    
                cur[T] = min(take, notTake);
            }
            prev = cur;
        }
        
        int res = prev[x];
        
        if(res >= 1e9){
            return -1;
        }
        return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Endss