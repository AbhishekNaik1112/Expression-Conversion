#include<bits/stdc++.h>
using namespace std ;

bool isOperand(char ch){
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

string PostfixToInfix(string s){
    stack<string> st;
    
    for(int i=0;s[i]!='\0';i++){
        if(isOperand(s[i])){
            string op(1,s[i]);
            st.push(op);
        }else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("("+op2+s[i]+op1+")");
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    string op = PostfixToInfix(s);
    cout<<op;
    return 0;
}