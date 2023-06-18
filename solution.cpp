
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
    vector<pair<pii, int>> inputvec;
    vector<pair<pii, int>> SortingbyRight;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pii p = {a, b};
        pair<pii, int> p2 = {p, i + 1};
        inputvec.pb(p2);
        pii temppair = {b, a};
        pair<pii, int> temppair2 = {temppair, i + 1};
        SortingbyRight.pb(temppair2);
    }
    vector<pair<pii, int>> SortingbyLeft = inputvec;
    sort(all(SortingbyLeft));
    v32 leftleg(n);
    for (int i = 0; i < n; i++)
    {
        leftleg[i] = SortingbyLeft[i].second;
    }
    sort(all(SortingbyRight));
    v32 rightleg(n);
    for (int i = 0; i < n; i++)
    {
        rightleg[i] = SortingbyRight[i].second;
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftleg[i] != i + 1)
        {
            auto it = find(all(leftleg), i + 1);
            int index = it - leftleg.begin();
            leftleg[index] = leftleg[i];
            leftleg[i] = i + 1;
            count1++;
        }
        if (rightleg[i] != i + 1)
        {
            auto it2 = find(all(rightleg), i + 1);
            int index2 = it2 - rightleg.begin();
            rightleg[index2] = rightleg[i];
            rightleg[i] = i + 1;
            count1++;
        }
    }
    cout << count1;
}
