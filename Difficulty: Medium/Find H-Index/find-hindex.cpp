class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
        
        for(int i = 0; i < n; i++) {
            if(citations[i] >= n) {
                freq[n]++;
            } else {
                freq[citations[i]]++;
            }
        }
        
        int HIndex = n;
        int num = freq[n];
        
        while(num < HIndex) {
            HIndex--;
            num = num + freq[HIndex];
        }
        
        return HIndex;
        
    }
};