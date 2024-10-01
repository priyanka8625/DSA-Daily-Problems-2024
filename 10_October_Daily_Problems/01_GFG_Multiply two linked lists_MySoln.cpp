class solution {
  public:
    long long mod = 1e9+7;
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long ans=0, n1=0, n2=0;
        while(first){
            int digit = first->data;
            n1 = ((n1*10)%mod + digit)%mod;
            first = first->next;
        }
        while(second){
            int digit = second->data;
            n2 = ((n2*10)%mod + digit)%mod;
            second = second->next;
        }
        ans = (n1*n2)%mod;
        return ans;
    }
};