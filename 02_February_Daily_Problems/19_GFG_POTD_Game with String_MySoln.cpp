class Solution{
public:
    int minValue(string s, int k){
        // code here
        //priority queue is a special datastructure which keeps the highest value first in queue and then the lower values
        //sorts the values in ascending order while insertion
        map<char, int> freq;
        priority_queue<int> q;
        //count frequencies of all characters
        for(char ch : s)
            freq[ch]++;
            
        //insert the values of map into q, so that we can access the highest occurance first
        for(auto it : freq)
            q.push(it.second);
        
        //now traverse the q and decrease the occurance of highest values in the q
        while(k != 0){
            int maxOccurance = q.top();
            q.pop();
            q.push(--maxOccurance);
            k--;
        }
        
        //add up the squares of all the occurances
        int sum = 0;
        while(!q.empty()){
            int value = q.top();
            sum += (value*value);
            q.pop();
        }
        
        return sum;
    }
};

//priority_queue<> in c++
// A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, 
// at the expense of logarithmic insertion and extraction. 
// It is implemented as a binary heap, which is a data structure that organizes elements 
// in a tree-like fashion such that the largest element is always at the root of the tree.
