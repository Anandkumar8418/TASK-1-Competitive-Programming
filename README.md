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
First Line of Input contains n  (1 <= n <= 8*10^4) - Number of people 

Next $n$ lines contains two numbers a and b (1 <= a <= 8*10^4 , 1 <= b <= 8*10^4 ) -
Where $ith$ line contains a_i which is the left sandals of ith person and b_i which is the right sandals of ith person.
```
Output - 
```
For each test Case, print the minimum number of swaps to give sandals back to their owners.
```
Generating test cases as txt files using this -
```cpp

// For generating edge testcases I manually set the temp to 80000,70000 etc.


#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define v32 vector<int>
#define MAX 80000
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
    int temp = (rand()+2)%MAX;
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


Link for Polygon Problem - 
```
https://polygon.codeforces.com/p3zgUTF/whitedevil/main
```
