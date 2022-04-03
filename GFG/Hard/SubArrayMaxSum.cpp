#include <bits/stdc++.h>
using namespace std;

// Size of given matrix
#define N 5

void printMaxSumSub(int[][] A, int B)
{
    cout << "MMMMM" << A.length();
}

int main()
{
    int mat[N][N] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 8, 6, 7, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5},
    };
    int k = 3;

    cout << "Maximum sum 3 x 3 matrix is\n";
    printMaxSumSub(mat, k);

    return 0;
}