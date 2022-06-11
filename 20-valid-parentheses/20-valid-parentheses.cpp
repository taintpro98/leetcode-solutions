class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 1) return false;
        stack<char> stack;
        map<char, int> encode;
        encode['('] = 1;
        encode['{'] = 2;
        encode['['] = 3;
        encode[')'] = -1;
        encode['}'] = -2;
        encode[']'] = -3;
        
        for(int i=0; i < s.length(); i++){
            if(stack.empty()){
                if(encode[s[i]] < 0) return false;
                stack.push(s[i]);
            } else {
                char top = stack.top();
                if(encode[top] * encode[s[i]] > 0){
                    stack.push(s[i]);
                } else {
                    if(encode[top] + encode[s[i]] != 0) return false;
                    else {
                        stack.pop();
                    }
                }
            }
        }
        if(!stack.empty()) return false;
        return true;
    }
};