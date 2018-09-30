#include <iostream>
#include <vector>
using namespace std;

void ease(vector<int> r){
    int n = r.size()-1, i = 1, first = r[0], first_ind = 0;
    while(i <= n){
        if(r[i] == 0){
            i++;
        }
        else if(r[i] == first){
            r[first_ind] = first*2;
            r[i] = 0;
            first = r[first_ind];
            i++;
        }
        else{
            first = r[i];
            first_ind = i;
            i++;
        }
    }
    i = 0;
    int j = 0;
    while(i < r.size()){
        if(r[i] != 0){
            r[j] = r[i];
            if(i != j)
                r[i] = 0;
            j += 1;
        }
        i += 1;
    }
    for(i = 0; i <= n; i++)
        cout << r[i] << " ";

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