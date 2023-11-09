#include <iostream>
using namespace std;
const int N = 50010;

int n, k;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
        p[i] = i;
    int res = 0;
    while (k--)
    {
        int D, x, y;
        scanf("%d%d%d", &D, &x, &y);
        if (x > n || y > n)
            res++;
        else
        {
            int px = find(x), py = find(y);
            if (D == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = p[y];
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = p[y];
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}