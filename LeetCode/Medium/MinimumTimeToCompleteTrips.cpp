// https://leetcode.com/problems/minimum-time-to-complete-trips/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1, high = 1e14;

        while(low <= high){
            long long int mid = low + (high - low)/2;
            long long int temp = 0;
            for(auto &x : time){
                long long int val = x;
                temp += mid / val;
            }
            if(temp >= totalTrips){
                high = mid - 1;
            }else if(temp < totalTrips){
                low = mid + 1;
            }
        }

        return low;
    }
};

int main(){

    Solution obj;

    vector<int> time = {1,2,3};

    cout<<obj.minimumTime(time, 5);

    return 0;
}