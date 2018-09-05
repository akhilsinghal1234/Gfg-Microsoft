#include <iostream>
#include <vector>
#include <climits>
#include <map>
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

void sum(vector<int>& array, int req) {
    int size = array.size();
    map<int, vector<pair<int, int> > > mp;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            // if(i != j)
            mp[array[i]+array[j]].push_back(make_pair(i, j));
        }
    }

    vector<vector<int> > res;

    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size; j++)
            if(i != j){
            int s = req-(array[i]+array[j]);
            if(mp.find(s) != mp.end()){
                cout << req << " " << s << " " << array[i]+array[j] << endl;
                for(int k = 0; k < mp[s].size(); k++){
                    pair<int, int> p = mp[s][k];
                    if(!(p.first == i || p.second == j || p.second == i || p.first == j)){
                        vector<int> row(4);
                        row[0] = array[i];
                        row[1] = array[j];
                        row[2] = array[p.first];
                        row[3] = array[p.second];
                        res.push_back(row);
                    }
                }
            }
        }
    if(res.size() == 0){
        cout << "-1" << endl;
        return;
    }
    for(int j = 0; j < res.size(); j++)
        sort(res[j].begin(), res[j].end());

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    for(int j = 0; j < res.size(); j++){
        cout << res[j][0] << " " << res[j][1] << " " << res[j][2] << " " << res[j][3] << " " << "$";
    }
    cout << endl;
    // cout << res.size() << endl;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, req;
        cin >> n >> req;
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        sum(v, req);
    }
    return 0;
}

