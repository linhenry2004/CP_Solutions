#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);
}

int main () {
    int n;
    cin >> n;
    vector<pair<int, int>> movie(n);
    for (int i = 0; i < n; i++) {
        cin >> movie[i].first >> movie[i].second;
    }
    
    sort(movie.begin(), movie.end(), cmp);

    int end = -1;
    int movies = 0;
    for (int i = 0; i < n; i++) {
        if (movie[i].first >= end) {
            movies++;
            end = movie[i].second;
        }
    }
    cout << movies << endl;
    return 0;
}