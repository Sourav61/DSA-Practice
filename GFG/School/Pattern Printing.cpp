// https://practice.geeksforgeeks.org/problems/pattern-printing1347/1/?category[]=pattern-printing&category[]=pattern-printing&problemStatus=unsolved&difficulty[]=-2&page=1&query=category[]pattern-printingproblemStatusunsolveddifficulty[]-2page1category[]pattern-printing#

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void printPattern(int N)
    {
        for(int i=N;i>0;i--){
            for(int j=N-i;j>=0;j--){
                cout<<"*";
            }
            cout<<" ";
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printPattern(N);
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
