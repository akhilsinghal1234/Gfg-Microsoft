#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};

struct pos{
    int i;
    int j;
};

bool isSafe(int a, int b, int r, int c){
    if(a >= 0 && b >= 0 && a < r && b < c)
        return true;
    return false;
}

bool unvisited(vector<pair<int, int> > &visited, int i, int j){
    pair<int, int> p = make_pair(i,j);
    if(find(visited.begin(), visited.end(), p) == visited.end())
        return true;
    return false;
}

void rot(vector<vector<int> > mat, int r, int c){
    vector<pair<int, int> > visited;
    queue<pair<pos, int> > q;
    pos start;
    int rotten = 0, to_rot = 0, time_taken = 0;
    for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                if(mat[i][j] == 2){
                    start.i = i;
                    start.j = j;
                    q.push(make_pair(start, 0));
                }
                if(mat[i][j] == 1)
                    to_rot++;
            }
    while(to_rot != rotten && q.empty() == false){
        pos t = q.front().first;
        int time_ = q.front().second;
        q.pop();
        int i = t.i, j = t.j, a, b;
        visited.push_back(make_pair(i, j));
        for(int k = 0; k < 4; k++){
            i = t.i+x[k];
            j = t.j+y[k];
            if(isSafe(i,j,r,c) && mat[i][j] == 1 && unvisited(visited, i,j)){
                pos temp;
                temp.i = i;
                temp.j = j;
                q.push(make_pair(temp, time_+1));
                time_taken = max(time_+1, time_taken);
                mat[i][j] = 2;
                rotten++;
            }
        }
    }
    cout << rotten << " " << to_rot << endl;
    // if(q.empty() == true)
    //     cout << "empty:" << endl;
    if(to_rot != rotten)
        cout << "-1" << endl;
    else
        cout << time_taken << endl;
}

int main() {
	int t;
    cin >> t;
    while(--t >= 0){
        int r, c, x;
        cin >> r >> c;
        vector<int> row;
        vector<vector<int> > mat;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> x;
                row.push_back(x);
            }
            mat.push_back(row);
            row.clear();
        }
        rot(mat, r,c );
    }
	return 0;
}