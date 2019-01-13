#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    n = n % 4;
    if (n == 0 || n == 3)
        printf("0");
    else
        printf("1");
    return 0;
}

