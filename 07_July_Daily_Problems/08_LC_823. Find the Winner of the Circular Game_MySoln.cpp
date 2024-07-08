class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> person(n, 0);
        return winner(person, n, 0, n, k);
    }
    int winner(vector<bool>& person, int n, int index, int person_left, int k){
        if(person_left==1){
            //find the non-killed person
            for(int i=0; i<n; i++){
                if(person[i]==0)
                    return i+1;
            }
        }
        //find the steps needed to the next person from index
        int kill = (k-1)%person_left;
        //find the index of person after kill steps 
        while(kill--){
            index = (index+1)%n;
            while(person[index]==1)//already killed
                index = (index+1)%n;
        }
        person[index] = 1;
        //find the next valid index to start killing
        while(person[index]==1){
            index = (index+1)%n;
        }
        return winner(person, n, index, person_left-1, k);
    }
};