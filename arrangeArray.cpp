#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void arrange(vector<int>& array) {
    vector<int> neg, pos;
    for(int i = 0; i < array.size(); i++)
        if(array[i] < 0)
            neg.push_back(array[i]);
        else
            pos.push_back(array[i]);
    for(int i = 0; i < neg.size(); i++)
        array[i] = neg[i];
    for(int i = 0; i < pos.size(); i++)
        array[i+neg.size()] = pos[i];

    for(int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
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
        arrange(v);
    }
    return 0;
}

