#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> get_divisor(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        auto res = get_divisor(a);
        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
