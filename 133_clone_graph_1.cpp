/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    unordered_map<Node*,Node*> visited;
public:
    
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        if(visited[node]) return visited[node];
        Node* new_node = new Node();
        new_node->val = node->val;
        visited[node] = new_node;
        for(Node* n : node->neighbors){
            new_node->neighbors.push_back(cloneGraph(n)); 
        }
        return new_node;
    }
};
