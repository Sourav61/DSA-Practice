// https://leetcode.com/problems/three-divisors/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isThree(int n) {
        if(n < 4){
            return false;
        }

        for(int i=2;i<=sqrt(n);i++){
            if(n % i == 0 &&  i * i != n){
                return false;
            }
        }

        return (int)sqrt(n)*sqrt(n) == n;
    }
};

int main(){
    Solution obj;

    cout<<obj.isThree(n);

    return 0;
}