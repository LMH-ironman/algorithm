#include <iostream>

using namespace std;
typedef long long LL;
int n;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if (b % d)
            puts("impossible");
        else
            printf("%d\n", (LL)b / d * x % m);
    }
    return 0;
}