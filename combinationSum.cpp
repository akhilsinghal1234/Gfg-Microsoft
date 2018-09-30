#include <bits/stdc++.h>

using namespace std;

void combinationSum(set<vector<int> > &s, vector<int> v, vector<int> temp, int ind, int sum){
    if(ind < -1 || sum < 0)
        return;
    if(sum == 0){
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }
    vector<int> t = temp;
    t.push_back(v[ind]);
    combinationSum(s, v, temp, ind-1, sum);
    combinationSum(s, v, t, ind-1, sum-v[ind]);
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, sum, l, w, h;
        int x, i = 0, j = 0;
        cin >> n;
        vector<int> v, temp;
        while(i < n){
            cin >> h;
            v.push_back(h);
            i++;
        }
        set<vector<int> > s;
        cin >> sum;
        combinationSum(s, v, temp, v.size()-1, sum);
        if(s.size() == 0){
            cout << "Empty" << endl;
            continue;
        }
        for(auto it = s.begin(); it != s.end(); it++){
            temp = *it;
            cout << "(";
            for(int j = 0; j < temp.size()-1; j++)
                cout << temp[j] << " ";
            cout << temp[temp.size()-1];
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}

