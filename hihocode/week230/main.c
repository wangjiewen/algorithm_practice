#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str_org[100010] = {0}, str_ans[100010] = {0};

int get_min_pos(int start_pos, int end_pos)
{
    int i, ans = start_pos;
    char min = 'z';

    if (start_pos > end_pos)
        return -1;

    for (i = start_pos; i <= end_pos; i++) {
        if (str_org[i] < min) {
            min = str_org[i];
            ans = i;
        }
    }

    return ans;
}

int main()
{
    int ans_len, str_len;
    int start_pos, end_pos, min_pos, ans_pos;

    scanf("%d%s", &ans_len, str_org);
    str_len = strlen(str_org);

    ans_pos = 0;
    min_pos = -1;
    do {
        start_pos = min_pos + 1;
        end_pos = str_len - ans_len + ans_pos;
        min_pos = get_min_pos(start_pos, end_pos);
        str_ans[ans_pos] = str_org[min_pos];
        ans_pos += 1;
    } while (ans_pos < ans_len);

    printf("%s\n", str_ans);

    return 0;
}
