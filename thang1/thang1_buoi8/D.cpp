/*
 ******************************************************************************************
 *      * AUTHOR : hoangprodn
 *      * CREATED: 02.12.2024 15:44:52
 ******************************************************************************************
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(void) {
	multiset<int> ms;
	int a;
	while (cin >> a) {
		bool flag = false;
	 	switch (a) {
	 	 	case 1: {
	 	 		int b;
	 	 		cin >> b;
	 	 		ms.insert(b);
	 	 		break;
	 	 	}
	 	 	case 2: {
	 	 		int b;
	 	 		cin >> b;
	 	 		ms.erase(b);
                break;
            }
			case 3: {
				if (ms.empty()) {
				 	cout << "empty" << endl;
				} else {
				 	cout << *ms.begin() << endl;
				}
				break;
			}
			case 4: {
				if (ms.empty()) {
				 	cout << "empty" << endl;
				} else {
				 	auto it = ms.end();
				 	--it;
				 	cout << *it << endl;
				}
				break;
			}
			case 5: {
				int b;
				cin >> b;
				if (ms.empty()) {
				 	cout << "empty" << endl;
				} else {
				 	auto it = ms.upper_bound(b);
				 	if (it == ms.end()) {
				 	 	cout << "no" << endl;
				 	} else {
				 	 	cout << *it << endl;
				 	}
				}
				break;
			}
			case 6: {
				int b;
				cin >> b;
				if (ms.empty()) {
				 	cout << "empty" << endl;
				} else {
				 	auto it = ms.lower_bound(b);
				 	if (it == ms.end()) {
						cout << "no" << endl;
				 	} else {
				 	 	cout << *it << endl;
				 	}
				}
				break;
			}
			case 7: {
				int b;
				cin >> b;
				if (ms.empty()) {
				 	cout << "empty" << endl;
				} else {
				 	auto it = ms.lower_bound(b);
				 	if (it == ms.end()) {
						auto temp_it = ms.end();
						--temp_it;
						if (*temp_it < b) {
						 	cout << *temp_it << endl;
						} else {
						 	cout << "no" << endl;
						}
				 	} else {
				 	 	if (it == ms.begin()) {
				 	 	 	cout << "no" << endl;
				 	 	} else {
				 	 		--it;
				 	 		cout << *it << endl;
				 	 	}
				 	}
				}
				break;
			}
			case 8: {
				int b;
				cin >> b;
				if (ms.empty()) {
                    cout << "empty" << endl;
                } else {
					auto it = ms.lower_bound(b);
					if (it == ms.end()) {
					 	auto temp_it = ms.end();
					 	--temp_it;
					 	if (*temp_it <= b) {
					 	 	cout << *temp_it << endl;
					 	} else {
					 	 	cout << "no" << endl;
					 	}
                 	} else {
                 	 	if (*it == b) {
                 	 	 	cout << *it << endl;
                 	 	} else {
                 	 	 	if (it == ms.begin()) {
                 	 	 	 	cout << "no" << endl;
                 	 	 	} else {
                 	 	 	 	--it;
                 	 	 	 	cout << *it << endl;
                 	 	 	}
                 	 	}
                 	}
                }
                break;
			}
			default: {
			 	flag = true;
			 	break;
			}
			if (flag) break;
	 	}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef HOANGPRODN_DEBUG
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif // HOANGPRODN_DEBUG
	
	solve();

	return 0;
}
