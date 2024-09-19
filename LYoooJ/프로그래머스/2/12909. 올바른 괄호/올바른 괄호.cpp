#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk; 
    for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
        if (!stk.empty() && stk.top() == '(' && *iter == ')')
            stk.pop();
        else
            stk.push(*iter);
    }

    return stk.empty();
}