
int rect(vector<int> row){
    stack<int> st;
    int i = 0, max_area = 1;
    while(i < row.size()){
        if((!st.empty() && row[i] > row[st.top()]) || st.empty()){
            st.push(i);
            i++;
        }
        else{
            int t = row[st.top()];
            st.pop();
            if(!st.empty())
                max_area = max(max_area, (i-st.top()-1)*t);
            else
                max_area = max(max_area, t*i);
        }
    }
    while(!st.empty()){
        int t = row[st.top()];
        st.pop();
        if(!st.empty())
            max_area = max(max_area, (i-st.top()-1)*t);
        else
            max_area = max(max_area, t*i);
    }
    return max_area;
}

int maxArea(int M[MAX][MAX],int n,int m)
{
    int max_rec = 0, count = 1;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < m; j++){
            if(M[i][j] == 1 && i>0)
            {
                M[i][j] += M[i-1][j];
            }
            row.push_back(M[i][j]);
        }
            max_rec = max(max_rec, rect(row));
    }
    return max_rec;
    //Your code here
}
