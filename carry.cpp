#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        long long int x,y;
        cin >> x >> y;
        int carry = 0, ncarry = 0;
        while(x && y){
            int a = x%10, b = y%10;
            x = x/10;
            y = y/10;
            carry = (a+b+carry)/10;
            if(carry)
                ncarry++;
        }
        while(x && carry == 1 && x%10 == 9){
            ncarry++;
            x /= 10;
        }
        while(y && carry == 1 && y%10 == 9){
            ncarry++;
            y /= 10;
        }
        cout << ncarry << endl;
    }
    return 0;
}