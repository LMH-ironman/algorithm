#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m;
int h[N], s;

void down(int u)
{
    int t = u;
    if (u * 2 <= s && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    s = n;

    for (int i = n / 2; i; i--)
        down(i);
    while (m--)
    {
        printf("%d ", h[1]);
        h[1] = h[s];
        s--;
        down(1);
    }
    return 0;
}