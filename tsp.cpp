#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
    cin >> t;
    while(--t >= 0){
        int n;
        cin >> n;
        int graph[n][n];
        memset(graph, 0, sizeof(graph));
        vector<int> nodes;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cin >> graph[i][j];
        }
        for(int i = 1; i < n; i++)
            nodes.push_back(i);
        // for(int i = 0; i < n-1; i++){
        //     int u = nodes[i], v = nodes[i+1];
        //     cout << graph[u][v] << endl;
        // }
            
        int min_length = INT_MAX, source = 0;
        do{
            int length = 0;
            if(graph[0][nodes[0]] != 0)
                length += graph[0][nodes[0]];
            
            else
                continue;
            for(int i = 0; i < nodes.size()-1; i++){
                int u = nodes[i], v = nodes[i+1];
                if(graph[u][v])
                    length += graph[u][v];
                else
                    continue;
            }
            if(graph[nodes[nodes.size()-1]][0] != 0)
                length += graph[nodes[nodes.size()-1]][0]; 
            
            else
                continue;
            min_length = min(min_length, length);
        }
        while(next_permutation(nodes.begin(), nodes.end()));
        cout << min_length << endl;
    }
	return 0;
}