class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count=0;
        while(n!=0)
        {
            if(n&1)  //bitwise AND operator
            {
                count++;
            }
           n= n>>1;   // right shift by 1
        }
        return count;        
  }
};