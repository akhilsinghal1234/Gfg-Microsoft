#include <iostream>
#include <vector>
#include <set>

using namespace std;

void nth(vector<int> &a, vector<int> &b, int n){
    set<int> st;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            st.insert(a[i]+b[j]);
    set<int>::iterator it = st.begin();
    int t = 0, ans;
    for(it; (it != st.end() && t < n); it++){
        t++;
        ans = *it;
    }
    cout << ans << endl;
}

int main(){
    int t, m, n, N;
    cin >> t;
    while(--t >= 0){
        cin >> m >> n;
        vector<int> a(m), b(n);
        for(int i = 0; i < m; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        cin >> N;
        nth(a, b, N);
    }
}