#include <stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(--t >= 0){
	    string s;
	    cin >> s;
	    stack<int> st;
	    int res = s[0]-'0', i = 1;
	    while(i < s.length()){
	        if(s[i] == 'A'){
	            int val = s[i+1]-'0';
	           // cout << val << endl;
	            res = res * val;
	            i++;
	        }
	        else if(s[i] == 'B'){
	           int val = s[i+1]-'0';
	           //cout << val << endl;
	            if(res == 1 && val == 1)
	                res = 1;
	            else
	                res = (res + val);
	            i++; 
	        }
	        else{
	            int val = s[i+1]-'0';
	           // cout << val << endl;
	            if(val != res)
	                res = 1;
	            else
	                res = 0;
	           i++;
	        }
	        i++;
	    }
	   cout << res << endl; 
	}
	return 0;
}