#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
int n;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int a, p;
        scanf("%d%d", &a, &p);
        int res = qmi(a, p - 2, p);
        if (a % p)
            printf("%d\n", res);
        else
            puts("impossible");
    }
    return 0;
}