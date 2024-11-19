#include <bits/stdc++.h>
#define ll long long

using namespace std;

string str;
int n;
pair<int,int> moves[4] = {
	{0,1},
	{0,-1},
	{1,0},
	{-1,0}
};

void solve(void) {
	cin >> n;
	cin >> str;
	int ret = 0;
	set<pair<int,int>> v_node;
	set<pair<pair<int,int>, pair<int,int>>> v_edge;
	v_node.insert({0,0});
	int x = 0, y = 0;
	for (char c : str) {
		int ver = x + moves[c-'0'].first;
		int hor = y + moves[c-'0'].second;
		pair<pair<int,int>, pair<int,int>> a = {{x,y}, {ver,hor}};
		pair<pair<int,int>, pair<int,int>> b = {{ver,hor}, {x,y}};
		if (v_node.count({ver,hor}) && !v_edge.count(a)) ret++;
		v_edge.insert(a);
		v_edge.insert(b);
		v_node.insert({ver,hor});
		x = ver;
		y = hor;
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


