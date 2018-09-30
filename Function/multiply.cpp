#include <bits/stdc++.h>
using namespace std;

string addstrings(vector<string> row){
    string res = row[0], t2 = "";;
    for(int i = 1; i < row.size(); i++){
        string t1 = row[i];
        t2 += '0';

        int shift = i;
        while(shift > 0){
            t1 += '0';
            shift--;
        }
        
        while(t1.length() < res.length()){
            t1 = '0'+t1;
        }
        while(t1.length() > res.length()){
            res = '0'+res;
        }
        int s, c = 0, n, m;
        for(int j = t1.length()-1; j >= 0; j--){
            n = t1[j]-'0';
            m = res[j]-'0';
            s = (n+m)+c;
            c = s/10;
            s = s%10;
            res[j] = (char)(s+'0');
        }
        if(c!='0')
            res = (char)(c+'0')+res;
    }
    int n = 0;
    while(res[n] == '0')
        n++;
    res = res.substr(n, res.size());
    return res;
}

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = a;
}

int main(){
    int f1 = false, f2 = false;
    string s1, s2, res;
    cin >> s1 >> s2;
    if(s1[0] == '-'){
        s1 = s1.substr(1, s1.length());
        f1 = true;
    }
    if(s2[0] == '-'){
        s2 = s2.substr(1, s2.length());
        f2 = true;
    }
    vector<string> row;
    for(int i = s2.length()-1; i >= 0; i--){
        string str;
        int m = s2[i]-'0', c = 0, n, p;
        for(int j = s1.length()-1; j >= 0; j--){
            n = s1[j]-'0';
            p = n*m+c;
            c = p/10;
            p = p%10;
            str = (char)(p+'0')+str;
        }
        if(c!='0')
            str = (char)(c+'0')+str;
        
        row.push_back(str);
    }
    
    string res = addstrings(row);
    if(f1 && f2)
        cout << res << endl;
    else if(f1 || f2)
        cout << "-" << res << endl;
    else
        cout << res << endl;
    return 0;
}

/*

string addstrings(vector<string> row){
    string res = row[0], t2 = "";;
    for(int i = 1; i < row.size(); i++){
        string t1 = row[i];
        t2 += '0';
        t1 = t1+t2;
        while(t1.length() < res.length()){
            t1 = '0'+t1;
        }
        while(t1.length() > res.length()){
            res = '0'+res;
        }
        int s, c = 0, n, m;
        for(int j = t1.length()-1; j >= 0; j--){
            n = t1[j]-'0';
            m = res[j]-'0';
            s = (n+m)+c;
            c = s/10;
            s = s%10;
            res[j] = (char)(s+'0');
        }
        if(c!='0')
            res = (char)(c+'0')+res;
    }
    int n = 0;
    while(res[n] == '0')
        n++;
    res = res.substr(n, res.size());
    return res;
}

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = a;
}


string multiplyStrings(string s1, string s2) {
   //Your code here
   int f1 = false, f2 = false;
    if(s1[0] == '-'){
        s1 = s1.substr(1, s1.length());
        f1 = true;
    }
    if(s2[0] == '-'){
        s2 = s2.substr(1, s2.length());
        f2 = true;
    }
    vector<string> row;
    for(int i = s2.length()-1; i >= 0; i--){
        string str;
        int m = s2[i]-'0', c = 0, n, p;
        for(int j = s1.length()-1; j >= 0; j--){
            n = s1[j]-'0';
            p = n*m+c;
            c = p/10;
            p = p%10;
            str = (char)(p+'0')+str;
        }
        if(c!='0')
            str = (char)(c+'0')+str;
        row.push_back(str);
    }
    
    string res = addstrings(row);
    if(f1 && f2)
        return res;
    else if(f1 || f2)
        return '-'+res;
    else
        return res;
}


*/