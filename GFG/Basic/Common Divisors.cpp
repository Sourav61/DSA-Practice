// https://practice.geeksforgeeks.org/problems/common-divisors4712/1/?category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&problemStatus=unsolved&difficulty[]=-1&page=1&query=category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-FlowproblemStatusunsolveddifficulty[]-1page1category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-Flow

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int commDiv(long long int a,long long int b) {
        int count=0;
        for(int i=1;i<=(a+b)/2;i++){
            if(a%i==0 && b%i==0){
                count++;
            }
        }
        return count; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int a, b;
        cin >> a >> b;
        Solution ob;
        cout<<ob.commDiv(a, b)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
