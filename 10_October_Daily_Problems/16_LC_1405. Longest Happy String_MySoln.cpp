class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int, char>> pq;
        if(a>0)
            pq.push({a, 'a'});
        if(b>0)
            pq.push({b, 'b'});
        if(c>0)
            pq.push({c, 'c'});

        while(!pq.empty()){
            char ch = pq.top().second;
            int limit = pq.top().first;
            pq.pop();
            if(ans.length()>=2 && ans[ans.length()-1]==ch && ans[ans.length()-2]==ch){
                if(pq.empty()){
                    //we have left with the only ch which can't be pushed in ans
                    return ans;
                }
                char temp=ch;
                int i = limit;
                ch = pq.top().second;
                limit = pq.top().first;
                pq.pop();
                pq.push({i, temp});
            }
            ans.push_back(ch);
            if(--limit > 0){
                pq.push({limit, ch});
            }
        }
        return ans;
    }
};