#include <bits/stdc++.h>

using namespace std;


void fill(vector<int> &v,int &n1,int &n2, unordered_set<int> &m){
    int val;
    int i = v.size()-1;
    for(int j=0;j<v.size();j++){
        val = n1*v[j]-n2*v[i];
        if(val > 0 && m.find(val) == m.end())
            m.insert(val);
        val = n1*v[i]-n2*v[j];
        if(val > 0 && m.find(val) == m.end())
            m.insert(val);
    }
}

int main() {
	//code
    int t;
	cin >> t;
	while(--t >= 0){
        int n1,n2,n;
        cin>>n1>>n2>>n;
        vector<int> v;
        v.push_back(1);
        unordered_set<int> m;
        for(int i=1;i<n;i++){
            fill(v,n1,n2,m);
            for(int j=v[i-1]+1;;j++){
                if(m.find(j) == m.end()){
                    v.push_back(j);
                    break;
                }
            }  
        }
	   for(int i=0;i<v.size();i++){
	       cout<<v[i]<<" ";
	   }
	   cout<<endl;
	}
	
	return 0;
}