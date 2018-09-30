#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t, n, r;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        string ans;
        while(n){
            r = n%26;
            cout << r << endl;
            if(r == 0){
                ans = 'Z'+ans;
                n = n/26-1;
            }
            else{
                ans = (char)(r+'A'-1)+ans;
                n = n/26;
            }
        }
        cout << ans << endl;
    }
	//code
	return 0;
}