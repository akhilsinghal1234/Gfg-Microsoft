#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0

int min_value(vector<int> &area){
    int m_v = area[0];
    for(int i = 1; i < area.size(); i++)
        m_v = min(m_v, area[i]);
    return m_v;
}
int max_value(vector<int> &area){
    int m_v = area[0];
    for(int i = 1; i < area.size(); i++)
        m_v += area[i];
    return m_v;
}

int required_painters(vector<int> &area, int val){
    int p = 1, sum = 0;
    for(int i = 0; i < area.size(); i++){
        // if(sum + area[i] > val){
        //     p += 1;
        //     sum = 0;
        // }
        // else
        if(area[i] > val)
            return INT_MAX;
        sum += area[i];
        if(sum > val){
            sum = area[i];
            p += 1;
        }
    }
    return p;
}

int main()
{
    int t;
    cin >> t;
    while(--t >= 0){
        int n, k, x;
        cin >> k;
        cin >> n;
        vector<int> area;
        for(int i = 0; i < n; i++){
            cin >> x;
            area.push_back(x);
        }
        int l = min_value(area);
        int r = max_value(area);
        int mid = l+(r-l)/2;
        if(k > n)
            k = n;
        while(l+1 < r){
            mid = (r+l)/2;
            cout << l << " " << r << endl;
            int painters = required_painters(area, mid);
            cout << mid << " " << painters << endl;
            if(painters <= k)
                r = mid;
            else
                l = mid;
        }
        cout << r << endl;
    }
	//code
	return 0;
}