#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

void merge(vector<pii> &segs)
{
    vector<pii> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        if (ed < seg.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else
            ed = max(ed, seg.second);
    }

    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}

int main()
{
    int n;
    cin >> n;
    vector<pii> segs;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size();
    return 0;
}