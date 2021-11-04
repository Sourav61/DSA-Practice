// https://practice.geeksforgeeks.org/problems/krishnamurthy-number1323/1/?category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&problemStatus=unsolved&difficulty[]=-1&page=1&query=category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-FlowproblemStatusunsolveddifficulty[]-1page1category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-Flow

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
        
    string isKrishnamurthy(int N) {
        
        int rem,mult=1,a=N,sum=0;
        while(N!=0){
            rem=N%10;
            N=N/10;
            while(rem>0){
                mult*=rem;
                rem--;
            }
            sum+=mult;
            mult=1;
        }
        if(sum==a){
                cout<<"YES";
        }else{
            cout<<"NO";
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isKrishnamurthy(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
