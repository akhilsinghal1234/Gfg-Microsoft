#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int multc(vector<int> v){
    int dp[v.size()][v.size()];
    for(int i = 1; i < v.size(); i++)
        dp[i][i] = 0;
        
    int last;
    for(int i = 2; i < v.size(); i++){
        for(int start = 1; start < v.size()-i+1; start++){
            last = start+i-1;
            dp[start][last] = INT_MAX;
            for(int k = start; k < last; k++){
                dp[start][last] = min(dp[start][last], v[start-1]*v[k]*v[last] + dp[start][k] + dp[k+1][last]);
            }
        }
    }
    return dp[1][v.size()-1];
}

int main() {
    int t, n, x;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        if(n < 3)
        {
            cout << "0" << endl;
            continue;
        }
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        cout << multc(v) << endl;
    }
	return 0;
}