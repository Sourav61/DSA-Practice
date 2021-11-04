// https://practice.geeksforgeeks.org/problems/bitwise-operators/1/?problemStatus=solved&difficulty[]=0&page=1&query=problemStatussolveddifficulty[]0page1

// { Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

// Function Prototype
void bitWiseOperation(int, int, int);


 // } Driver Code Ends
// User function Template for C++

// Function to perform bitwise manipulations
// a, b and c are input integers
void bitWiseOperation(int a, int b, int c) {

    int d,e,f,g;
    d=a^a;
    e=c^b;
    f=a&b;
    g=c|(a^a);
    cout<<d<<endl;
    cout<<e<<endl;
    cout<<f<<endl;
    cout<<g<<endl;
    cout<<~e<<endl;
}

// { Driver Code Starts.

// Driver code to test above function
int main() {

    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        bitWiseOperation(a, b, c);
    }

    return 0;
}  // } Driver Code Ends