class Solution {
public:
    bool isValid(string s) {

        stack<char> st;


        for(char& c: s) {

            if(c == '[') {
                st.push(']');
            } else if(c == '{') {
                st.push('}');
            } else if(c == '(') {
                st.push(')');
            } else if(st.empty() || st.top() != c) {
                return false;
            } else {
                st.pop();
            }
        }
        
        return st.empty();
        
        
        // stack<char> st;

        // for (int i = 0; i < s.length(); i++) {

        //     if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        //         st.push(s[i]);
        //     } else {

        //         if (st.empty()) {
        //             return false;
        //         } 

        //         char top = st.top();

        //         if ((s[i] == ')' && top == '(') ||
        //             (s[i] == ']' && top == '[') ||
        //             (s[i] == '}' && top == '{')) {
        //             st.pop();
        //         } else {
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }
};