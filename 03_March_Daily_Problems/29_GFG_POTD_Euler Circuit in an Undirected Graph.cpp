class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
       for(int i=0;i<v;i++) {
           if(adj[i].size()&1) return false;
       }
       return true;
    }

};
