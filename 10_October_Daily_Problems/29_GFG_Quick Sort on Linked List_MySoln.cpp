class Solution {
  public:
    struct Node* quickSort(struct Node* head) {
        // code here
        vector<int> arr;
        getElements(head, arr);
        
        quickSort(arr, 0, arr.size()-1);
        
        Node *temp = head;
        int i=0;
        while(temp){
            temp->data = arr[i++];
            temp = temp->next;
        }
        return head;
    }
    void quickSort(vector<int>& arr, int start, int end){
        if(start>=end){
            return;
        }
        int pivot = find(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
    int find(vector<int>& arr, int start, int end){
        int count=0;
        for(int i=start+1; i<=end; i++){
            if(arr[i]<=arr[start]){
                count++;
            }
        }
        int pivotIndex = start+count;
        swap(arr[start], arr[pivotIndex]);
        
        
        int i=start, j=end;
        while(i<pivotIndex && j>pivotIndex){
            while(i<pivotIndex && arr[i]<=arr[pivotIndex])
                i++;
            while(j>pivotIndex && arr[j]>arr[pivotIndex])
                j--;
            if(i<pivotIndex && j>pivotIndex){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        return pivotIndex;
    }
    void getElements(Node* head, vector<int>& arr){
        if(!head){
            return;
        }
        arr.push_back(head->data);
        getElements(head->next, arr);
    }
};
