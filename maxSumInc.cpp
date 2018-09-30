
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void maxSum(vector<int> a){
    int n = a.size(), max_sum = INT_MIN;
    vector<int> dp;
    for(int i = 0; i < n; i++)
        dp.push_back(a[i]);

    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(a[i] > a[j])
                dp[i] = max(dp[i], a[i]+dp[j]);
                
    for(int i = 0; i < n; i++)
        max_sum = max(max_sum, dp[i]);
    
    cout << max_sum << endl;
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
	    maxSum(r);
	}
	return 0;
}