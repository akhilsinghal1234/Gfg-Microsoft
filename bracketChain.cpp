#include<bits/stdc++.h>
using namespace std;

void bracket(int i, int j, string &s){
    if(i > j)
        return;
    string res;
    if(i == j)
        return;
    int count = 0, ind = i;
    for(int k = 0; k < s.length(); k++){

        if(isalpha(s[k]))
            count++;

        if(count == i){
            res += '(';
            ind = k+1;
            res += s[k];
            break;
        }
        res += s[k];
    }
    count = 0;
    for(int k = 0; k < s.length(); k++){
        if(isalpha(s[k]))
            count++;

        if(k >= ind)
            res += s[k];

        if(count == j){
            res += ')';
            count += 1;
        }
    }
    s = res;
}

vector<vector<int> > chain(vector<int> v, int n){
    vector<vector<int> > dp(n, vector<int> (n, 0));
    // int dp[n][n];
    // memset(dp, 0 ,sizeof(dp));
    
    int minv, last, val;
    for(int len = 2; len <= n-1; len++)
        for(int start = 1; start <= n-len; start++){
            minv = INT_MAX;
            last = start + len - 1;
            if(len == 2)
                dp[start][last] = v[start-1]*v[start]*v[start+1];
            else{
                for(int k = start; k < last; k++){
                    val = v[start-1]*v[k]*v[last] + dp[start][k] + dp[k+1][last];
                    minv = min(val, minv);
                }
                dp[start][last] = minv;
            }
        }
    return dp;
}

void brackets(string &s, vector<int> v, vector<vector<int> > dp, int i, int j){
    if(i == j)
        return;
    bracket(i, j, s);
    cout << s << endl;
    if(i+1 == j)
        return;
    for(int k = i; k < j; k++)
        if(dp[i][j] == v[i-1]*v[k]*v[j] + dp[i][k] + dp[k+1][j]){
            brackets(s, v, dp, i, k);
            brackets(s, v, dp, k+1, j);
        }
}

int main()
 {
    int t, n, x;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> x;
            v[i] = x;
        }
        string s;
        for(int i = 0; i < n-1; i++)
            s += char('A'+i);
        unordered_map<string, int> memo;
        vector<vector<int> > dp = chain(v, n);
        brackets(s, v, dp, 1, n-1);
        cout << s << endl;
    }
	//code
	return 0;
}

// ((A(B(C(D(E(F(G(H(IJ)))))))))((KL)M))
// ((A(B(C(D(E(F(G(HI))))))))((((JK)L)M)N))