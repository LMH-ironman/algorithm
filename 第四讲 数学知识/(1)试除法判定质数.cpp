#include <iostream>
#include <cstdio>

using namespace std;
int n;
bool is_prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int a;
        cin >> a;
        if (is_prime(a))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}