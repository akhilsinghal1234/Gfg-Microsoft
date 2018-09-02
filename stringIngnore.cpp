#include <iostream>
#include <string>
#include <map>
using namespace std;

void convert(string s){
    map<char, int> mp;
    string res;
    for(int i = 0; i < s.length(); i++){
        if(mp[tolower(s[i])] == 1){
            mp[tolower(s[i])] = 0;
        }
        else{
            res += s[i];
            mp[tolower(s[i])] = 1;
        }
    }
    cout << res << endl;
}

int main() {
	int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(--t >= 0){
        string str;
        getline(cin, str);
        convert(str);
    }
	return 0;
}