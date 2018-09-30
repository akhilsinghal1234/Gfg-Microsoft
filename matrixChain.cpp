#include<bits/stdc++.h>
using namespace std;

int chain(vector<int> v, int n){
    int dp[n][n];
    memset(dp, 0 ,sizeof(dp));
    
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
    return dp[1][n-1];
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
        unordered_map<string, int> memo;
        cout << chain(v, n) << endl;
    }
	//code
	return 0;
}
/*

int chain(unordered_map<string, int> &memo, vector<int> v, int i, int j){
    if(memo.find(s) != memo.end())
        return memo[s];
    if(i == j)
        return 0;
    if(i+1 == j){
        return v[i-1]*v[i]*v[i+1];
    }

    int ans, min_v = INT_MAX;
    for(int k = i; k < j; k++){
        ans = chain(memo, v, i, k) + chain(memo, v, k+1, j) + v[i-1]*v[k]*v[j];
        min_v = min(min_v, ans);
    }
    memo[s] = min_v;
    return min_v;
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
        unordered_map<string, int> memo;
        cout << chain(memo, v, 1, n) << endl;
    }
	//code
	return 0;
}

*/