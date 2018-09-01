#include <bits/stdc++.h>
// #include <vector>
using namespace std;

/*
 correct one needs to consider the cases like 1 2 4 3 2 4/ 1 1 2 2 2 3 3
 as LIS cannot ensure that integers can be squeezed between two increasing numbers.
*/

void convert(vector<int> v){
    vector<int> lis(v.size(), 1);
    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && lis[i] < lis[j]+1) 
                lis[i] = lis[j]+1;
        }//&& (i-j) <= (v[i]-v[j])
    }
    int max_lis = 0;
    for(int i = 0; i < v.size(); i++)
        max_lis = max(max_lis, lis[i]);
    cout << v.size() - max_lis;
    cout << endl;
}

int main() {
    int t, n, x;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        convert(v);
    }
	return 0;
}