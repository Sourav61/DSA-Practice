// https://leetcode.com/problems/maximum-units-on-a-truck/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool sortSec(const vector<int>& v1, const vector<int> &v2){
        return v1[1]>v2[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sortSec);
        int sum = 0;

        for(vector<int> v : boxTypes){
            if(truckSize >= v[0]){
                sum += v[0] * v[1];
                truckSize -= v[0];
            }else if(truckSize <= v[0] && truckSize > 0){
                sum += (truckSize % v[0]) * v[1];
                truckSize -= truckSize % v[0];
            }
        }

        return 0;
    }
};

int main(){

    Solution obj;

    vector<vector<int>> boxTypes = {{1,2},{2,2},{3,1}};

    cout<<obj.maximumUnits(boxTypes, 4);

    return 0;
}