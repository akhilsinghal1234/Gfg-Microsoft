#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int val[] = {1, 5, 10, 50, 100, 500, 1000};

int to_int(string s) {
    int ans = 0;
    for(int j = 0; j < s.length(); j++){
        int f = 0,l = 0;
        for(int i = 0; i < 7; i++)
            if(s[j] == roman[i])
                f = val[i];

        if(j < s.length())
        for(int i = 0; i < 7; i++)
            if(s[j+1] == roman[i])
                l = val[i];
        if(l <= f)
            ans += f;
        else if(l > f){
            ans = ans+l-f;
            j++;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        string s;
        cin >> s;
        cout << to_int(s) << endl;
    }
    return 0;
}

