#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s){
	int half_len = 0, c = 0;
	int i = 0, j;
	char *ret;

	while (s[i] != '\0') {
		j = 1;
		while (i-j >= 0 && s[i+j] != '\0' && s[i-j] == s[i+j]) {
			j++;
		}
		if (j > half_len) {
			half_len = j - 1;
			c = i;
		}
		i++;
	}

	ret = (char *)malloc(sizeof(char)*(2*half_len + 2));
	memcpy(ret, s+(c-half_len), 2*half_len+1);
	ret[2*half_len+1] = '\0';
	return ret;
}

int main(void)
{
	char *s = "babad";
	char *ret = longestPalindrome(s);
	printf("%s\n", ret);
	free(ret);
	return 0;
}
