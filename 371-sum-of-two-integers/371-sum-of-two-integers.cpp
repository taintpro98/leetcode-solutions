class Solution {
public:
  string number2bits(int a){
    stack<int> st;
    int r;
    while(a){
      r = a % 2;
      st.push(r);
      a /= 2;
    }
    string res = "";
    while(!st.empty()){
      res += st.top(); st.pop();
    }
    return res;
  }
  
  int bits2number(string s){
    int n = s.length();
    int res = 0;
    int multiples = 1;
    for(int i=0; i<n; i++){
      res += (int)(s[n-1-i]) * multiples;
      multiples *= 2;
    }
    return res;
  }
  
//   string getBitsSum(string a, string b){
//     int m = a.length(), n = b.length();
//     int carry = 0;
//     for(int i=0; i<max(m,n); i++){
//       if(i<min(m, n)){
//         int aIdx = m-1-i;
//         int bIdx = n-1-i;
//         int tmp = (int)(a[aIdx])
//       } else {
        
//       }
//     }
//   }
  
  int getSum(int a, int b) {
    int res;
        if(a>0 ){   // a is (+)ve
             while(a--){
                b++;
            }
            res = b;
        }
        else if(b>0){   // b is (+)ve
            while(b--){
                a++;
            }
            res = a;
        }
        else {     // when both are negative---
            while(a++){
                b--;
            }
            res = b;
        }
        return res;
  }
};