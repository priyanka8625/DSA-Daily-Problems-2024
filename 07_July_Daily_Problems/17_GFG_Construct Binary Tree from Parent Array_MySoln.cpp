class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int, Node*> mp;
        Node* root = NULL;

        // First pass to create all nodes
        for (int i = 0; i < parent.size(); i++) {
            if (mp.find(i) == mp.end()) {
                mp[i] = new Node(i);
            }
            if (parent[i] == -1) {
                root = mp[i];
            } else {
                if (mp.find(parent[i]) == mp.end()) {
                    mp[parent[i]] = new Node(parent[i]);
                }
                Node* parentNode = mp[parent[i]];
                if (parentNode->left == NULL) {
                    parentNode->left = mp[i];
                } else {
                    parentNode->right = mp[i];
                }
            }
        }

        return root;
    }
};
