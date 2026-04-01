class Solution {
  public:
     int countStrings(int n) {
        // code here
        int a=1;
         int b=1;
         int c=0;
         for(int i=1;i<=n;i++)
         {
             c=a+b;
             a=b;
             b=c;
         }
         return c;
    }
};