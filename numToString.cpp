#include<bits/stdc++.h>

using namespace std;

int main()
 {
	//code
	int t, n;
    cin >> t;
    while(--t >= 0){
    cin >> n;
    string ans, end;
    string tens[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};
	string tens_[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
	string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	if(n%100 < 20 && n%100 > 10){
        end = tens_[(n%100)%10];
    }
    else{
        if((n%100)/10)
            end = tens[(n%100)/10] + " "+ ones[(n%10)];
        else
            end = ones[(n%10)];
    }
    if(n == 0){
        cout << "zero" << endl;
        continue;
    }
    if(n == 0){
        cout << "zero" << endl;
        continue;
    }
    if(n < 99)
        ans = ones[n/100]+ end;
    else if(n >= 100 && n < 1000){
        if(end == "")
            ans = ones[n/100] + " hundred";
        else    
            ans = ones[n/100] + " hundred and " + end;
    }
    else{
        if(ones[(n/100)%10] == "" && end == "")
            ans = ones[n/1000] + " thousand ";
        else if(ones[(n/100)%10] == "" && end != "")
            ans = ones[n/1000] + " thousand and " + end;
        else if(ones[(n/100)%10] != "" && end == "")
            ans = ones[n/1000] + " thousand " + ones[(n/100)%10] + " hundred";
        else
            ans = ones[n/1000] + " thousand " + ones[(n/100)%10] + " hundred and " + end;
    }
    cout << ans << endl;
    }
	return 0;
}