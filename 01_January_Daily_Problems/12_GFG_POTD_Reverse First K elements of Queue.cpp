class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here..
        stack<int>s;
        int n=q.size();
        while(k--)
        {
            s.push(q.front());
            q.pop();
            n--;
        }
        while(!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        while(n--)
        {
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};
