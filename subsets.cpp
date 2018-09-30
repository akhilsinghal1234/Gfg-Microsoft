#include <bits/stdc++.h>

using namespace std;

void combinationSum(set<vector<int> > &s, vector<int> v, vector<int> temp, int ind){
    if(ind < 0){
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }
    vector<int> t = temp;
    t.push_back(v[ind]);
    combinationSum(s, v, temp, ind-1);
    combinationSum(s, v, t, ind-1);
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
        sort(v.begin(), v.end());
        combinationSum(s, v, temp, v.size()-1);
        // sort(s.begin(), s.end());
        for(auto it = s.begin(); it != s.end(); it++){
            temp = *it;
            cout << "(";
            if(temp.size() == 0)
                goto label;
            for(int j = 0; j < temp.size()-1; j++)
                cout << temp[j] << " ";
            cout << temp[temp.size()-1];
            label:
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}

