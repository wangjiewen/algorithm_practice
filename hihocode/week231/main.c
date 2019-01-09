#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int loop, stone, foot, step, gcd_num;

    scanf("%d", &loop);
    while (loop--) {
        scanf("%d%d%d", &stone, &foot, &step);
        if (stone > step)
            gcd_num = gcd(stone, step);
        else
            gcd_num = gcd(step, stone);
        if (foot > gcd_num) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
