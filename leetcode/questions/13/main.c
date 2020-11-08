#include <stdio.h>
#include <stdlib.h>

int romanToInt(char * s){
	int i = 0;
	int ret = 0;

	while (s[i] != '\0') {
		if (s[i] == 'I') {
			if (s[i+1] == 'V') {
				ret += 4;
				i += 1;
			} else if (s[i+1] == 'X') {
				ret += 9;
				i += 1;
			} else {
				ret += 1;
			}
		} else if (s[i] == 'V') {
			ret += 5;
		} else if (s[i] == 'X') {
			if (s[i+1] == 'L') {
				ret += 40;
				i += 1;
			} else if (s[i+1] == 'C') {
				ret += 90;
				i += 1;
			} else {
				ret += 10;
			}
		} else if (s[i] == 'L') {
			ret += 50;
		} else if (s[i] == 'C') {
			if (s[i+1] == 'D') {
				ret += 400;
				i += 1;
			} else if (s[i+1] == 'M') {
				ret += 900;
				i += 1;
			} else {
				ret += 100;
			}
		} else if (s[i] == 'D') {
			ret += 500;
		} else if (s[i] == 'M') {
			ret += 1000;
		} else {
			printf("error\n");
			return -1;
		}
		i += 1;
	}
	return ret;
}

int main(void)
{
	char *str = "MCMXCIV";
	int ret;

	ret = romanToInt(str);
	printf("%d\n", ret);
	return 0;
}
