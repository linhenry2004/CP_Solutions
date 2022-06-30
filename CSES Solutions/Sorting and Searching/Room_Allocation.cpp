#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i].first.first >> customers[i].first.second;
        customers[i].second = i;
    }
    sort(customers.begin(), customers.end());

    vector<int> rooms(n, -1);
    int id = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            rooms[customers[i].second] = id++;
            pq.push(make_pair(customers[i].first.second, id - 1));
        } else {
            if (pq.top().first < customers[i].first.first) {
                rooms[customers[i].second] = pq.top().second;
                int x = pq.top().second;
                pq.pop();
                pq.push(make_pair(customers[i].first.second, x));
            } else {
                rooms[customers[i].second] = id++;
                pq.push(make_pair(customers[i].first.second, id - 1));
            }
        }
    }

    cout << id - 1 << endl;
    for (auto room : rooms) {
        cout << room << " ";
    }
    cout << endl;
    return 0;
}