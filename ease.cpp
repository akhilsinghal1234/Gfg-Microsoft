#include <iostream>
#include <vector>
using namespace std;

void ease(vector<int> r){
    int n = r.size()-1;
    for(int i = 0; i < r.size()-1; i++)
        if(r[i] == r[i+1] && r[i] != 0)
            r[i] = 2*r[i], r[i+1] = 0;
            
    int i = 0, j = 0;
    while(i < r.size()){
        if(r[i] != 0){
            r[j] = r[i];
            if(i != j)
                r[i] = 0;
            j += 1;
        }
        i += 1;
    }
    for(auto it: r)
        cout << it << " ";
}

int main() {
	int t,n,x;
	cin >> t;
	while(--t >= 0){
	    cin >> n;
	    vector<int> r;
	    while(--n >= 0){
	        cin >> x;
	        r.push_back(x);
	    }
	    ease(r);
	    cout << endl;
	}
	return 0;
}