#include <iostream>
#include <vector>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};   

bool isVowel(char c){
    for(int i = 0; i < 5; i++)
        if(vowels[i] == tolower(c))
            return true;
    return false;
}

void difficulty(vector<string> &v){
    int vow = 0, cons = 0, diff = 0, easy = 0;
    for(int i = 0; i < v.size(); i++){
        int j = 0, start = 0, vow = 0, cons = 0;
        while(j < v[i].size()){
            if(!isVowel(v[i][j])){
                cons++;
                start = j;
                j++;
                while(!isVowel(v[i][j]) && j < v[i].size()){
                    cons++;
                    j++;
                }
                if(j-start >= 4){
                    cons = v[i].length();
                    break;
                }
            }
            else if(isVowel(v[i][j])){
                vow++;
                j++;
            }
        }
        if(cons > vow)
            diff++;
        else   
            easy++;
    }
    cout << 5*diff+3*easy << endl;
}

int main() {
    int t;
    cin >> t;
    char buf[5];
    cin.getline(buf, 5);
    while(--t >= 0){
        vector<string> v;
        string str;
        getline(cin, str);
        stringstream ss;
        ss << str;
        string s;
        while(ss >> s){
            v.push_back(s);
        }
        difficulty(v);
    }
	return 0;
}