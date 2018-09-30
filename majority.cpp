#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void majority(vector<int> v){
    int maj = INT_MAX, count = 0, cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == maj)
            count++;
        else if(count == 0){
            maj = v[i];
            count = 1;
        }
        else
            count--;
    }
    for(int i = 0; i < v.size(); i++)
        if(v[i] == maj)
            cnt++;
    if(v.size()%2 == 0 && cnt > (v.size()/2))
        cout << maj << endl;
    else if(v.size()%2 != 0 && cnt >= (v.size()+1)/2)
        cout << maj << endl;
    else
        cout << "NO Majority Element" << endl;
    // return INT_MAX;
}

int main() {
	int t;
    cin >> t;
    while(--t >= 0){
        int n, x;
        cin >> n;
        vector<int> v;
        while(--n >= 0){
            cin >> x;
            v.push_back(x);
        }
        majority(v);
    }
	return 0;
}