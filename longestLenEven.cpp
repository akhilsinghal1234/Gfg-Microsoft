#include<bits/stdc++.h>
using namespace std;

int even(string s){
    int dp[s.length()][s.length()];
    memset(dp, 0, sizeof(dp));
    int n = s.length(), end, maxlen = 0, mid;
    for(int i = 0; i < n; i++){
        dp[i][i] = s[i]-'0';
    }
    for(int l = 2; l <= n; l++){
        for(int start = 0; start <= n-l; start++){
            end = start+l-1;
            mid = l/2;
            dp[start][end] = dp[start][end-mid] + dp[end-mid+1][end];
            if(l % 2 == 0 && dp[start][end-mid] == dp[end-mid+1][end])
                maxlen = max(l, maxlen);
        }
    }
    return maxlen;
}

int main()
{
    int t;
    cin >> t;
    while(--t >= 0){
        string s;
        cin >> s;
        int len = 0, l, r;
        len = even(s);
        cout << len << endl;
    }
	//code
	return 0;
}