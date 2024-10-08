
//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };


class Solution {
public:
    // Function to clone a graph
    Node* cloneGraph(Node* node) {
        // If the node is NULL, return NULL
        if (!node) {
            return NULL;
        }
        // If the node is not present in the map, create a copy of it
        if (copies.find(node) == copies.end()) {
            // Create a new node with the same value as the original node
            copies[node] = new Node(node -> val, {});
            // Copy the neighbors of the original node recursively
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        // Return the copy of the node
        return copies[node];
    }
private:
    // Map to store the copy of the nodes
    unordered_map<Node*, Node*> copies;
};