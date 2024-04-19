class Solution{

	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    vector<int> ans;
	    unordered_set<int> b_elements;
	    for(int i=0; i<m; i++){
	        b_elements.insert(b[i]);
	    }
	    for(int i=0; i<n; i++){
	        if(b_elements.find(a[i]) == b_elements.end())//element not found
	            ans.push_back(a[i]);
	    }
	    return ans;
	} 
};