// https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string-1587115621/1/?category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&category[]=Mathematical&category[]=Strings&category[]=CPP&category[]=Prime%20Number&category[]=number-theory&category[]=Design-Pattern&category[]=series&category[]=Fibonacci&category[]=pattern-printing&category[]=%20modular%20arithmetic&category[]=Operators&category[]=Data%20Type&category[]=Functions&category[]=cpp-operator&category[]=cpp-strings&category[]=%20CPP-Control-Flow&category[]=CPP-Control-Flow&problemStatus=unsolved&difficulty[]=-1&page=1&query=category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-FlowproblemStatusunsolveddifficulty[]-1page1category[]Mathematicalcategory[]Stringscategory[]CPPcategory[]Prime%20Numbercategory[]number-theorycategory[]Design-Patterncategory[]seriescategory[]Fibonaccicategory[]pattern-printingcategory[]%20modular%20arithmeticcategory[]Operatorscategory[]Data%20Typecategory[]Functionscategory[]cpp-operatorcategory[]cpp-stringscategory[]%20CPP-Control-Flowcategory[]CPP-Control-Flow#

// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    int findSum(string str)
    {
    	string temp = "";
    	int sum = 0;
    
    	for (char ch: str)
    	{
    		if (isdigit(ch))
    			temp += ch;
    		else
    		{
    			sum += atoi(temp.c_str());
    			temp = "";
    		}
    	}
    	return sum + atoi(temp.c_str());
    }

};

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
