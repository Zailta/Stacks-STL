//code for infix to post fix expression :
#include<bits/stdc++.h> 
using namespace std;

int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixToPostfix(string s) {
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;

    //checking for the character value in the stack
    for (int i = 0; i < l; i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            ns = ns + s[i];
        else if (s[i] == '(')
            st.push('(');
        else if (s[i] == ')') {
            while (st.top() != 'N' && st.top() != '(') {
                char c = st.top();
                st.pop();
                ns += c;
            }
            if (st.top() == '(') {
                char c = st.top();
                st.pop();
            }
        }

        //now check priority of the operator;
        else {
            while (st.top() != 'N' && priority(s[i]) <= priority(st.top())) {
                char c = st.top();
                st.pop();
                ns += c;

            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N') {
        char c = st.top();
        st.pop();
        ns += c;

    }
   
    cout << ns << endl;

}
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);

    cout << "done";
    return 0;
}