class Solution {
public:
    bool isOperator(string s){
        return s=="+" || s=="-" || s=="*" || s=="/";
    }

    int fn(char c,int a,int b){
        if(c=='+') return a+b;
        if(c=='-') return b-a;
        if(c=='*') return a*b;
        if(c=='/') return b/a;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s:tokens){
            if(!isOperator(s)) st.push(stoi(s));
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(fn(s[0],a,b));
            }
        }
        return st.top();

    }
};
