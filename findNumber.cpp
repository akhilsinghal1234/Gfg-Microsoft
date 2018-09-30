#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

bool mycmp(vector<int> &a, vector<int> &b){

    if(a[0] < b[0])
        return(a[0] < b[0]);
    else if(a[1] < b[1])
        return (a[1] < b[1]);
    else if(a[2] < b[2])
        return (a[2] < b[2]);
    else
        (a[0] < b[0]);
}

void number(vector<int>& array) {
    int x = array[0];
    for(int i = 1; i < array.size(); i++){
        x = x^array[i];
    }

    int t = ~(x-1);
    t = x & t;
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < array.size(); i++){
        if(array[i] & t)
            xor1 = xor1^array[i];
        else
            xor2 = xor2^array[i];
    }
    cout << min(xor1, xor2) << " " << max(xor1, xor2) << endl; 
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int n, x, req;
        cin >> n;
        n = 2*(n+1);
        vector<int> v;
        while(n > 0){
            n -= 1;
            cin >> x;
            v.push_back(x);
        }
        number(v);
    }
    return 0;
}

