#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n;
int count[5] = {0};
int t[5] = {0}, n[i] = {0};
char str[300005];

void init()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        count[str[i]-'0'] += 1;
    }
}

void replace_big(char low, char high, int num)
{
    int num_c = 0;
    for (int i = n - 1; i >= 0 && num > num_c; i--) {
        if (str[i] == low) {
            str[i] = high;
            num_c += 1;
        }
    }
    t[low - '0'] -= num;
    n[high - '0'] -= num;
}

void replace_little(char low, char high, int num)
{
    int num_c = 0;
    for (int i = 0; i < n && num > num_c; i++) {
        if (str[i] == high) {
            str[i] = low;
            num_c += 1;
        }
    }
    t[high - '0'] -= num;
    n[low - '0'] -= num;
}

int main()
{
    init();
    int ans = n/3;
    for (int i = 0; i < 3; i++) {
        if (count[i] > ans) {
            t[i] = count[i] - ans;
        } else if (count[i] < ans) {
            n[i] = ans - count[i];
        }
    }

    replace_big('0', '1', min(t[0], n[1]));
    replace_big('0', '2', min(t[]))
    printf("%s\n", str);

    return 0;
}
