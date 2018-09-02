#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        long long int n;
        cin >> n;
        if(n == 0)
            n = 3;
        if(float(log2(n)) - int(log2(n)) < 0.00001)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}