#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int mod = 1e9 + 7;
typedef long long LL;
int n;

int main()
{
    cin >> n;
    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }
    LL res = 1;
    for (auto t : primes)
    {
        int p = t.first, a = t.second;
        LL h = 1;
        while (a--)
            h = (h * p + 1) % mod;
        res = res * h % mod;
    }
    printf("%ld", res);
    return 0;
}