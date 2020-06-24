#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s) {
	int numbers[256] = {0};
	int head = 0, tail = 0;
	int ret = 0;

	while (s[head] != '\0') {
		while (s[tail] != '\0' && !numbers[s[tail]]) {
			numbers[s[tail]] = 1;
			tail += 1;
		}
		ret = ret > tail - head ? ret : tail - head;
		numbers[s[head]] = 0;
		head += 1;
	}
	return ret;

}

int main(void)
{
	char *s = "aab";
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);
}
