#include <bits/stdc++.h>

using namespace std;

void swap1(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int index, vector<int> &str){
    for(int j = index+1, k = str.size()-1; j < k; j++, k--){
        swap1(str[j], str[k]);
    }
}
void print(vector<int> v){
    for(int j = 0 ; j < v.size() ; j++)
        cout << v[j] << " ";
    cout << endl;
}

void next_perm(vector<int> &str){
    if(str.size() == 1){
        print(str);
        return;
    }
    int ind_i = -1, ind_j;
    for(int i = 0; i < str.size()-1; i++)
        if(str[i] < str[i+1])
            ind_i = i;
    if(ind_i == -1){
        reverse(-1, str);
        print(str);
    }
    else
    {
        for(int j = ind_i + 1; j < str.size(); j++)
            if(str[j] > str[ind_i])
                ind_j = j;

        int temp = str[ind_i];
        str[ind_i] = str[ind_j];
        str[ind_j] = temp;

        reverse(ind_i, str);
        print(str);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v, res;
    while(n--){
        int x;
        cin >> x;
        v.push_back(x);
    }
    print(v);
    next_perm(v);
    
    return 0;
}