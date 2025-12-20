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
private:
    unordered_map<Node*, Node*> track;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        track[node] = new Node(node->val);
        queue<Node*> nodes;
        nodes.push(node);

        while(!nodes.empty()) {
            Node* temp = nodes.front();
            nodes.pop();

            for(auto &ele : temp->neighbors) {
                if(track.find(ele) == track.end()) {
                    Node* newNeighbor = new Node(ele->val);
                    track[ele] = newNeighbor;
                    nodes.push(ele);
                }
                track[temp]->neighbors.push_back(track[ele]);
            }
            
        }
        return track[node];
    }
};
/*
1 - [2, 4] - node
2 - [1, 3]
3 - [2, 4]
4 - [1, 3]

1 - [2, 4] - node
2 - [1, 3]
3 - [2, 4]
4 - [1, 3]

1 - [] - newNode
2 - []
*/