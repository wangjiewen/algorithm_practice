#include <iostream>
#include <stdio.h>

using namespace std;

int n, k;
int a[5005];
int num[5005] = {0};
bool ju[5005][5005] = {false};

bool init()
{
    scanf("%d%d", &n, &k);
    if (n < k) return false;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        num[a[i]] += 1;
        if (num[a[i]] > k) {
            return false;
        }
    }
    return true;
}

int main()
{
    bool flag = init();
    if (flag) {
        printf("YES\n");
        int color = 1;
        int i;
        for (i = 0; i < n && color <= k; i++) {
            if (!ju[a[i]][color]) {
                printf("%d ", color);
                ju[a[i]][color] = true;
                color += 1;
            } else {
                for(int j = 1; j <= k; j++) {
                    if (!ju[a[i]][j]) {
                        printf("%d ", j);
                        ju[a[i]][j] = true;
                        break;
                    }
                }
            }
        }
        for (; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                if (!ju[a[i]][j]) {
                    printf("%d ", j);
                    ju[a[i]][j] = true;
                    break;
                }
            }
        }
    } else {
        printf("NO\n");
    }

    return 0;
}
