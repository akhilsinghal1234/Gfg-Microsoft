#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

int zero(vector<int>& array) {
    int count = 0;
    map<int, vector<int> > mp;
    int sum = 0;
    for(int j = 0; j < array.size(); j++){
        sum += array[j];
        if(sum == 0)
            count++;
        if(mp.find(sum) != mp.end()){
            count += mp[sum].size();
        }
        mp[sum].push_back(j);
    }  
    cout << count << endl;
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
        zero(v);
    }
    return 0;
}

