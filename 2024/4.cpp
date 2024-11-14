// 수정전 로봇청소기 1회 사용 시작시간과 종료시간을 이용하여 요금을 계산한 코드

#include <iostream>
using namespace std;

char start_time[10];
char end_time[10];

void InputData(void)
{
	cin >> start_time;
	cin >> end_time;
}

int ConvertInt(char * t)
{
	return (t[0] - '0') * 10 + (t[1] - '0');
}

int ComputeTime(void)
{
	int s = ConvertInt(start_time) * 60 + ConvertInt(start_time + 3);
	int e = ConvertInt(end_time) * 60 + ConvertInt(end_time + 3);

	return (e - s);
}

int Solve(void)
{
	int p;
	int t = ComputeTime();
	if (t <= 10) return 300;
	if (t <= 30) return 500;
	int temp = t - 30;
	if (temp % 10 == 0) {
		temp /= 10;
	} else {
		temp /= 10;
		temp++;
	}
	p = 500 + temp * 300;
	p = p > 30000 ? 30000 : p;

	return p;
}

void OutputData(int sol)
{
	cout << sol;
}

int main(void)
{
	int sol = -1;
	InputData();// 입력

	sol = Solve();

	OutputData(sol);// 출력

	return 0;
}

