#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int dp[coins.size()][amount+1];
    for(int j = 0; j <= amount; j++)
        for(int i = 0; i < coins.size(); i++)
            dp[i][j] = 0;
    for(int i = 0; i < coins.size(); i++)
        dp[i][0] = 1;

    if(amount == 0)
        return 0;
    
    for(int j = 1; j <= amount; j++){
        for(int i = 0; i < coins.size(); i++){
            
            int x = (j-coins[i] >= 0) ? dp[i][j-coins[i]]:0;
            int y = (i > 0) ? dp[i-1][j] : 0;

            dp[i][j] = x+y;
        }
    }
    return dp[coins.size()-1][amount];
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, amount;
        cin >> n;
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        cin >> amount;
        cout << coinChange(v, amount);
    }
    return 0;
}

