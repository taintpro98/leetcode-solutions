class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> result;
    result.push_back(0);
    if(n==0) return result;
    result.push_back(1);
    if(n==1) return result;
    result.push_back(1);
    if(n==2) return result;
    
    int min = 2;
    for(int i=3; i<=n; i++){
      cout << 3 << endl;
      if(i == min * 2){
        result.push_back(1);
        min *= 2;
      } else {
        result.push_back(1+result[i-min]);
      }
    }
    return result;
  }
};