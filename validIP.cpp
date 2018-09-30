#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        string ip, str;
        cin >> ip;
        vector<string> ips;
        int i = 0, val;
        while(i < ip.length()){
            if(ip[i] != '.')
                str += ip[i];
            if(ip[i] == '.' || i == ip.length()-1){
                ips.push_back(str);
                str = "";
            }
            i++;
        }
        if(ips.size() != 4){
            cout << "0" << endl;
            continue;
        }
        stringstream ss;
        bool flag = false;
        for(int i = 0; i < ips.size(); i++){
            ss << ips[i];
            ss >> val;
            if(to_string(val) != ips[i] || val > 255 || val < 0){
                cout << "0" << endl;
                flag = true;
                break;
            }
            ss.str("");
            ss.clear();
        }
        if(flag)
            continue;
        cout << "1" << endl;
    }
    return 0;
}

