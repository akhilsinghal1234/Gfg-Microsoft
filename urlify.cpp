#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

void urlify(char str[], int l) {
    int spaces = 0, newl = 0;
    for(int i = 0; str[i]; i++)
        if(str[i]==' ')
            spaces++;
    newl = l + spaces*2;
    int j = newl-1, i = l-1;
    while(j >= 0){
        if(str[i] != ' '){
            str[j] = str[i];
            j -= 1;
            i -= 1;
        }
        else{
            str[j] = '0';
            str[j-1] = '2';
            str[j-2] = '%';
            j -= 3;
            i -= 1;
        }
    }
    cout << str << endl;
}

int main(){
    int t, ex;
    cin >> t;
    cin.ignore();
    while(--t >= 0){
        char s[10000];
        fgets(s, sizeof(s), stdin);
        cin >> ex;
        cin.ignore();
        int l = 0;
        for(l = 0; s[l]; l++);
        urlify(s, l);
    }
    return 0;
}

