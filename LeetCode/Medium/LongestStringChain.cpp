// https://leetcode.com/problems/longest-string-chain/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool checkPossible(string &s1, string &s2){
    //     if(s1.size() != s2.size() + 1)
    //         return false;

    //     int first = 0;
    //     int sec = 0;

    //     while(first < s1.size()){
    //         if(sec < s2.size() && s1[first] == s2[sec]){
    //             first++;
    //             sec++;
    //         }else{
    //             first++;
    //         }
    //     }

    //     if(first == s1.size() && sec == s2.size())
    //         return true;

    //     return false;
    // }

    // static bool comp(string &a, string &b){
    //     return a.size() < b.size();
    // }

    // int longestStrChain(vector<string>& words) {
    //     int n = words.size();

    //     vector<int> dp(n,1);
    //     int maxi = 1;

    //     sort(words.begin(),words.end(),comp);

    //     for(int i=1;i<n;i++){
    //         for(int prev=0;prev<n;prev++){
    //             if(checkPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
    //                 dp[i] = 1 + dp[prev];
    //             }
    //         }
    //         if(dp[i] > maxi)
    //             maxi = dp[i];
    //     }

    //     return maxi;
    // }

    static bool compare(const string &s1, const string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;

        int res = 1;

        for (string &w : words)
        {
            for (int i = 0; i < w.length(); i++)
            {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }

        return res;
    }
};

int main()
{

    Solution obj;

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << obj.longestStrChain(words);

    return 0;
}