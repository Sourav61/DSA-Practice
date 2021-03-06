https://practice.geeksforgeeks.org/problems/pangram-checking-1587115620/1/#

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        bool l[26]={false};
        for(int i=0;i<str.size();i++){
            
//             if(str[i]>='a' && str[i]<='z'){
//                 l[str[i]-'a']=1;
//             }
            
//             if(str[i]>='A' && str[i]<='Z'){
//                 l[str[i]-'A']=1;
//             }
            
            if(int(str[i])>=97 && int(str[i])<=122){
                l[str[i]-97]=1;
            }
            
            if(int(str[i])>=65 && int(str[i])<=90){
                l[str[i]-65]=1;
            }
        }
        
        for(int i=0;i<26;i++){
            if(l[i]==0){
                return 0;
            }
        }
        return 1;
    }

};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends
