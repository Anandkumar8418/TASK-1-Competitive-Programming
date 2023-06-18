
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define v32 vector<int>
#define pii pair<int, int>
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pii> vec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pii p = {a, b};
        vec.pb(p);
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].first != i + 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j].first == i + 1)
                {
                    count1++;
                    vec[j].first = vec[i].first;
                    vec[i].first = i + 1;
                }
            }
        }
        if (vec[i].second != i + 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j].second == i + 1)
                {
                    count1++;
                    vec[j].second = vec[i].second;
                    vec[i].second = i + 1;
                }
            }
        }
    }

    cout << count1;
}