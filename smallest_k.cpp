#include <bits/stdc++.h>

using namespace std;

void smallestk(string s, int k){
    string newStr, result = "";
    int removed;
    while(k > 0){
        int minInd = 0;
        for(int i = 1; i <= k; i++){
            if(s[minInd] > s[i])
                minInd = i;
        }
        result += s[minInd];
        k = k - minInd;
        newStr = s.substr(minInd+1);
        cout << "after removal: " << newStr << " " << result << " " << k << endl;
        s = newStr;
        if(k == 0)
            result += newStr;
    }
    cout << "ans: " << result << endl;
}

int main(){
    int k;
    string s;
    cin >> s >> k;
    smallestk(s, k);
    return 0;
}