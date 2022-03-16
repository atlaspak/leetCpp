class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> testStack;
        int popIndex = 0;
        
        for(int i = 0; i < pushed.size(); i++){
            if(pushed[i] == popped[popIndex]){
                popIndex++;
                while(!testStack.empty() && testStack.top() == popped[popIndex]){                    
                    popIndex++;
                    testStack.pop();
                }
            }
            else{
                testStack.push(pushed[i]);
            }
        }
        
        while(!testStack.empty()){
            if(popped[popIndex] == testStack.top()){
                popIndex++;
                testStack.pop();
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};
