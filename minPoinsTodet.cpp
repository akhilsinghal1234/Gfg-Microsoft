#include<bits/stdc++.h>
using namespace std;

bool ifvalid(int i, int j, int m, int n){
    if(i < 0 || i > n || j < 0 || j > m)
        return false;
    return true;
}

int minPoints(vector<vector<int> > &mat, int i, int j){
    int n = mat.size()-1, m = mat[0].size()-1;
    if(i == n && j == m)
        return mat[n][m];

    int c1 = INT_MAX, c2 = INT_MAX;
    if(ifvalid(i+1, j, m, n))
        c1 = mat[i][j]+minPoints(mat, i+1, j);
    if(ifvalid(i, j+1, m, n))
        c2 = mat[i][j]+minPoints(mat, i, j+1);
    int to_ret = 0;
    if(c1 < 0 && c2 < 0)
        to_ret = max(c1, c2);
    if(c1 < 0 && c2 > 0 && abs(c1) < c2)
        to_ret = c1;
    if(c1 < 0 && c2 > 0 && abs(c1) >= c2)
        to_ret =  c2;
    if(c1 > 0 && c2 < 0 && abs(c2) < c1)
        to_ret =  c2;
    if(c1 > 0 && c2 < 0 && abs(c2) >= c1)
        to_ret =  c1;
    if(c1 > 0 && c2 > 0)
        to_ret = 0;
    if(mat[i][j] < 0 && to_ret > mat[i][j])
        to_ret = mat[i][j];
    cout << mat[i][j] << " " << c1 << " " << c2 << " " << to_ret << endl;
    return to_ret;
}

int main()
{
	int t;
    cin >> t;
    while(--t >= 0){
        int n, m, x;
        cin >> n >> m;
        vector<vector<int> > mat;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < m; j++){
                cin >> x;
                row.push_back(x);
            }
            mat.push_back(row);
        }
        int cost = 0;
        cost = minPoints(mat, 0, 0);
        if(cost < 0)
            cost = abs(cost)+1;
        cout << cost << endl;
    }
	return 0;
}