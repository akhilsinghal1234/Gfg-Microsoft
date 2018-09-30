#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

int mycmp(int a, int b){
    return a>b;
}

void sort(vector<int> &v){
    int i = 0, j = v.size()-1;
    while(1){
        while(v[i]%2 != 0 && i < v.size())
            i++;
        while(v[j]%2 != 1 && j >= 0)
            j--;
        if(i >= v.size() || j < 0 || i > j)
            break;
        int t = v[i];
        v[i] = v[j];
        v[j] = t;
    }
    vector<int>::iterator it = v.begin();
    for(it; it!=v.end(); it++){
        if(*it%2 == 0){
            break;
        }
    }
    cout << *it << endl;
    sort(v.begin(), it, mycmp);
    sort(it, v.end());
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, sum;
        int x;
        cin >> n;
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        sort(v);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}

