#include <iostream>

using namespace std;

int n;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        printf("%d\n", gcd(a, b));
    }
    return 0;
}