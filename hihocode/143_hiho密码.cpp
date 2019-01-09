/*************************************************************************
	> File Name: 143_hiho密码.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/28 10:19:45 2017
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    int n, a[1005], k;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(k = max(n - 1, 1) ; k > 1; k--)
    {
        if(a[k] < a[k - 1])
            break;
    }
    for(int i = 0; i < k; i++)
        cout << a[i] << " ";
}

