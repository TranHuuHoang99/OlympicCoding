#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node {
    map<char,pair<Node*, int>> next;
    Node() {}
};

int N, Q;
Node *root = new Node();
vector<int> res;

void make_node(string str) {
    Node *temp = root;

    for(auto c : str) {
        if(temp->next.find(c) == temp->next.end()) {
            temp->next[c].first = new Node();
        } 
        temp->next[c].second++;

        temp = temp->next[c].first;
    }
}

void solve(string str) {
    int ret = 0;
    Node *temp = root;

    for(auto c : str) {
        if(temp->next.find(c) != temp->next.end()) {    
            ret = temp->next[c].second;
            temp = temp->next[c].first;
        } else {
            ret = 0;
            break;
        }
    }

    res.push_back(ret);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef HOANG_DEBUG
    freopen("input.txt", "r", stdin);
#endif // HOANG_DEBUG   

    cin >> N >> Q;
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        make_node(temp);
    }

    for(int i = 0; i < Q; i++) {
        cin >> temp;
        solve(temp);
    }

    for(auto r : res) {
        cout << r << endl;
    }

    return 0;
}
