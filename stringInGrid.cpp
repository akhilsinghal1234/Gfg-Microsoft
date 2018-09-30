#include<bits/stdc++.h>
using namespace std;

int x[] = {0,1,0,-1,1,-1,1,-1};
int y[] = {1,0,-1,0,1,-1,-1,1};

bool safe(int i, int j, int n, int m){
    if(i < 0 || i > n || j < 0 || j > m)
        return false;
    return true;
}

bool found(vector<vector<char> > &mat, string s, int ind, int r, int c, int dir){
    if(ind == s.size()){
        return true;
    }
        // return;
    int i = dir;
    if(safe(r+x[i], c+y[i], mat.size()-1, mat[0].size()-1) && mat[r+x[i]][c+y[i]] == s[ind])
        if(found(mat, s, ind+1, r+x[i], c+y[i],dir))
            return true;
        
    return false;
}

void search(vector<vector<char> > mat, string str, int r, int c){
    string s = str;
    vector<pair<int, int> > ans;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            for(int dir = 0; dir < 8; dir++)
                if(mat[i][j] == s[0]){
                    if(found(mat, s, 1, i, j, dir))
                        ans.push_back(make_pair(i, j));
                }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second<<", ";
    }
    if(ans.size() == 0)
        cout << "-1";
    cout << endl;
}

int main()
{
	int t;
    cin >> t;
    while(--t >= 0){
        int n, r,c;
        char x;
        string str;
        cin >> r >> c;
        vector<vector<char> > mat;
        for(int i = 0; i < r; i++){
            vector<char> row;
            for(int j = 0; j < c; j++){
                cin >> x;
                row.push_back(x);
            }
            mat.push_back(row);
        }
        cin >> str;
        search(mat, str, r, c);
    }
	return 0;
}