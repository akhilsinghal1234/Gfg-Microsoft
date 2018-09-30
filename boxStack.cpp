#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

int mycomp(vector<int> a, vector<int> b){
    return a[0]*a[1]>b[0]*b[1];
}

void boxstack(vector<vector<int> > &v){
    for(int i = 0; i < v.size(); i+=3){
        int l = v[i][0], b = v[i][1], h = v[i][2];
        v[i+1].push_back(l);
        v[i+1].push_back(h);
        v[i+1].push_back(b);
        v[i+2].push_back(h);
        v[i+2].push_back(b);
        v[i+2].push_back(l);
    }

    sort(v.begin(), v.end(), mycomp);

    vector<int> lih(v.size(), 0);
    for(int i = 0; i < v.size(); i++)
        lih[i] = v[i][2];

    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[j][0] > v[i][0] && v[j][1] > v[i][1] || v[j][1] > v[i][0] && v[j][0] > v[i][1])
                lih[i] = max(lih[j]+v[i][2], lih[i]);
        }
    }
    int max_h = 0;
    for(int i = 0; i < v.size(); i++){
        // cout << lih[i] << " ";
        max_h = max(max_h, lih[i]);
    }
    // cout << endl;
    cout << max_h << endl;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, sum, l, w, h;
        int x, i = 0, j = 0;
        cin >> n;
        vector<vector<int> > v(n*3);
        while(i < n){
            vector<int> row;
            cin >> h;
            cin >> w;
            cin >> l;
            v[j].push_back(l);
            v[j].push_back(w);
            v[j].push_back(h);
            j += 3;
            i++;
        }
        boxstack(v);
    }
    return 0;
}

