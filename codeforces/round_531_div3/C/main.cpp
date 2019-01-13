#include <iostream>
#include <stdio.h>

using namespace std;

int n, x, y;
int a[105];
int num = 0;
int add = 0;

void init()
{
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] <= x) {
            num += 1;
        }
        if (add == 0 && a[i] <= 2*x) {
            add = 1;
        }
    }
}

int main()
{
    init();

    if (x > y) {
        printf("%d", n);
    } else {
        printf("%d", (num+add)/2);
    }
    return 0;
}
