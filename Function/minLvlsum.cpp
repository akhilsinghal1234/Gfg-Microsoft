int minLeafSum(Node* root)
{
    queue<pair<Node *, int>> q;
    map<int, vector<int> > mp;
    if(root == NULL)
        return 0;
    q.push(make_pair(root, 1));
    int sum = 0;
    bool leaf = false;
    while(!q.empty() && !leaf){
        pair<Node *, int> p = q.front();
        Node *t = p.first;
        q.pop();
        if(!t->left && !t->right)
        {
            mp[p.second].push_back(t->data);
            leaf = true;
            while(!q.empty()){
                pair<Node *, int> p = q.front();
                t = p.first;
                q.pop();
                if(!t->left && !t->right)
                    mp[p.second].push_back(t->data);
            }
        }
        if(t->left)
        q.push(make_pair(t->left, p.second+1));
        if(t->right)
        q.push(make_pair(t->right, p.second+1));
    }
    if(mp.size() == 0)
        return 0;
    map<int, vector<int>>::iterator it = mp.begin();
    for(int i = 0; i < it->second.size(); i++)
        sum += it->second[i];
    return sum;
	// Code here
}