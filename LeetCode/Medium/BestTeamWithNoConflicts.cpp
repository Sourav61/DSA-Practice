// https://leetcode.com/problems/best-team-with-no-conflicts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // =============================================   Approach-1(Memoization)   =======================================

    // int sol(int idx,vector<pair<int,int>>& temp,int prev, vector<vector<int>> &dp){
    //     if(idx==temp.size())
    //         return 0;

    //     if(dp[idx][prev] != -1){
    //         return dp[idx][prev];
    //     }

    //     int take=INT_MIN;
    //     int notTake = INT_MIN;

    //     if(prev>=temp[idx].second ){
    //         take = temp[idx].first + sol(idx+1,temp,temp[idx].second,dp);
    //     }

    //     notTake = sol(idx+1,temp,prev,dp);
    //     return dp[idx][prev] = max(take,notTake);
    // }

    // int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    //     vector<pair<int,int>> temp;
    //     int n = scores.size();
    //     vector<vector<int>> dp(n+1, vector<int> (1007,-1));

    //     for(int i=0;i<ages.size();i++){
    //         temp.push_back({scores[i],ages[i]});
    //     }

    //     sort(temp.begin(),temp.end(),greater<pair<int,int>>());

    //     return sol(0,temp,1001,dp);
    // }

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        // =============================================   Approach-2(Tabulation)   =======================================

        // vector<pair<int,int>> temp;
        // int n = scores.size();
        // vector<vector<int>> dp(n+1, vector<int> (1007,0));

        // for(int i=0;i<ages.size();i++){
        //     temp.push_back({scores[i],ages[i]});
        // }

        // int res = 0;
        // sort(temp.begin(),temp.end(),greater<pair<int,int>>());

        // for(int idx=n-1;idx>=0;idx--){
        //     int maxi = 0;
        //     for(int prev=1002;prev>=0;prev--){
        //         int take = INT_MIN;
        //         int notTake = INT_MIN;

        //         if(prev >= temp[idx].second){
        //             take = temp[idx].first + dp[idx+1][temp[idx].second];
        //         }

        //         notTake = dp[idx+1][prev];
        //         dp[idx][prev] = max(take,notTake);
        //         maxi = max(maxi, dp[idx][prev]);
        //     }
        //     res = max(res, maxi);
        // }

        // return res;

        // =============================================   Approach-3(LIS)   =======================================

        vector<pair<int, int>> basket;

        int n = scores.size();

        for (int i = 0; i < n; i++)
        {
            basket.push_back({ages[i], scores[i]});
        }

        sort(basket.begin(), basket.end());

        // for(int i=0;i<n;i++){
        //     cout<<basket[i].first<<" "<<basket[i].second<<endl;
        // }

        vector<int> dp(n);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (basket[i].second >= basket[j].second)
                {
                    dp[i] = max(dp[i], dp[j] + basket[i].second);
                }
            }
            res = max(res, dp[i]);
        }

        // for(auto &x : dp){
        //     cout<<x<<" ";
        // }cout<<endl;

        return res;
    }
};

int main()
{

    Solution obj;

    vector<int> scores = {1, 3, 5, 10, 15};

    vector<int> ages = {1, 2, 3, 4, 5};

    cout << obj.bestTeamScore();

    return 0;
}