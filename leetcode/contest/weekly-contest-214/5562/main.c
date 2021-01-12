#include <stdio.h>
#include <stdlib.h>

int minDeletions(char * s){
	int nums[26] = {0};
	int i, j;
	int ret = 0;

	for (i = 0; s[i] != '\0'; i++) {
		nums[s[i] - 'a']++;
	}

	for (i = 0; i < 26; i++) {
		for (j = i + 1; j < 26; j++) {
			if (nums[i] != 0 && nums[j] != 0 && nums[i] == nums[j]) {
				nums[j]--;
				ret++;
			}
		}
	}

	return ret;
}

int main(void)
{
	int ret;
	char str[1024] = {0};

	scanf("%s", str);
	ret = minDeletions(str);
	printf("%d\n", ret);

	return 0;
}
