// https://practice.geeksforgeeks.org/problems/anshumans-favourite-number2029/1/?problemStatus=solved&difficulty[]=-1&page=1&query=problemStatussolveddifficulty[]-1page1

// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    string isValid(long long N){
        if(N%5==0){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.isValid(N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
