#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;
typedef long long LL;
int n;
int primes[N], cnt;
int euler[N];
bool st[N];

void get_euler(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {

            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            euler[primes[j] * i] = euler[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    cin >> n;
    get_euler(n);
    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += euler[i];
    cout << res;
    return 0;
}