#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
    cin >> t;
    while(--t >= 0){
        int n, m, x, max_ones = 0, ans;
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
        for(int i = 0; i < n; i++){
            vector<int> r = mat[i];
            int ind = lower_bound(r.begin(), r.end(), 1) - r.begin();
            if(max_ones < m-ind){
                ans = i;
                max_ones = m-ind;
            }
        }
        cout << ans << endl;
    }
	return 0;
}