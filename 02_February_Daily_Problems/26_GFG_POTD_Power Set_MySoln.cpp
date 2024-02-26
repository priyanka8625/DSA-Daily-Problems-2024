class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int index=0;
		    vector<string> ans;
		    string temp="";
		    generate(s, index, temp, ans, s.length());
		    sort(ans.begin(), ans.end());
		    return ans;
		}
		void generate(string &s, int index, string &temp, vector<string> &ans, int n){
		    if(index == n){
		        if(temp.length()){
		            ans.push_back(temp);
		        }
		        return;
		    }
		    
		    //pick the current char
		    temp.push_back(s[index]);
		    generate(s, index+1, temp, ans, n);
		    temp.pop_back();
		    //not pick
		    generate(s, index+1, temp, ans, n);
		}
};