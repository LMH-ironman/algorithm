#include <iostream>
#include <cstdio>

using namespace std;
int n;
const int N = 10;
int path[N];
bool str[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!str[i])
        {
            path[u] = i;
            str[i] = true;
            dfs(u + 1);
            str[i] = false;
        }
    }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}