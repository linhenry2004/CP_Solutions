// https://cses.fi/problemset/task/1621

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<long long> num;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        num.insert(temp);
    }
    cout << num.size();
    return 0;
}