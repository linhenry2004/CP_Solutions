// https://cses.fi/problemset/task/1621

#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    list<long long> result;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (result.back() != arr[i])
        {
            result.push_back(arr[i]);
        }
    }
    cout << result.size() << endl;
    return 0;
}