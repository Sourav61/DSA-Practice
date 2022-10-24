// https://practice.geeksforgeeks.org/problems/earthquake-and-the-paint-shop4518/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    static bool comp(const alphanumeric &a, const alphanumeric &b){
        return a.name < b.name;
    }
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        unordered_map<string,int> mp;
        for(int i=0;i<N;i++){
            mp[A[i]]++;
        }
        
        vector<alphanumeric> res;
        
        for(auto x : mp){
            alphanumeric u;
            u.name = x.first;
            u.count = x.second;
            res.push_back(u);
        }
        
        sort(res.begin(),res.end(),comp);
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends