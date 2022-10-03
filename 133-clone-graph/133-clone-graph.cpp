/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if(node == NULL) return NULL;
    if(node->neighbors.size() == 0){
      Node* clone = new Node(node->val);
      return clone;
    }
    map<Node*, Node*> mp;
    queue<Node*> q;
    map<int, bool> visited;
    
    q.push(node); visited[node->val] = true;
    while(!q.empty()){
      Node* f = q.front(); q.pop();
      if(!mp[f]){
        Node* g = new Node(f->val);
        mp[f] = g; 
      }
      
      for(auto c: f->neighbors){
        if(!mp[c]) {
          Node* tmp = new Node(c->val);
          mp[c] = tmp;
        }
        mp[f]->neighbors.push_back(mp[c]);
        if(!visited[c->val]){
          q.push(c); visited[c->val] = true;
        }
      }
    }
    return mp[node];
  }
};