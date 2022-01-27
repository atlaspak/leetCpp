class Solution {
public:
    bool isValid(string s) {
        stack<char> stackedPart;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stackedPart.push(s[i]);
            }
            else if( stackedPart.size() != 0 &&
                    ((s[i] == ')' && stackedPart.top() == '(') ||
                    (s[i] == ']' && stackedPart.top() == '[') ||
                    (s[i] == '}' && stackedPart.top() == '{'))){
                stackedPart.pop();
            }
            else{
                return false;
            }            
        }
        
        if(stackedPart.size() != 0)
            return false;
        return true;
    }
};
