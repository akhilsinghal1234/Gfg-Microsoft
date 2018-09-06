// #include <iostream>
// #include <vector>
// #include <climits>
// #include <string>

#include <bits/stdc++.h>

using namespace std;

int value(string s1, int n) {
    int chars[26];
    priority_queue<int> pq;
    memset(chars, 0, sizeof(chars));
    for(int i = 0; s1[i]; i++){
        chars[s1[i]-'a']++;
    }
    for(int i = 0; i < 26; i++)
        if(chars[i])
            pq.push(chars[i]);
    int j = 0, freq, ans = 0;

    while(j < n && pq.empty() == false){
        freq = pq.top();
        pq.pop();
        if(freq-1 > 0)
            pq.push(freq-1);
        j++;
    }
    while(pq.empty() != true){
        ans += pq.top()*pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    int t, n;
    cin >> t;
    while(--t >= 0){
        string s1;
        cin >> s1 >> n;
        cout << value(s1, n) << endl;
    }
    return 0;
}

