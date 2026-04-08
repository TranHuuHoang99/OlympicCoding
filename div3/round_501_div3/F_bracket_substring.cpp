/*
**************************************************************************
  	author     : hoangprodn
  	email  	   : thhoang08091999@gmail.com
  	local time : 2026-04-08 21:02:39 
************************************************************************** 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
const int N = 210;
int n;
string str;
// call F[i][balance][len][status] is the total ways can get a valid bracket sequence
// when we have first i elements
// balance is the number open and close brackets can have
// when we open bracket -> the balance will increase 1 -> '(' -> += 1
// when we close bracket -> the balance will decrease 1 -> ')' -> -= 1
// len is the len of prefix str, and the len of suffix sequence that we are creating
// status is the state to determine whether we already included pattern bracket sequence or not
// THE ANSWER : the answer is F already filled 2*n character, balance is 0, the current matching between prefix and suffix 0 -> m, and already have pattern inside
int F[N][N][N][2];
// N is the len of the matching prefix, 2 is the last bracket -> '0' is open -> '1' is close
int len_prefix[N][2];
int pi[N];
void solve(void) {
 	cin >> n;
    cin >> str;
    int m = str.size();
    str = " " + str;
    int k = 0;
    for (int i = 2; i <= m; i++) {
     	while (k > 0 && str[k+1] != str[i]) {
			k = pi[k];
        }
        if (str[k+1] == str[i]) {
         	k = k+1;
        }
        pi[i] = k;
    }
	for (int i = 0; i <= m; i++) {
	 	for (int j = 0; j <= 1; j++) {
		 	char c = (j == 0) ? '(' : ')';
			if (i < m && str[i+1] == c) {
			 	len_prefix[i][j] = i + 1;
			} else {
			 	if (i == 0) {
                 	len_prefix[i][j] = 0;
                } else {
                 	len_prefix[i][j] = len_prefix[pi[i]][j];
                }
			}
		}
	}
	// create base state with 0 characters first, 0 nothing add to sequence, 0 len of pattern, don't have text sequence 
	F[0][0][0][0] = 1;
	for (int i = 0; i < 2*n; i++) {
		for (int balance = 0; balance <= n; balance++) {
			for (int len = 0; len <= m; len++) {
			 	for (int status = 0; status <= 1; status++) {
					if (F[i][balance][len][status] == 0) continue;
					// case add open bracket '('
					if (balance+1 <= n) {
					 	F[i+1][balance+1][len_prefix[len][0]][status|(len_prefix[len][0] == m)] = \
						(F[i+1][balance+1][len_prefix[len][0]][status|(len_prefix[len][0] == m)] % MOD +\
						F[i][balance][len][status] % MOD) % MOD;
					}
					// case add close bracket ')'
					if (balance-1 >= 0) {
					 	F[i+1][balance-1][len_prefix[len][1]][status|(len_prefix[len][1] == m)] = \
						(F[i+1][balance-1][len_prefix[len][1]][status|(len_prefix[len][1] == m)] % MOD +\
						F[i][balance][len][status] % MOD) % MOD;						
					}
				}
			}
	 	}		
	}
	int ret = 0;
	for (int i = 0; i <= m; i++) {
	 	ret = (ret % MOD + F[2*n][0][i][1] % MOD) % MOD;
	}
	cout << ret % MOD << endl;
}
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}


























