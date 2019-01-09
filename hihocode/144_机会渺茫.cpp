#include<iostream>
#include<cmath>

using namespace std;

int apprcnt(int x)
{
    int cnt = 0;
    int n = sqrt(x);
    for(int i = 1; i < n; i++)
    {
        if(x % i == 0)
            cnt += 2;
    }
    if(n * n == x)
        return cnt - 1;
    return cnt;
}

int main()
{
    long n, m;
    long ans1, ans2;
    cin >> n >> m;
    return 0;
}
