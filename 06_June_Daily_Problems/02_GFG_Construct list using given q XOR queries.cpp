class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int> s;
        s.push_back(0);
        int Xor=0;
        for(int i=0; i<q; i++){
            int op = queries[i][0];
            int val = queries[i][1];
            if(op==0){
                s.push_back(val^Xor);
            }else{
                Xor ^= val;
            }
        }
        for(int& i : s)
            i ^= Xor;
            
        sort(s.begin(), s.end());
        return s;
    }
};