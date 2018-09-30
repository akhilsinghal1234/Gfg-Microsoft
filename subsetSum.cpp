#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int subSum(vector<int>& array, int sum) {
    int dp[array.size()+1][sum+1];
    for(int j = 0; j <= sum; j++)
        for(int i = 0; i <= array.size(); i++)
            dp[i][j] = 0;

    for(int i = 0; i <= array.size(); i++)
        dp[i][0] = 1;

    for(int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    dp[0][0] = 1;   

    if(sum == 0)
        return 0;
    
    for(int j = 1; j <= sum; j++){
        for(int i = 1; i <= array.size(); i++){
            if(j < array[i-1])
                dp[i][j] += dp[i-1][j];
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-array[i-1]];
            }
        }
    }
    return dp[array.size()][sum];
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, sum;
        cin >> n;
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        cin >> sum;
        cout << subSum(v, sum) << endl;
    }
    return 0;
}

