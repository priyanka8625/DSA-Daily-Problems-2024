class Solution {
public:
    //row an column values for U, D L, R directions
    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check full word can be created from the current index, if yes return true
                if(checkPath(board, word, 0, i, j, visited, m, n))
                    return true;
            }
        }
        return false;
    }
    bool checkPath(vector<vector<char>>& board, string &word, int index, int i, int j, vector<vector<bool>>& visited, int m, int n){
        if(index == word.size()-1){
            if(word[index] == board[i][j])
                return 1;//we found the word
            return 0;
        }


        //if current character doesn't match with word ->exit
        if(board[i][j] != word[index])
            return 0;

        //visit current cell
        visited[i][j] = 1;
        //for all the four direction
        for(int k=0; k<4; k++){
            if(valid(i+rows[k], j+cols[k], m, n) && !visited[i+rows[k]][j+cols[k]]){
                //if path is valid and exists 
                //if there's present any path in matrix then return it, else go for other directions 
                if(checkPath(board, word, index+1, i+rows[k], j+cols[k], visited, m, n))  {
                    visited[i][j] = 0;
                    return true;
                }
            }
        }
        //if no directions return true, it means the word doesn't exist so return false
        visited[i][j]=0;
        return false;
    }
    bool valid(int i, int j, int m, int n) {
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;
    }
};