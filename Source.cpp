#include<bits/stdc++.h>
using namespace std;

void print(stack <int> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}
int main() {
    stack <int> st;
    st.push(10);
    st.push(10);
    st.push(10);
    st.push(10);
    st.push(10);

    print(st);
    return 0;
}