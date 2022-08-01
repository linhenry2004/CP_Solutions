#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7;
int visited[maxn];
int prv[maxn];
vector<string> ans;

int get_enc (vector<int> &v) {
	int res = 0;
	for (int i = 0; i < v.size(); ++i) {
		res *= 3;
		res += v[i];
	}
	return res;
}

vector<int> get_vector (int x, int len) {
	vector<int> v(len);
	for (int i = 0; i < len; i++) {
		v[len - i - 1] = x % 3;
		x /= 3;
	}
	return v;
}

int pow (int a, int b) {
	int res = 1;
	for (int i = 0; i < b; ++i) {
		res *= a;
	}
	return res;
}

int f (int total) {
	if(total <= 2) {
		cout << "FAIL" << endl;
		return 0;
	}

	int chars = total - 2;
	vector<int> v(total);
	vector<int> que;
	for (int zeros = 0; zeros <= chars; zeros++) {
		for (int e_pos = 0; e_pos + 1 < total; e_pos++) {
			int c_pos = 0;
			for(int j = 0; j < total; j++) {
				if (j == e_pos || j == e_pos + 1) {
					v[j] = 2;
				} else {
					if (c_pos < zeros) {
						v[j] = 0;
					} else {
						v[j] = 1;
					}
					c_pos++;
				}
			}
			que.push_back(get_enc(v));
		}
	}
	memset(visited, -1, sizeof visited);
	for (int i = 0; i < que.size(); i++) {
		visited[que[i]] = 0;
		prv[que[i]] = que[i];
		vector<int> v = get_vector(que[i], total);
	}
	for (int i = 0; i < que.size(); i++) {
		vector<int> v = get_vector(que[i], total);
		int dist = visited[que[i]];
		int prev_enc = que[i];
		int em_pos = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] == 2) {
				em_pos = i;
				break;
			}
		}
		for (int i = 0; i + 1 < v.size(); i++) {
			if (v[i] != 2 && v[i+1] != 2) {
				swap(v[i], v[em_pos]);
				swap(v[i+1], v[em_pos+1]);
				int enc = get_enc(v);
				if (visited[enc] == -1) {
					prv[enc] = prev_enc;
					visited[enc] = dist+1;
					que.push_back(enc);
				}
				swap(v[i], v[em_pos]);
				swap(v[i+1], v[em_pos+1]);
			}
		}
	}
}
 
void move (string& str, int& a, int b) {
	swap(str[a], str[b]);
	swap(str[a+1], str[b+1]);
	ans.push_back(str);
	a = b;
}

int main() {
	int n;
	cin >> n;
	n *= 2;
	string s;
	cin >> s;
	if (n == 2) {
		cout << 0 << endl;
		return 0;
	}

	int aas = 0;
	int bbs = 0;
	int dots = -1;
	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];
		if (c == 'A') ++aas;
		if (c == 'B') ++bbs;
		if (c == '.' && dots == -1) dots = i;
	}
 
	int a = 0;
	int b = n - 1;
	
	while (true) {
		if (b - a+1 < 10) {
            break;
        }
		char t = (aas >= 4 ? 'A' : 'B');
		int i1 = (t == 'B' ? -1 : b + 1);
		if (t == 'A') {
			if (dots == a + 1) {
				move(s, dots, dots + 2);
				move(s, dots, a);
			} else if (dots >= a + 2) {
				move(s, dots, a);
			}
			for (int i = a; i <= b; i++) {
				if (s[i] == t) {
					if (t == 'A' && i < i1) i1 = i;
				}
			}	
			move(s, dots, i1);
			++a;
			--aas;
		}
		if(t == 'B') {
			if(dots == b-2) {
				move(s, dots, dots-2);
				move(s, dots, b-1);
			}
			else if(dots <= b-3) {
				move(s, dots, b-1);
			}
			for (int i = a; i <= b; ++i) {
				if (s[i] == t) {
					if (t == 'B' && i1 < i) i1 = i;
				}
			}	
			move(s, dots, i1-1);
			--b;
			--bbs;
		}
	}
	vector<int> v;
	for(int i = a; i <= b; ++i) {
		if(s[i] == 'A') v.push_back(0);
		if(s[i] == 'B') v.push_back(1);
		if(s[i] == '.') v.push_back(2);
	}
	f(b-a+1);
	int pos = get_enc(v);
	if(visited[pos] == -1) {
		cout<<-1<<'\n';
		return 0;
	}
	vector<int> states;
	while(1) {
		vector<int> v2 = get_vector(pos, b-a+1);
		int next_pos = prv[pos];
		if(next_pos == pos) break;
		states.push_back(next_pos);
		pos = next_pos;
	}
	for(int i = 0; i < states.size(); ++i) {
		string s2;
		for(int j = 0; j < a; ++j) s2.push_back('A');
		vector<int> v = get_vector(states[i], b-a+1);
		for(auto x: v) s2.push_back("AB."[x]);
		for(int j = b+1; j < n; ++j) s2.push_back('B');
		ans.push_back(s2);
	}
	cout<<ans.size()<<'\n';
	for(int i = 0; i < ans.size(); ++i) {
		cout<<ans[i]<<'\n';
	}
}