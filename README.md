# TASK-1-Competitive-Programming
Name -
```
Identical Sandals
```
Problem Statement - 
```
Wing C3 planned to visit JK Temple and wore their sandals for the trip.
However, upon reaching the temple, they had to leave their sandals at the entrance.
When they returned from the temple, they realized that all the sandals were identical in design and color,
so they unintentionally wore each other's sandals.
Now, back at Wing C3, they want to return the sandals to their original owners.
However, they have a class, MTH101, to attend. Can you assist them in sorting the sandals with the fewest
possible swaps?

Example- 

1 2

2 1

1st Person has 2nd person's sandal in right leg so one swap is enough.
```

Input(In Latex text) - 
```
First Line of Input contains $n$  ($1 \le n \le 3 \cdot10^5$) --- Number of people 

Next $n$ lines contains two numbers $a$ and $b$ ($1 \le a \le 3 \cdot 10^5$ , $1 \le b \le 3 
\cdot 10^5$) --- Where $ith$ line contains $a_i$ which is the left sandals of $ith$ person and $b_i$ which is the right sandals of $ith$ person.
```
Output - 
```
For each test Case, print the minimum number of swaps to give sandals back to their owners.
```
Generating test cases as txt files using this -
```cpp
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define v32 vector<int>
#define MAX 30000
void shuffle(v32 &arr, int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main()
{
    char x[] = "out00.txt";

    freopen(x, "w", stdout);

    srand(time(NULL));
    int temp = (rand() + 20000) % MAX;
    cout << temp << "\n";
    v32 vec1(temp);
    v32 vec2(temp);

    for (int i = 0; i < temp; i++)
    {
        vec1[i] = i + 1;
        vec2[i] = i + 1;
    }
    shuffle(vec1, temp);
    shuffle(vec2, temp);
    for (int i = 0; i < temp; i++)
    {
        cout << vec1[i] << " " << vec2[i] << endl;
    }

    return (0);
}
```

Solution in C++ - 
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
```


Link for Polygon Problem - 

[Polygon Link](https://polygon.codeforces.com/p3zgUTF/whitedevil/main)

