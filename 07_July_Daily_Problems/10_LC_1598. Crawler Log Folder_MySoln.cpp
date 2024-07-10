class Solution {
public:
    int minOperations(vector<string>& logs) {
        //preform operations:
        //1. x/ => increment count
        //2. ./ => no change 
        //3. ../ => decrement count if not zero
        int count=0, n=logs.size();
        for(int i=0; i<n; i++){
            if(logs[i]=="./"){
                continue;
            }
            if(logs[i]=="../"){
                if(count!=0)
                count--;
            }else{
                count++;
            }
        }
        return count;
    }
};