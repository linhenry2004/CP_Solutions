// https://codeforces.com/contest/1642/problem/A

#include <iostream>
#include <iomanip>
using namespace std;

bool parallel(int y1, int y2)
{
    return y1 == y2;
}

int main()
{
    cout << setprecision(9) << fixed;
    int numTest;
    int x1, y1, x2, y2, x3, y3;
    cin >> numTest;
    int array[numTest];
    for (int i = 0; i < numTest; i++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;
        if (parallel(y1, y2) && y3 < y1)
        {
            array[i] = abs(x2 - x1);
        }
        else if (parallel(y1, y3) && y2 < y1)
        {
            array[i] = abs(x3 - x1);
        }
        else if (parallel(y2, y3) && y1 < y2)
        {
            array[i] = abs(x3 - x2);
        }
        else
        {
            array[i] = 0;
        }
    }
    for (int i = 0; i < numTest; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}