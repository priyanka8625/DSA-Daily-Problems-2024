// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            pq.push(nuts[i]);
        }
        
        int index=0;
        while(!pq.empty()){
            char minNut = pq.top();
            pq.pop();
            nuts[index] = minNut;
            bolts[index] = minNut;
            index++;
        }
    }
};