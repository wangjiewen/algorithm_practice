#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *nums[8] = {"abc", "def", "ghi", "jkl",
		"mno", "pqrs", "tuv", "wxyz",};
static int nums_len[8] = {3, 3, 3, 3, 3, 4, 3, 4};
char str[128] = {'\0'};
int i_num = 0;

void DFS(int index, char *digits, char **ret)
{
	int len;
	int num;

	if (digits[index] == '\0') {
		str[index] = '\0';
		memcpy(ret[i_num], str, index+1);
		i_num+=1;
		return;
	}

	num = digits[index] - '0';
	len = strlen(nums[num - 2]);
	for (int i = 0; i < len; i++) {
		str[index] =  nums[num - 2][i];
		DFS(index + 1, digits, ret);
	}
}

char ** letterCombinations(char * digits, int* returnSize){
	int length = strlen(digits);
	int total_len = 1;
	for (int i = 0; i < length; i++) {
		total_len *= nums_len[digits[i] - '0' - 2];
	}

	*returnSize = length > 0 ? total_len : 0;
	char **ret = (char **)malloc(total_len*sizeof(char*));
	for (int i = 0; i < total_len; i++) {
		ret[i] = (char *)calloc(length + 1, sizeof(char));
	}

	if (length != 0) {
		DFS(0, digits, ret);
	}

	return ret;
}

int main(void)
{
	int ret_len;
	char **ret;

	ret = letterCombinations("2", &ret_len);

	for (int i = 0; i < ret_len; i++) {
		printf("%s, ", ret[i]);
	}
	printf("\n");
	return 0;
}
