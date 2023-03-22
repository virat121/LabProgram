/* Design a C++ program to convert and print a given valid parenthesized infix
arithmetic expression to postfix expression. The expression consists of
single character operands and binary operators +, -, *, / and $. Apply the
concept of stack data structure to solve this problem. */
#include <iostream>
#include <stack>
using namespace std;
int precedence(char c)
{
    if (c == '$')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
    /* switch (c)
    {
    case '$':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return -1;
    } */
}
class Expression
{
    string infix;
    string postfix;

public:
    Expression()
    {
        cout << "Enter the infix Expression: ";
        getline(cin, infix);
    }
    void infix_postfix();
};

void Expression::infix_postfix()
{
    stack<char> st;
    string res;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        // Associativity
        else
        {
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top()))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}
int main()
{
    Expression E;
    E.infix_postfix();
    return 0;
}
