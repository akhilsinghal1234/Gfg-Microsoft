#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void binary(int num, string &s){
    if(num == 0)
        return;
    if(num%2)
        s = '1'+s;
    else
        s = '0'+s;
    binary(num/2, s);
}

int decimal(string s){
    int sum = 0, p = 0, i = s.length()-1;
    while(i >= 0){
        sum += (s[i]-'0')*pow(2,p);
        p++;
        i--;
    }
    return sum;
}

int replace(int n, int k) {
    string s;
    binary(n,s);
    // cout << s << endl;
    int len = s.length();
    // cout << s[k-1] << endl;
    if(s[k-1] == '0'){
        return n;
    }
    s[k-1] = '0';
    return decimal(s);
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        int s,k;
        cin >> s >> k;
        cout << replace(s, k) << endl;
    }
    return 0;
}

