// https://practice.geeksforgeeks.org/problems/alien-dictionary/1


{
//Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include<bits/stdc++.h>
using namespace std;
string printOrder(string [], int , int );
string order;
bool f(string a,string b)
{
	int p1=0;int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1 ==p2;i++ )
	{
		p1 = order.find(a[i]);
		p2 = order.find(b[i]);
	//	cout<<p1<<" "<<p2<<endl;
	}
	
	if(p1 == p2 and a.size()!=b.size())
	return a.size()<b.size();
	
	return p1<p2;
}
	
// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    
        string ss = printOrder(s,n,k);
        order="";
        for(int i=0;i<ss.size();i++)
        order+=ss[i];
        
        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp,temp+n,f);
        
        bool f= true;
        for(int i=0;i<n;i++)
        if(s[i]!=temp[i])f=false;
        
        cout<<f;
        cout<<endl;
        
    }
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
void topological(stack<char> &st, int node, vector<vector<int> > &graph, vector<int> &visited){
    int n = visited.size();
    visited[node] = 1;
    for(int i = 0; i < n; i++){
        if(graph[node][i] && !visited[i])
            topological(st, i, graph, visited);
    }
    st.push(char('a'+node));
}

string printOrder(string dict[], int N, int n)
{
    string ret;
    vector<vector<int> > graph(n, vector<int> (n, 0));
    vector<int> visited(n, 0);
    for(int i = 0; i < N-1; i++){
        string w1 = dict[i], w2 = dict[i+1];
        int l = min(w1.length(), w2.length());
        for(int k = 0; k < l; k++)
            if(w1[k] != w2[k]){
                graph[w1[k]-'a'][w2[k]-'a'] = 1;
                break;
            }
    }
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(!visited[i])
            topological(st, i, graph, visited);
    }
    while(st.size() > 0){
        ret += st.top();
        st.pop();
    }
    // cout << ret << endl;
    return ret;
   //Your code here
}