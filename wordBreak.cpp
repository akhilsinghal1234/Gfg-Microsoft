#include <bits/stdc++.h>
using namespace std;

struct Trienode{
    Trienode *children[26];
    bool end[26];
};

struct Trienode *newNode(int n){
    struct Trienode *node = new Trienode;
    for(int i = 0; i < 26; i++)
        node->children[i] = NULL;
    for(int i = 0; i < 26; i++)
        node->end[i] = false;
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
            if(i == str.length()-1)
                root->end[key] = true;
            root = root->children[key];
        }
        root = temp;
    }

    bool search(string s){
        Trienode *temp = root;
        for(int i = 0; i < s.length(); i++){
            int key = s[i]-'a';
            if(temp->children[key] == NULL)
                return false;
            if(temp->end[key] == true && i == s.length()-1)
                return true;
            temp = temp->children[key];
        }
        return false;
    }
};

void word_break(Trie t, string p){
    string pat;
    int index, count = 0;
    stack<pair<string, int> > q;
    string s;
    for(int i = 0; i < p.length(); i++){
        s += p[i];
        if(t.search(s)){
            q.push(make_pair(s, i));
        }
    }

    while(q.empty() != true){
        pair<string, int> pa = q.top();
        q.pop();
        index = pa.second;
        if(index == p.length()-1)
            count++;
        s = "";
        for(int i = index+1; i < p.length(); i++){
            s += p[i];
            if(t.search(s)){
                q.push(make_pair(s,i));
            }
        }
    }
    cout << count << endl;
}

int main() {
    int test, n, i = 0;
    cin >> test;
    while(--test >= 0){
        cin >> n;
        Trie t(n);
        string s;
        while(--n >= 0){
            cin >> s;
            t.add(s, i++);
        }
        cin >> s;
        word_break(t, s);
    }
	return 0;
}