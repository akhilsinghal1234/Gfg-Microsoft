#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int multc(vector<int> v){
    int dp[v.size()][v.size()];
    for(int i = 1; i < v.size(); i++)
        dp[i][i] = 0;
        
    int last;
    for(int i = 2; i < v.size(); i++){
        for(int j = 1; j < v.size()-i+1; j++){
            last = j+i-1;
            dp[j][last] = INT_MAX;
            for(int k = j; k < last; k++){
                dp[j][last] = min(dp[j][last], v[j-1]*v[k]*v[last] + dp[j][k] + dp[k+1][last]);
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