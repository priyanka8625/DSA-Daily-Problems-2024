struct Node *insert(struct Node *head, int data) {
    // Code here
    Node *temp = new Node(data);
    temp->npx = XOR(head, temp);
    head = temp;
    return head;
}

vector<int> getList(struct Node *head) {
    // Code here
    vector<int> ans;
    while(head){
        ans.push_back(head->data);
        head = XOR(head, head->npx);
    }
    return ans;
}
