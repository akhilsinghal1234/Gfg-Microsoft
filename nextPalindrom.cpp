#include<bits/stdc++.h>
using namespace std;

void print(vector<char> &v){
    for(int i = 0 ; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

bool check(vector<char> v, int i, int j){
    while(i >= 0){
        if(v[i] > v[j]){
            return true;
        }
        else if(v[i] < v[j])
            return false;

        i--;
        j++;
    }
    return false;
}

void getpal(vector<char> &v){
    if(v.size() % 2 == 0){
        int j = v.size()/2, i = j-1, flag = false;
        // bool c = check(v, i-1, j+1);
        while(i >= 0){
            if(!flag)
                cout << v[i] << " " << v[j] << " " << flag << " ";
            int l = v[i], r = v[j];
            if(l > r && !flag){
                cout << "1: " << endl;
                v[j] = l;
                flag = true;
            }
            else if(r == l && !flag){
                bool c = check(v, i-1, j+1);
                cout << "2: " << c << endl;
                if(!c){
                    v[i] = l+1;
                    v[j] = v[i];
                    flag = true;
                }
            }
            else if(r > l && !flag){
                    cout << "3: " << endl;
                    v[i] = l+1;
                    v[j] = v[i];
                    flag = true;
            }
            else if(flag){
                    v[j] = l;
            }
            i--;
            j++;
        }
        return;
    }
    else{
        int  mid = v.size()/2, j = v.size()/2+1, i = mid-1, flag = false;
        // cout << v[mid] << endl;
        bool c = check(v, i, j);
        if(v[mid] < '9'){
            if(!c)
                v[mid] = v[mid]+1;
            while(i >= 0){
                int l = v[i], r = v[j];
                v[j] = l;
                i--;
                j++;
            }
            return;
        }
        else{
            // if(!c)
            v[mid] = '0';
            while(i >= 0){
                int l = v[i], r = v[j];
                if(l > r && !flag){
                    v[j] = l;
                    flag = true;
                }
                else if(r == l && r == '9' && !flag){
                    v[i] = '0';
                    v[j] = '0';
                }
                else if(r >= l && !flag){
                    v[i] = l+1;
                    v[j] = v[i];
                    flag = true;
                }
                else if(flag)
                    v[j] = l;
                i--;
                j++;
            }
            return;
        }   
    }
}

// void compare(vector<char> chars, vector<char> v){
//     for(int i = 0; i < v.size(); i++)
//         if(v[i])
// }

int main()
 {
    int t, n;
    cin >> t;
    while(--t >= 0){
        cin >> n;
        char x;
        vector<char> v;
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        vector<char> chars;
        chars = v;
        getpal(v);
        // compare(chars, v);
        print(v);
    }
	//code
	return 0;
}

// 4 5 7 7 6 4 3 3 2 3 6 6 6 7 3 3 6 3 7 8 7 2 5 8 3 5 6 6 3 2 6 8 6 5 6 2 6 8 5 4 4 6 3 3 3 2 4 7 3 8 4 2 7 3 6 4 7 3 7 4 6 2 6 4 4 5 6 3 6 5 3 3 7 8 8 4 6 2 4 6 4 4 3 5 8 2 5 2 2 2 7 6 5 5 6 6 2 6 7 6 7 8 7 7 3 8 3 7 5 8 5 8 2 5 7 5 6 3 7 8 7 2 8 5 7 8 2 8 4 8 7 2 3 4 4 8 8 4 2 7 7 5 4 4 6 5 6 4 7 8 8 8 7 5 7 4 2 4 3 7 7 6 4 4 7 5 5 8 8 4 3 8 6 4 2 5 3 2 3 5 6 2 4 4 4 6 5 4 6 4 8 5 4 4 4 6 2 6 6 5 7 8 2 4 2 7 6 7 2 3 8 4 2 8 5 3 8 6 3 2 6 3 2 7 2 4 4 7 8 6 6 4 7 3 2 6 3 2 4 2 4 4 6 4 7 3 5 4 3 3 7 8 8 5 6 8 4 3 6 7 4 4 4 8 6 7 5 2 5 2 4 7 2 8 7 5 4 6 4 7 8 3 2 8 4 2 7 4 4 7 4 6 5 5 7 3 7 4 6 5 7 5 7 3 8 4 8 5 3 4 3 4 3 5 6 8 6 8 3 5 7 3 7 3 4 8 3 8 6 3 8 2 6 7 4 4 3 5 2 4 5 7 2 6 7 8 7 4 8 5 3 6 6 7 5 6 5 2 8 8 4 6 8 4 4 3 6 4 8 7 2 3 3 3 7 6 8 7 3 6 2 2 6 3 7 8 6 7 3 3 3 2 7 8 4 6 3 4 4 8 6 4 8 8 2 5 6 5 7 6 6 3 5 8 4 7 8 7 6 2 7 5 4 2 5 3 4 4 7 6 2 8 3 6 8 3 8 4 3 7 3 7 5 3 8 6 8 6 5 3 4 3 4 3 5 8 4 8 3 7 5 7 5 6 4 7 3 7 5 5 6 4 7 4 4 7 2 4 8 2 3 8 7 4 6 4 5 7 8 2 7 4 2 5 2 5 7 6 8 4 4 4 7 6 3 4 8 6 5 8 8 7 3 3 4 5 3 7 4 6 4 4 2 4 2 3 6 2 3 7 4 6 6 8 7 4 4 2 7 2 3 6 2 3 6 8 3 5 8 2 4 8 3 2 7 6 7 2 4 2 8 7 5 6 6 2 6 4 4 4 5 8 4 6 4 5 6 4 4 4 2 6 5 3 2 3 5 2 4 6 8 3 4 8 8 5 5 7 4 4 6 7 7 3 4 2 4 7 5 7 8 8 8 7 4 6 5 6 4 4 5 7 7 2 4 8 8 4 4 3 2 7 8 4 8 2 8 7 5 8 2 7 8 7 3 6 5 7 5 2 8 5 8 5 7 3 8 3 7 7 8 7 6 7 6 2 6 6 5 5 6 7 2 2 2 5 2 8 5 3 4 4 6 4 2 6 4 8 8 7 3 3 5 6 3 6 5 4 4 6 2 6 4 7 3 7 4 6 3 7 2 4 8 3 7 4 2 3 3 3 6 4 4 5 8 6 2 6 5 6 8 6 2 3 6 6 5 3 8 5 2 7 8 7 3 6 3 3 7 6 6 6 3 2 3 3 4 6 7 7 5 4
// 4 5 7 7 6 4 3 3 2 3 6 6 6 7 3 3 6 3 7 8 7 2 5 8 3 5 6 6 3 2 6 8 6 5 6 2 6 8 5 4 4 6 3 3 3 2 4 7 3 8 4 2 7 3 6 4 7 3 7 4 6 2 6 4 4 5 6 3 6 5 3 3 7 8 8 4 6 2 4 6 4 4 3 5 8 2 5 2 2 2 7 6 5 5 6 6 2 6 7 6 7 8 7 7 3 8 3 7 5 8 5 8 2 5 7 5 6 3 7 8 7 2 8 5 7 8 2 8 4 8 7 2 3 4 4 8 8 4 2 7 7 5 4 4 6 5 6 4 7 8 8 8 7 5 7 4 2 4 3 7 7 6 4 4 7 5 5 8 8 4 3 8 6 4 2 5 3 2 3 5 6 2 4 4 4 6 5 4 6 4 8 5 4 4 4 6 2 6 6 5 7 8 2 4 2 7 6 7 2 3 8 4 2 8 5 3 8 6 3 2 6 3 2 7 2 4 4 7 8 6 6 4 7 3 2 6 3 2 4 2 4 4 6 4 7 3 5 4 3 3 7 8 8 5 6 8 4 3 6 7 4 4 4 8 6 7 5 2 5 2 4 7 2 8 7 5 4 6 4 7 8 3 2 8 4 2 7 4 4 7 4 6 5 5 7 3 7 4 6 5 7 5 7 3 8 4 8 5 3 4 3 4 3 5 6 8 6 8 3 5 7 3 7 3 4 8 3 8 6 3 8 2 6 7 4 4 3 5 2 4 5 7 2 6 7 8 7 4 8 5 3 6 6 7 5 6 5 2 8 8 4 6 8 4 4 3 6 4 8 7 2 3 3 3 7 6 8 7 3 6 3 3 6 3 7 8 6 7 3 3 3 2 7 8 4 6 3 4 4 8 6 4 8 8 2 5 6 5 7 6 6 3 5 8 4 7 8 7 6 2 7 5 4 2 5 3 4 4 7 6 2 8 3 6 8 3 8 4 3 7 3 7 5 3 8 6 8 6 5 3 4 3 4 3 5 8 4 8 3 7 5 7 5 6 4 7 3 7 5 5 6 4 7 4 4 7 2 4 8 2 3 8 7 4 6 4 5 7 8 2 7 4 2 5 2 5 7 6 8 4 4 4 7 6 3 4 8 6 5 8 8 7 3 3 4 5 3 7 4 6 4 4 2 4 2 3 6 2 3 7 4 6 6 8 7 4 4 2 7 2 3 6 2 3 6 8 3 5 8 2 4 8 3 2 7 6 7 2 4 2 8 7 5 6 6 2 6 4 4 4 5 8 4 6 4 5 6 4 4 4 2 6 5 3 2 3 5 2 4 6 8 3 4 8 8 5 5 7 4 4 6 7 7 3 4 2 4 7 5 7 8 8 8 7 4 6 5 6 4 4 5 7 7 2 4 8 8 4 4 3 2 7 8 4 8 2 8 7 5 8 2 7 8 7 3 6 5 7 5 2 8 5 8 5 7 3 8 3 7 7 8 7 6 7 6 2 6 6 5 5 6 7 2 2 2 5 2 8 5 3 4 4 6 4 2 6 4 8 8 7 3 3 5 6 3 6 5 4 4 6 2 6 4 7 3 7 4 6 3 7 2 4 8 3 7 4 2 3 3 3 6 4 4 5 8 6 2 6 5 6 8 6 2 3 6 6 5 3 8 5 2 7 8 7 3 6 3 3 7 6 6 6 3 2 3 3 4 6 7 7 5 4 
// 4 5 7 7 6 4 3 3 2 3 6 6 6 7 3 3 6 3 7 8 7 2 5 8 3 5 6 6 3 2 6 8 6 5 6 2 6 8 5 4 4 6 3 3 3 2 4 7 3 8 4 2 7 3 6 4 7 3 7 4 6 2 6 4 4 5 6 3 6 5 3 3 7 8 8 4 6 2 4 6 4 4 3 5 8 2 5 2 2 2 7 6 5 5 6 6 2 6 7 6 7 8 7 7 3 8 3 7 5 8 5 8 2 5 7 5 6 3 7 8 7 2 8 5 7 8 2 8 4 8 7 2 3 4 4 8 8 4 2 7 7 5 4 4 6 5 6 4 7 8 8 8 7 5 7 4 2 4 3 7 7 6 4 4 7 5 5 8 8 4 3 8 6 4 2 5 3 2 3 5 6 2 4 4 4 6 5 4 6 4 8 5 4 4 4 6 2 6 6 5 7 8 2 4 2 7 6 7 2 3 8 4 2 8 5 3 8 6 3 2 6 3 2 7 2 4 4 7 8 6 6 4 7 3 2 6 3 2 4 2 4 4 6 4 7 3 5 4 3 3 7 8 8 5 6 8 4 3 6 7 4 4 4 8 6 7 5 2 5 2 4 7 2 8 7 5 4 6 4 7 8 3 2 8 4 2 7 4 4 7 4 6 5 5 7 3 7 4 6 5 7 5 7 3 8 4 8 5 3 4 3 4 3 5 6 8 6 8 3 5 7 3 7 3 4 8 3 8 6 3 8 2 6 7 4 4 3 5 2 4 5 7 2 6 7 8 7 4 8 5 3 6 6 7 5 6 5 2 8 8 4 6 8 4 4 3 6 4 8 7 2 3 3 3 7 6 8 7 3 6 2 2 6 3 7 8 6 7 3 3 3 2 7 8 4 6 3 4 4 8 6 4 8 8 2 5 6 5 7 6 6 3 5 8 4 7 8 7 6 2 7 5 4 2 5 3 4 4 7 6 2 8 3 6 8 3 8 4 3 7 3 7 5 3 8 6 8 6 5 3 4 3 4 3 5 8 4 8 3 7 5 7 5 6 4 7 3 7 5 5 6 4 7 4 4 7 2 4 8 2 3 8 7 4 6 4 5 7 8 2 7 4 2 5 2 5 7 6 8 4 4 4 7 6 3 4 8 6 5 8 8 7 3 3 4 5 3 7 4 6 4 4 2 4 2 3 6 2 3 7 4 6 6 8 7 4 4 2 7 2 3 6 2 3 6 8 3 5 8 2 4 8 3 2 7 6 7 2 4 2 8 7 5 6 6 2 6 4 4 4 5 8 4 6 4 5 6 4 4 4 2 6 5 3 2 3 5 2 4 6 8 3 4 8 8 5 5 7 4 4 6 7 7 3 4 2 4 7 5 7 8 8 8 7 4 6 5 6 4 4 5 7 7 2 4 8 8 4 4 3 2 7 8 4 8 2 8 7 5 8 2 7 8 7 3 6 5 7 5 2 8 5 8 5 7 3 8 3 7 7 8 7 6 7 6 2 6 6 5 5 6 7 2 2 2 5 2 8 5 3 4 4 6 4 2 6 4 8 8 7 3 3 5 6 3 6 5 4 4 6 2 6 4 7 3 7 4 6 3 7 2 4 8 3 7 4 2 3 3 3 6 4 4 5 8 6 2 6 5 6 8 6 2 3 6 6 5 3 8 5 2 7 8 7 3 6 3 3 7 6 6 6 3 2 3 3 4 6 7 7 5 4 