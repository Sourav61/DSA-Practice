// https://practice.geeksforgeeks.org/problems/reverse-a-string/1/?category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&problemStatus=unsolved&difficulty[]=-1&page=1&query=category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-FlowproblemStatusunsolveddifficulty[]-1page1category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-Flow#
// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){

      string rev_string;      
      int len=str.size();  
      for(int i=len-1;i>=0;i--){
          rev_string+=str[i];
      }
      return rev_string;
}
