// https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&difficulty[]=-2&difficulty[]=-1&page=1&query=category[]ArraysproblemStatusunsolveddifficulty[]-2difficulty[]-1page1category[]Arrays#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getfirstsecond(long long a[], int n) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        pair<ll, ll> pp = getfirstsecond(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}// } Driver Code Ends


pair<long long, long long> getfirstsecond(long long a[], int n) {
    
    pair<long long, long long> v;
    
    int first,second;
    v.first = v.second = INT_MIN;
    if (n == 1)
    {
        v.second = a[0];
        v.first = a[0];    
        return v;
    }
    if (a[0] > a[1])
    {
        v.second = a[0];
        v.first = a[1];
    }
    else
    {
        v.second = a[1];
        v.first = a[0];
    }
     
    for(int i = 2; i < n; i++)
    {
        if (a[i] > v.second)    
            v.second = a[i];
             
        else if (a[i] < v.first)    
            v.first = a[i];
    }
    
    return v;
}
