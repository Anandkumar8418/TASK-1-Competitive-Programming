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
    int temp =(rand()+2)%MAX;
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
