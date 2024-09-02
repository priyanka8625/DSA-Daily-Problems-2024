class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int n;
	int row[4] = {-1, 1, 0, 0};
	int col[4] = {0, 0, -1, 1};
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()){
            int ds = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            for(int k=0; k<4; k++){
                int newi = i+row[k], newj = j+col[k];
                if(isValid(newi, newj) && dist[newi][newj]> dist[i][j]+grid[newi][newj]){
                    dist[newi][newj] = dist[i][j] + grid[newi][newj];
                    pq.push({dist[newi][newj], {newi, newj}});
                }
            }
        }
        return dist[n-1][n-1];
    }
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
};