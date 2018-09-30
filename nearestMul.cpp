#include <iostream>
#include <cmath>
using namespace std;


int main() {	
	int t,a,b;
	cin >> t;
	while(--t >= 0){
	    cin >> a >> b;
	    int rem = a%b, ans;
	    if((a > 0 && b > 0) || (a < 0 && b < 0)){
	        if(rem < b-rem)
	            ans = a-rem;
	        else
	            ans = a+(b-rem);
	    }
		else{
			int n1 = a - rem;
			int n2 = a - (b+rem);
			if(abs(n1 - a) < abs(n2 - a))
			    ans = n1;
			else
			    ans = n2;
		}
		cout << ans << endl;
	}
	return 0;
}