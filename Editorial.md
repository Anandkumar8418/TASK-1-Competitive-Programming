In this problem the easy way will be in O(N^2) but the constraints will not allow this.

```
Wrong O(N^2) solution will be for each person iterating thorough all other persons 
and finding the orignal sandals and swapping it.
```
```
Right O(NlogN) solution -
First store the location of sandals in ascending order for left and right leg in O(N),
done in solution by SortingnyRight and SortingbyLeft vectors using vector of (firstpair of (secondpair and int))
where int represents the person who have the secondpair.first right sandals or secondpair.first left sandal for both vecotr
Then you can access the location of each sandal in O(1)
Swap sandals by finding sandals using find() function of STL in O(logN) and count the number of swaps.
```



```cpp

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
```
