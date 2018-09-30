#include <bits/stdc++.h>

using namespace std;

bool interleaved(string x, int i, string y, int j, string xy, int k) {
    if(i == j && i == k && i == -1)
        return true;
    if(k == -1)
        return false;
    if(xy[k] != x[i] && xy[k] != y[j])
        return false;
    if(xy[k] == x[i] && xy[k] == y[j])
        return interleaved(x, i-1, y, j, xy, k-1) || interleaved(x, i, y, j-1, xy, k-1);
    else if(xy[k] == x[i])
        return interleaved(x, i-1, y, j, xy, k-1);
    else
        return interleaved(x, i, y, j-1, xy, k-1);
}

bool interleaved(string x, string y, string xy) {
    bool dp[x.length()+1][y.length()+1][xy.length()+1];
    memset(dp, false, sizeof(dp));
    for(int k = 0; k < xy.length()+1; k++){
        for(int j = 0; j < y.length()+1; j++){
            for(int i = 0; i < x.length()+1; i++){
                if(i == j && i == k && i == 0)
                    dp[i][j][k] = true;
                else if(k == 0)
                    dp[i][j][k] = false;
                else if(xy[k-1] != x[i-1] && xy[k-1] != y[j-1])
                    dp[i][j][k] = false;
                else if(xy[k-1] == x[i-1] && xy[k-1] == y[j-1])
                    dp[i][j][k] = dp[i-1][j][k-1] || dp[i][j-1][k-1];
                else if(xy[k-1] == x[i-1])
                    dp[i][j][k] = dp[i-1][j][k-1];
                else
                    dp[i][j][k] = dp[i][j-1][k-1];
            }
        }
    }
    return dp[x.length()][y.length()][xy.length()];
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        string x, y, xy;
        cin >> x >> y >> xy;
        // cout << interleaved(x,x.length()-1, y, y.length()-1, xy, xy.length()-1) <<endl;
        cout << interleaved(x,y,xy) << endl;
    }
    return 0;
}

