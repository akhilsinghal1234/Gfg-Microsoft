#include <iostream>
#include <string>
using namespace std;

string dict[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","ng","o","p","q","r","s","t","u","v","w","x","y","z"};

int comp(string a, string b){
    int pos1, pos2;
    for(int i = 0; i < 27; i++){
        if(dict[i] == a)
            pos1 = i;
        if(dict[i] == b)
            pos2 = i;
    }
    if(pos1 < pos2)
        return -1;
    
    return 1;
}

int strcomp(string a, string b){
    int i = 0, j = 0;
    while(i < a.length() && i < b.length()){
        if(a[i] == b[i]){
            if(a[i] == 'n'){
                if(i+1 < a.length() && a[i+1] == 'g' && i+1 >= b.length())
                    return 1;
                else if(i+1 < b.length() && b[i+1] == 'g' && i+1 >= a.length())
                    return -1;
                if(i+1 < a.length() && i+1 < b.length()){
                string s1, s2;
                s1 += a[i], s2 += b[i];

                if(a[i] == 'n' && a[i+1] == 'g' && b[i+1] != 'g')
                    return comp(dict[14], s2);

                else if(a[i] == 'n' && b[i+1] == 'g' && a[i+1] != 'g')
                    return comp(s1, dict[14]);
                }
            }
            if(i+1 < a.length() && i+1 < b.length()){
                string s1, s2;
                s1 += a[i], s2 += b[i];

                if(a[i] == 'n' && a[i+1] == 'g' && b[i+1] != 'g')
                    return comp(dict[14], s2);

                else if(a[i] == 'n' && b[i+1] == 'g' && a[i+1] != 'g')
                    return comp(s1, dict[14]);
            }
            i++;
        }
        else{
            string s1, s2;
            s1 += a[i], s2 += b[i];
            return comp(s1, s2); 
        }  
    }

    if(i < a.length())
        return -1;
    else if(i < b.length())
        return 1;

    return 0;

}
int main(){
    int t;
    cin >> t;
    while(--t >= 0){
        string s1, s2;
        cin >> s1 >> s2;
        cout << strcomp(s1, s2) << endl;
    }
    return 0;
}