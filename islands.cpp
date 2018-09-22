int x[] = {1,0,-1,0,1,-1,1,1};
int y[] = {0,1,0,-1,1,-1,-1,-1};

bool ifSafe(int x, int y, int n, int m){
    if(x > n || x < 0 || y < 0 || y > m)
        return false;
    return true;
}

void visit(int A[MAX][MAX], int N, int M, int visited[MAX][MAX], int u, int v){
    visited[u][v] = 1;
    for(int i = 0; i < 8; i++){
        if(ifSafe(u+x[i], v+y[i], N, M) && !visited[u+x[i]][v+y[i]] && A[u+x[i]][v+y[i]])
            visit(A, N, M, visited, u+x[i], v+y[i]);
    }
}

int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here 
    int visited[N][M];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            visited[i][j] = 0;
    int islands = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            {
                if(!visited[i][j] && A[i][j]){
                    visit(A, N, M, visited, i, j);
                    islands += 1;
                }
            }
    }
}