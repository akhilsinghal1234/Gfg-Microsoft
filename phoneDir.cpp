// #include <set>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Trienode{
    Trienode *children[26];
    vector<int> end;
    vector<int> present;
    // Trienode *next = NULL;
};

struct Trienode *newNode(int n){
    struct Trienode *node = new Trienode;
    vector<int> p(n, 0);
    node->present = p;
    node->end = p;
    for(int i = 0; i < 26; i++)
        node->children[i] = NULL;

    return node;
}

class Trie{
    public:
    Trienode *root;
    int size;

    Trie(int n){
        root = newNode(n);
        size = n;
    }

    void add(string str, int ind){
        Trienode *temp = root;
        for(int i = 0; i < str.length(); i++){
            int key = str[i]-'a';
            if(!root->children[key])
                root->children[key] = newNode(size);
            root = root->children[key];
            root->present[ind] = 1;
        }
        root->end[ind] = true;
        root = temp;
    }

    vector<int> search(string s){
        Trienode *temp = root;
        vector<int> dummy(size, 0);
        for(int i = 0; i < s.length(); i++){
            int key = s[i]-'a';
            if(temp->children[key] == NULL)
                return dummy;
            temp = temp->children[key];
        }
        return temp->present;
    }
};

void phoneDirec(Trie t, vector<string> &strings, string p){
    string pat;
    vector<int> present;
    for(int i = 0; i < p.length(); i++){
        vector<string> ans;
        pat += p[i];
        present = t.search(pat);
        int count = 0;
        for(int i = 0; i < present.size(); i++)
            if(present[i]){
                count++;
                ans.push_back(strings[i]);
                // cout << strings[i] << " ";
            }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        if(ans.size() != 0){
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
        }
        if(count == 0)
            cout << "0";
        cout << endl;
    }   
}

int main() {
    int test, n, i = 0;
    cin >> test;
    while(--test >= 0){
        cin >> n;
        Trie t(n);
        vector<string> strings;
        string s;
        i = 0;
        while(--n >= 0){
            cin >> s;
            strings.push_back(s);
            t.add(s, i++);
        }
        cin >> s;
        phoneDirec(t, strings, s);
    }
    return 0;
}