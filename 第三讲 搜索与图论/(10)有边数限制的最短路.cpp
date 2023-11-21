#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
const int M = 10010;
int n, m, k;
int dist[N];
int backup[N];

struct edge
{
    int a, b, c;
} edge[M];

void bf()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            auto e = edge[j];
            dist[e.b] = min(dist[e.b], backup[e.a] + e.c);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i] = {a, b, c};
    }

    bf();

    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d", dist[n]);
    return 0;
}
