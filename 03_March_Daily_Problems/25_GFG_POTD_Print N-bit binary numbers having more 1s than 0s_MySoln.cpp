class Solution{
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    string number="";
	    vector<string> ans;
	    generateNumbers(n, 0, 0, number, ans);
	    return ans;
	}
	void generateNumbers(int n, int ones, int zeros, string& temp, vector<string>& ans){
	    if(temp.size() == n){
	        ans.push_back(temp);
	        return;
	    }
	    //first add one
	    temp.push_back('1');
	    generateNumbers(n, ones+1, zeros, temp, ans);
	    temp.pop_back();
	    
	    if(zeros<ones){
	        temp.push_back('0');
	        generateNumbers(n, ones, zeros+1, temp, ans);
	        temp.pop_back();
	    }
	}
};