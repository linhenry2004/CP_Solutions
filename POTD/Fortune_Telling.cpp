// https://codeforces.com/contest/1634/problem/B

#include <iostream>
using namespace std;

int main()
{
    int numCases, a;
    long long sum, ans;
    cin >> numCases;
    for (int i = 0; i < numCases; i++)
    {
        cin >> a >> sum >> ans;
        long long x;
        for (int j = 0; j < a; j++)
        {
            cin >> x;
            sum += x;
        }
        bool same = (ans % 2 == sum % 2);
        if (same)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
    return 0;
}