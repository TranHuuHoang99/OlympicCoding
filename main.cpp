#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n = 0;
vector<pair<int,int>> lm;
vector<pair<int,int>> chance;
vector<pair<int,int>> no_chance;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    lm.assign(n, {0,0});
    int ret = 0;
    int length = 0;

    for(int i = 0; i < n; i++) {
        cin >> lm[i].first >> lm[i].second;
        if(lm[i].second > 0) {
            chance.push_back(lm[i]);
            ret += lm[i].first;
            length += lm[i].second;
        } else {
            no_chance.push_back(lm[i]);
        }
    }

    if(!no_chance.empty()) sort(no_chance.begin(), no_chance.end(), cmp);
    length -= (chance.size() - 1);


    int i = 0;
    while(length > 0) {
        ret += no_chance[i].first;
        length--;
        i++;

        if(i >= no_chance.size()) break;
    }

    cout << ret << endl;

    return 0;
}
