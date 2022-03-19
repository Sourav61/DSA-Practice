// https://www.hackerrank.com/challenges/playing-with-characters/problem?isFullScreen=true

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char ch, s[100], sen[100];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%c", &ch);
    printf("%c", ch);
    printf("\n");
    scanf("%s", s);
    printf("%s", s);
    printf("\n");
    scanf(" %[^\n]%*c", sen);
    printf("%s", sen);
    return 0;
}
