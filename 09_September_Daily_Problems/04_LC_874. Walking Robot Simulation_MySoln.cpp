class Solution {
    //directions: up, right, down, left
    int x_dir[4] = {0, 1, 0, -1};
    int y_dir[4] = {1, 0, -1, 0};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int maxDistance = 0;
        int x=0, y=0, dir=0;
        unordered_set<string> obstacle_set;
        for(auto obstacle : obstacles){
            obstacle_set.insert(to_string(obstacle[0])+", "+to_string(obstacle[1]));
        }
        for(int command : commands){
            if(command == -2){
                dir = (dir+3)%4;
            }else if(command == -1){
                dir = (dir+1)%4;
            }else{
                for(int i=0; i<command; i++){
                    int newx = x + x_dir[dir];
                    int newy = y + y_dir[dir];
                    if(obstacle_set.find(to_string(newx)+", "+to_string(newy)) != obstacle_set.end())
                        break;
                    x = newx;
                    y = newy;
                    maxDistance = max(maxDistance, x*x + y*y);
                }
            }
        }
        return maxDistance;
    }
};