#include <iostream>

using namespace std;

const int N = 100010;

int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    int m;
    scanf("%d", &m);

    init();
    while (m--)
    {
        int k, x;
        char c;
        cin >> c;
        if (c == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (c == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}
