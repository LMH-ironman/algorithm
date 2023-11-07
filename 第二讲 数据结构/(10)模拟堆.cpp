#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int h[N], hp[N], ph[N], cnt;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n--)
    {
        int x, k;
        string c;
        cin >> c;
        if (c == "I")
        {
            scanf("%d", &x);
            cnt++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if (c == "PM")
            printf("%d\n", h[1]);
        else if (c == "DM")
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (c == "D")
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}