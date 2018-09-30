#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void transpose(vector<vector<int> >& mat, int r, int c){
    for(int i = 0; i < r; i++)
        for(int j = i; j < c; j++)
            swap(mat[i][j], mat[j][i]);
}

void rotate(vector<vector<int> >& mat, int r, int c) {
    transpose(mat, r, c);
    for (int i = 0; i < c; i++)
        for (int j = 0, k = c - 1; j < k; j++, k--)
            swap(mat[j][i], mat[k][i]);


    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, req;
        cin >> n;
        int r = n, c = n;
        vector<vector<int> > mat;
        for(int i = 0; i < r; i++){
            vector<int> row;
            for(int j = 0; j < c; j++){
                cin >> x;
                row.push_back(x);
            }
            mat.push_back(row);
        }
        rotate(mat, mat.size(), c);
    }
    return 0;
}

