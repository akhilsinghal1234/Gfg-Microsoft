#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int val[] = {1, 5, 10, 50, 100, 500, 1000};

int match(string s1, string s2) {
    int i = 0, j = 0;
    if(s1[0] == '^'){
        i++;
        while(i < s1.length() && j < s2.length()){
            if(s1[i] != s2[j])
                return 0;
            i++;
            j++;
        }
        return 1;
    }
    else if(s1[s1.length()-1] == '$'){
        i = s1.length()-2, j = s2.length()-1;
        while(i >= 0 && j >= 0){
            if(s1[i] != s2[j])
                return 0;
            i--;
            j--;
        }
        return 1;
    }
    else{
        if(strstr(s1.c_str(), s2.c_str()))
            return 1;
        return 0;
    }
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        string s1, s2;
        cin >> s1 >> s2;
        cout << match(s1, s2) << endl;
    }
    return 0;
}

