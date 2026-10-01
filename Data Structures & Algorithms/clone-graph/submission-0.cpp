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
    Node* Graph(Node* node, unordered_map<Node *,Node *>&m) {
        if(m.find(node)!=m.end()){
            return m[node];
        }

        
        Node* n1 = new Node(node->val);
        m[node]=n1;
        for (auto i : node->neighbors) {
            
                
                n1->neighbors.push_back(Graph(i, m));
               
            
        }
        return n1;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node *,Node *>m;

        return Graph(node, m);
    }
};