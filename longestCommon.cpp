#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

bool mycmp(vector<int> &a, vector<int> &b){

    if(a[0] < b[0])
        return(a[0] < b[0]);
    else if(a[1] < b[1])
        return (a[1] < b[1]);
    else if(a[2] < b[2])
        return (a[2] < b[2]);
    else
        (a[0] < b[0]);
}

void lcs(string s1, string s2){
    int dp[s1.length()+1][s2.length()+1];
    memset(dp, 0, sizeof(dp));
    int len = 1;
    for(int i = 1; i < s1.length()+1; i++){
        for(int j = 1; j < s2.length()+1; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            len = max(dp[i][j], len);
        }
    }
    cout << len << endl;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, req;
        cin >> n >> req;
        string s1, s2;
        cin >> s1 >> s2;
        lcs(s1, s2);
    }
    return 0;
}

