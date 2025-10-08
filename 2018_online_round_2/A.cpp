/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2025-10-07 08:49:56 
************************************************************************** 
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findFullHouse(vector<int> cards) {
 	int ret = 0;
 	while (true) {
 	 	if (cards[3] > 0) {
 	 	 	cards[3]--;
 	 	} else if (cards[4] > 0) {
 	 	 	cards[4]--;
 	 	 	cards[1]++;
 	 	} else {
 	 	 	break;
 	 	}
 	 	if (cards[2] > 0) {
 	 	 	cards[2]--;
 	 	} else if (cards[3] > 0) {
 	 	 	cards[3]--;
 	 	 	cards[1]++;
 	 	} else if (cards[4] > 0) {
 	 	 	cards[4]--;
 	 	 	cards[2]++;
 	 	} else {
 	 	 	break;
 	 	}
 	 	ret++;
 	}
 	return ret;
}

int minFullHouse(int remove_numb, int remv, vector<int> cards) {
	if (remove_numb == 0) return findFullHouse(cards);
 	if (remove_numb < 0 || remv < 1) return 8;
 	int min_val = 8;
 	for (int i = 0; i <= cards[4]; i++) {
 	 	cards[4] -= i;
 	 	cards[4-remv] += i;
 	 	min_val = min(min_val, minFullHouse(remove_numb - i*remv, remv-1, cards));
 	 	cards[4] += i;
 	 	cards[4-remv] -= i;
 	}
 	return min_val;
}

void solve(void) {
 	int remove_numb;
 	cin >> remove_numb;
 	int remain = 52 - remove_numb;
 	int max_val = min(8, remain/5);
 	vector<int> cards = {0,0,0,0,13};
 	int min_val = minFullHouse(remove_numb, 4, cards);
 	cout << min_val << ' ' << max_val << endl; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

