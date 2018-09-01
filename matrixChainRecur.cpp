#include <bits/stdc++.h>
// #include <vector>
using namespace std;

int multc(vector<int> v, int s, int e){
    if(s >= e)
        return 0;
    int min_val = INT_MAX;
    int value = 0;
    for(int k = s; k < e; k++){
        value =  multc(v, s, k) + multc(v, k+1, e) + v[s-1]*v[k]*v[e];

        min_val = min(value, min_val);
    }
    return min_val; 
}

int main() {
    int t, n, x;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        if(n < 3)
        {
            cout << "0" << endl;
            continue;
        }
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        cout << multc(v, 1, v.size()-1)<<endl;
    }
	return 0;
}