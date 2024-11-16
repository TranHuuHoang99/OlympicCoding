#include <bits/stdc++.h>
#define ll long long

using namespace std;

char start_time[10];
char end_time[10];

int convert(char *t) {
	int ret = (int)(t[0]-'0') * 10 + int(t[1]-'0');
	return ret;
}

void solve(void) {
	cin >> start_time;
	cin >> end_time;
	int temp_s = convert(start_time);
	int temp_e = convert(end_time);
	if (temp_s > temp_e) temp_e += 24; 
	int hour_s = temp_s * 60;
	int hour_e = temp_e * 60;
	int minute_s = convert(start_time+3);
	int minute_e = convert(end_time+3);
	int total = hour_e + minute_e - hour_s - minute_s;
	if (total <= 10) {
		cout << 300 << endl;
		return;
	}
	if (total <= 30) {
		cout << 500 << endl;
		return;
	}
	total -= 30;
	total = total % 10 == 0 ? total/10 : total/10+1;
	int ret = 500 + total * 300;
	ret = ret > 30000 ? 30000 : ret;
	cout << ret << endl;
}
  
int32_t main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	solve();
	
    return 0;
}



