#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t, n;
    cin >> t;
    while(--t >= 0){
        int x, ans = -1;
        vector<int> v;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        int mid, i = 0, j = v.size()-1;
        while(i <= j){
            mid = (i+j)/2;
            if(v[(mid-1)%v.size()] < v[mid] && v[mid] > v[(mid+1)%v.size()])
                break;
            else if(v[(mid-1)%v.size()] < v[mid])
                i = mid+1;
            else
                j = mid-1;
        }
        cin >> x;
        i = 0, j = mid-1;
        if(v[mid] == x){
            ans = mid;
        }
        while(i <= j){
            mid = (i+j)/2;
            if(v[mid] == x)
                break;
            else if(v[mid] < x)
                i = mid+1;
            else
                j = mid-1;
        }
        if(v[mid] == x){
            ans = mid;
        }
        i = mid+1, j = v.size()-1;
        while(i <= j){
            mid = (i+j)/2;
            if(v[mid] == x)
                break;
            else if(v[mid] > x)
                i = mid+1;
            else
                j = mid-1;
        }
        if(v[mid] == x){
            ans = mid;
        }
        
        cout <<ans << endl;
    }
	//code
	return 0;
}
    
