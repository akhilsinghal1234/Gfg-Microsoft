#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <queue>

using namespace std;

void nonRepeat(vector<char>& array) {
    map<char, int> mp;
    queue<char> q;
    for(int j = 0; j < array.size(); j++){
        char rep = '1';
        mp[array[j]]++;
        if(mp[array[j]] == 1)
            q.push(array[j]);
        while(!q.empty() && mp[q.front()] > 1)
            q.pop();
        if(!q.empty())
            rep = q.front();
            
        if(rep == '1')
            cout << "-1" << " ";
        else
            cout << rep<< " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, sum;
        char x;
        cin >> n;
        vector<char> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        nonRepeat(v);
    }
    return 0;
}

