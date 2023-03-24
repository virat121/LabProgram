// Evaluation of postfix expression
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
// only for single digit number
int evalPostfix(string &s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand2 / operand1);
                break;
            case '^':
                st.push(pow(operand2, operand1));
            }
        }
    }
    return st.top();
}
int main()
{
    string p_expr;
    cout << "Enter the Postfix Expression: ";
    getline(cin, p_expr);
    cout << evalPostfix(p_expr) << endl;
    return 0;
}
