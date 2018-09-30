#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int bitonic(vector<int>& array) {
    vector<int> lps(array.size(), 1), lds(array.size(), 1);
    for(int i = 1; i < array.size(); i++)
        for(int j = 0; j < i; j++)
            if(array[i] > array[j])
                lps[i] = max(lps[j]+1, lps[i]);

    for(int i = array.size()-2; i >= 0; i--)
        for(int j = array.size()-1; j > i; j--)
            if(array[i] > array[j])
                lds[i] = max(lds[j]+1, lds[i]);
    int max_len = 0;
    for(int i = 0; i < array.size(); i++)
        max_len = max(lps[i]+lds[i]-1, max_len);
    // cout << endl;
    return max_len;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, sum;
        cin >> n;
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        cout << bitonic(v) << endl;
    }
    return 0;
}

