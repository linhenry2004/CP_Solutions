#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {

	pair<int, char> pair1(1, 'a'); // a pair stores two value of different type
	pair<int, char> pair2 = {1, 'a'}; // equivalent to above
	cout << pair1.first << ":" << pair1.second << endl; // accessing values in pair
	cout << "Is equal? " << (pair1 == pair2) << endl;
	pair1.first = 2;

	/* comparing pairs work by comparing the first value first, then the second */
	cout << "Is less? " << (pair2 < pair1) << endl;
	cout << endl;

	vector<int> vec1(5); // a vector of size 5
	vector<int> vec2(5, -1); // a vector of size 5, filled with -1
	vector<int> vec3 = {1, 2, 3, 4, 5}; // a vector with these values

	vector<pair<int, int>> vec =
	{
		{1, 2},
		{3, 3},
		{2, 1},
		{3, 2},
		{1, 2},
		{2, 2}
	};
	pair<int, int> p = {3, 1};
	vec.push_back(p);
	vec.push_back({1, 1});

	sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); i++) {
		pair<int, int> value = vec[i];
		auto also_value = vec[i]; // auto interprets the type (less typing)
		cout << value.first << ':' << value.second << ' ';
	}
	cout << endl;

	/* loop through values */
	for (pair<int, int> value: vec) {
		cout << value.first << ':' << value.second << ' ';
	}
	cout << endl;

	/* same */
	for (auto value: vec) {
		cout << value.first << ':' << value.second << ' ';
	}
	cout << endl << endl;

	set<string> s;
	s.insert("abc");
	s.insert("acb");
	s.insert("bca");
	s.insert("abc");
	s.insert("bac");
	s.insert("cab");
	s.insert("cba");
	cout << "Does abc exists? " << s.count("abc") << endl;
	cout << "Does zzz exists? " << s.count("zzz") << endl;

	/* loop through a set */
	for (auto x: s) cout << x << endl;
	cout << endl;

	/* std::map */
	map<char, int> mp;
	mp.insert({'a', 4});
	mp.insert({'c', 3});
	mp.insert({'f', 2});
	mp['b'] = 1; // another way
	mp['d'] = 0;

	mp['a']++; // modify an existing value
	mp.erase('c'); // remove

	cout << "Does key 'a' exist? " << mp.count('a') << endl;
	cout << "Does key 'c' exist? " << mp.count('c') << endl;
	cout << "Value of key 'a' = " << mp['a'] << endl;

	/* print the values, map are also sorted (by key, aka the first value) */
	for (pair<char, int> x: mp)
		cout << x.first << ": " << x.second << endl;
	cout << endl; 

	return 0;
}

/*
Output:
1:a
Is equal? 1
Is less? 1

1:1 1:2 1:2 2:1 2:2 3:1 3:2 3:3
1:1 1:2 1:2 2:1 2:2 3:1 3:2 3:3
1:1 1:2 1:2 2:1 2:2 3:1 3:2 3:3

Does abc exists? 1
Does zzz exists? 0
abc
acb
bac
bca
cab
cba

Does key 'a' exist? 1
Does key 'c' exist? 0
Value of key 'a' = 5
a: 5
b: 1
d: 0
f: 2

*/

//A stack pushes a new element to the top of the stack and also pops the element at the top. 
//A queue, dequeues removes an element from the top of the queue, ​but it inserts an element at the bottom.