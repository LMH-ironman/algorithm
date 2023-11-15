#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100010, M = 2 * N;
int ans = N;
int n;
int h[N], idx, e[M], ne[M];
bool stl[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u)
{
    int res = 0;
    stl[u] = true;
    int sum = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!stl[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}
