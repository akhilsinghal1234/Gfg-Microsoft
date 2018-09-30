#include<bits/stdc++.h>
using namespace std;

int x[] = {1,0,-1,0,1,1,-1,-1};
int y[] = {0,1,0,-1,1,-1,1,-1};

bool isSafe(int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void region(vector<vector<int> > &mat){
    int n = mat.size(), m = mat[0].size(), max_l = 0, length = 1;
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            length = 0;
            if(mat[i][j] == 1 && visited[i][j] == false){
                stack<pair<int, int> > st;
                st.push(make_pair(i, j));
                while(st.empty() != true){
                    pair<int, int> p = st.top();
                    st.pop();
                    if(!visited[p.first][p.second])
                        length++;
                    visited[p.first][p.second] = true;
                    for(int k = 0; k < 8; k++){
                        if(isSafe(p.first+x[k], p.second+y[k], n, m) && visited[p.first+x[k]][p.second+y[k]] == false && mat[p.first+x[k]][p.second+y[k]] == 1)
                            st.push(make_pair(p.first+x[k], p.second+y[k]));
                    }
                }
            }
            max_l = max(max_l, length);
        }
    cout << max_l << endl;      
}

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
        region(mat);
    }
	return 0;
}