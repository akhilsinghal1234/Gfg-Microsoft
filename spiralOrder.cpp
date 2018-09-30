#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin >> t;
    while(--t >= 0){
        int n, m, x;
        cin >> n >> m;
        int mat[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cin >> x;
                mat[i][j] = x;
            }
        int r_s = 0, r_e = n-1, c_s = 0, c_e = m-1;
        while(r_s <= r_e && c_s <= c_e){
            if(r_s <= r_e)
            for(int i = c_s; i <= c_e; i++)
                cout << mat[r_s][i] << " ";
            r_s++;
            if(c_s <= c_e)
            for(int j = r_s; j <= r_e; j++)
                cout << mat[j][c_e] << " ";
            c_e--;

            if(r_s <= r_e)
            for(int i = c_e; i >= c_s; i--)
                cout << mat[r_e][i] << " ";
            r_e--;
            if(c_s <= c_e)
            for(int j = r_e; j >= r_s; j--)
                cout << mat[j][c_s] << " ";
            c_s++;
        }
        cout << endl;
    }
	//code
	return 0;
}
