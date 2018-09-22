#include<bits/stdc++.h>
using namespace std;

int x[] = {0,1,0,-1,1,-1,1,-1};
int y[] = {1,0,-1,0,1,-1,-1,1};

bool safe(int i, int j, int n, int m){
    if(i < 0 || i > n || j < 0 || j > m)
        return false;
    return true;
}

bool found(vector<vector<char> > &mat, string s, int ind, vector<vector<bool> > &visited, int r, int c){
    if(ind == s.size())
        return true;
    visited[r][c] = true;
    for(int i = 0; i < 8; i++)
        if(safe(r+x[i], c+y[i], mat.size()-1, mat[0].size()-1) && mat[r+x[i]][c+y[i]] == s[ind] && !visited[r+x[i]][c+y[i]]){
            if(found(mat, s, ind+1, visited, r+x[i], c+y[i]))
                return true;
        }
        
    visited[r][c] = false;
    return false;
}

void boggle(vector<vector<char> > &mat, vector<string> dic, int r, int c){
    int count = 0;
    for(int i = 0; i < dic.size(); i++){
        string s = dic[i];
        bool once = false;
        vector<vector<bool> > visited, copy;
        vector<bool> row(false, c);
        for(int i = 0; i < r; i++)
            visited.push_back(row);
        copy = visited;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(mat[i][j] == s[0] && !once){
                    visited = copy;
                    if(found(mat, s, 1, visited, i, j)){
                        cout << s << " ";
                        once = true;
                        count++;
                    }
                }
    }
    if(count == 0)
        cout << "-1";
}

int main()
{
	int t;
    cin >> t;
    while(--t >= 0){
        int n, r,c;
        char x;
        cin >> n;
        vector<string> dic;
        string str;
        for(int i = 0; i < n; i++){
            cin >> str;
            dic.push_back(str);
        }
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
        sort(dic.begin(), dic.end());
        dic.erase(unique(dic.begin(), dic.end()), dic.end());
        boggle(mat, dic, r, c);
        cout << "\n";
    }
	return 0;
}