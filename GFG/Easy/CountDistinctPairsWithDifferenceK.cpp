// https://practice.geeksforgeeks.org/problems/count-distinct-pairs-with-difference-k1233/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            int second = x.first - k;
            if(mp.find(second)!=mp.end())
            {
                if((second)==x.first)
                {
                    if(x.second > 1)
                        count++;
                }
                else
                    count++;
            }
        }
        return count;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends