
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
bool valid(int n){
    if(n > 255 || n < 0)
        return false;
    return true;
}

void generate(vector<vector<int>> &ips, vector<int> ip, string s, int ind){
    if(ind == s.size() && ip.size() == 4){
        // cout << "here" << endl;
        ips.push_back(ip);
        return;
    }
    if(ind == s.size())
        return;
    if(ip.size() == 4)
        return;
    int n = 0;
    // cout << ind << endl;
    for(int i = ind; i < ind+3 && i < s.size(); i++){
        n += (s[i]-'0');
        // cout << s[i]-'0' << endl;
        if(valid(n)){
            // cout << n << endl;
            ip.push_back(n);
            generate(ips, ip, s, i+1);
            ip.pop_back();
        }
        n = n*10;
    }
}

vector<string> genIp(string s)
{
    vector<vector<int>> ips;
    vector<string> ans;
    string res, valid;
    if(s.length() > 12)
        return ans;
    vector<int> ip;
    generate(ips, ip, s, 0);
    for(int i = 0; i < ips.size(); i++){
        res = "", valid = "";
        for(int j = 0; j < ips[i].size()-1; j++){
            res += to_string(ips[i][j]);
            res += ".";
            valid += to_string(ips[i][j]);
        }
        res += to_string(ips[i][ips[i].size()-1]);
        valid += to_string(ips[i][ips[i].size()-1]);
        if(s == valid){
            ans.push_back(res);
            // cout << res << endl;
        }
    }
    return ans;
    //Your code here
}
