#define P 1000000007

long long fastpower(long long base, long long power) {
	long long ret = 1;
	while (power > 0) {
		if (power % 2 == 1) {
			ret = ret * base % P;
		}
		power = power / 2;
		base = (base * base) % P;
	}
	return ret;
}

