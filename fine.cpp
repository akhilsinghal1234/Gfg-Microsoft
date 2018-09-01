#include <vector>
using namespace std;

long int fine(vector<int> p, vector<int> v, int d){
    int i = 0;
    unsigned int fine = 0;
    for(i; i < v.size(); i++){
        if(d%2 == 0 && p[i]%2 ==1)
        fine += v[i];
        else if(d%2 == 1 && p[i]%2 == 0)
            fine += v[i];
    }
    return fine;
}

int main() {
	int t, n, x, d;
    cin >> t;
    while(--t >= 0){
        cin >> n >> d;
        int cp = n;
        vector<int> p, v;
        while(--n >= 0){
            cin >> x;
            p.push_back(x);
        }
        while(--cp >= 0){
            cin >> x;
            v.push_back(x);
        }
    cout << fine(p, v, d) << endl;
    }
	return 0;
}