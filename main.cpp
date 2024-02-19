#include <bits/stdc++.h>
#include <memory>

using namespace std;

string solve(string str, string cmd, int cursor) {
    for(int i = 0; i < cmd.length(); i++) {
        if(cmd[i] == 'L') {
            if(cursor > 0) cursor--;
        } else if(cmd[i] == 'R') {
            if(cursor < str.length()) cursor++;
        } else if(cmd[i] == 'B') {
            if(str == " ") continue;
            if(cursor == 0) continue;
            int index = cursor > 0 ? cursor-1 : cursor;
            str.erase(str.begin() + index);
            if(cursor > 0) cursor--;
        } else {
            str.insert(str.begin()+cursor, cmd[i]);
            if(cursor < str.length()) cursor++;
        }
    }

    return str;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str = " ";
    string cmd = " ";

    cin >> str >> cmd;
    int cursor = str.length();

    cout << solve(str, cmd, cursor) << endl;

    return 0;
}

