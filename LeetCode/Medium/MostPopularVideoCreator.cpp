// https://leetcode.com/contest/weekly-contest-317/problems/most-popular-video-creator/

class Solution
{
public:
    // vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    // {
    //     unordered_map<string, vector<int>> mp;
    //     for (int i = 0; i < creators.size(); i++)
    //     {
    //         mp[creators[i]].push_back(i);
    //     }

    //     priority_queue<pair<long long int, string>, vector<pair<long long int, string>>> maxH;

    //     vector<vector<string>> res;

    //     for (auto &x : mp)
    //     {
    //         long long int pop = 0;
    //         for (auto &idx : x.second)
    //         {
    //             pop += views[idx];
    //         }
    //         maxH.push({pop, x.first});
    //     }

    //     long long int maxi = maxH.top().first;

    //     while (maxH.top().first == maxi && !maxH.empty())
    //     {
    //         string creator = maxH.top().second;
    //         vector<int> top = mp[creator];

    //         int maxView = INT_MIN;
    //         string topId = "";

    //         if (top.size() == 1)
    //         {
    //             maxView = top[0];
    //             topId = ids[top[0]];
    //         }
    //         else
    //         {
    //             for (auto &x : top)
    //             {
    //                 if (views[x] > maxView)
    //                 {
    //                     maxView = views[x];
    //                     topId = ids[x];
    //                 }
    //             }
    //         }

    //         res.push_back({creator, topId});
    //         maxH.pop();
    //     }

    //     sort(res.begin(), res.end());

    //     return res;
    // }

    struct video
    {
        long sum = 0;
        string small;
        int max_view = 0;
    };

    vector<vector<string>> mostPopularCreator(vector<string> &c, vector<string> &ids, vector<int> &views)
    {
        unordered_map<string, video> mp;
        long count = 0;

        for (int i = 0; i < size(c); i++)
        {
            if (!mp.count(c[i]))
            {
                mp[c[i]] = {views[i], ids[i], views[i]};
                count = max(count, mp[c[i]].sum);
                continue;
            }

            mp[c[i]].sum += views[i];
            if (mp[c[i]].max_view < views[i] || mp[c[i]].max_view == views[i] && ids[i] < mp[c[i]].small)
            {
                mp[c[i]].max_view = views[i];
                mp[c[i]].small = ids[i];
            }

            count = max(count, mp[c[i]].sum);
        }

        vector<vector<string>> ans;
        for (auto &r : mp)
            if (r.second.sum == count)
                ans.push_back({r.first, r.second.small});

        return ans;
    }
};