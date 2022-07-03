// https://practice.geeksforgeeks.org/problems/longest-zig-zag-sub-sequence2656/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int ZigZagMaxLength(vector<int>&nums){
		    int n = nums.size();

            if(n == 0)
                return 0;

            vector<int> pos(n,0);
            vector<int> neg(n,0);

            pos[0] = 1;
            neg[0] = 1;

            for(int i=1;i<n;i++){
                if(nums[i] > nums[i-1]){
                    pos[i] = neg[i-1] + 1;
                    neg[i] = neg[i-1];
                }else if(nums[i] < nums[i-1]){
                    neg[i] = pos[i-1] + 1;
                    pos[i] = pos[i-1];
                }else{
                    pos[i] = pos[i-1];
                    neg[i] = neg[i-1];
                }
            }
            return max(pos[n-1], neg[n-1]);
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.ZigZagMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends