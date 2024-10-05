#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve(void) {
	string str;
	int k;
	cin >> str >> k;
	
	string ret;
	string sub_str;
	int seq = 1;
	for (int i = 0; i < str.size(); i++) {
		if (sub_str.size() < k) {
			sub_str += str[i];
		} else {
			string temp;
			for (int j = 0; j < sub_str.size(); j++) {
				char c = sub_str[j] - 'a';
				c += (26 + k * seq);
				c %= 26;
				temp += c + 'a';
			}
			ret += temp;
			sub_str.clear();
			sub_str += str[i];
			seq *= -1;
		}
	}

	if (!sub_str.empty() && sub_str.size() < k) {
		ret += sub_str;
	} else {
		string temp;
		for (int i = 0; i < sub_str.size(); i++) {
			char c = sub_str[i] - 'a';
			c += 26 + k * seq;
			c %= 26;
			temp += c + 'a';
		}
		ret += temp;
	}

	cout << ret << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
