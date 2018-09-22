#include<bits/stdc++.h>
using namespace std;

void print_seq(int x, int n, bool flag){
    if(x <= 0){
        flag = true;
    }
    if(flag && x == n){
        cout << x << " ";
        return;
    }
    if(flag == false){
        cout << x << " ";
        print_seq(x-5, n, flag);
    }
    else{
        cout << x << " ";
        print_seq(x+5, n, flag);
    }
}

int main()
 {
	int t;
	cin >> t;
	while(--t >= 0){
    	int n, x;
    	cin >> n;
        x = n;
	    print_seq(x, n, false);
	    cout << endl;
	}
	return 0;
}