class Solution {
  public:
  
    int merge(vector<int> &arr, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;
        int count = 0;
        
        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                count += (mid - i + 1);
            }
        }
        
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int idx = 0; idx < temp.size(); idx++) {
            arr[idx + st] = temp[idx];
        }
        
        return count;
    }
  
    int mergeSort(vector<int> &arr, int st, int end) {
        if(st < end ) {
            int mid = st + (end - st) / 2;
        
            int leftInvcount = mergeSort(arr, st, mid);
            int rightInvcount = mergeSort(arr, mid + 1, end);
            int invCount = merge(arr, st, mid, end);
        
    
            return leftInvcount + rightInvcount + invCount;
        }
        
        return 0;
    }
    
    
    int inversionCount(vector<int> &arr) {
        
        return mergeSort(arr, 0, arr.size() - 1);
        
    }
};