// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/?problemStatus=solved&difficulty[]=0&page=1&query=problemStatussolveddifficulty[]0page1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    
    string reverseWords(string S) 
    { 
        char tmp;
        string result="";
        int i,j,k,len;
        len=S.size();
    
        for(j=0;j<len;j++){
            if(S[j]=='.' || (j == len-1)){
                if(j<len-1){
                    k=j-1;
                }else{
                    k=j;
                }
                
                while(i<k){
                    tmp=S[i];
                    S[i]=S[k];
                    S[k]=tmp;
                    i++;
                    k--;
                }
                
                i=j+1;
            }
        }
        
        for (int i = S.size()-1; i>=0; --i)
        {
            result += S[i];
            if(i!=0)
                result += '.';
        }
        //returning the result.
        cout<<result;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends
