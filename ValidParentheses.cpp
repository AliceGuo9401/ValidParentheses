#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

bool isValid(string s) {
    map<char, char> convertTable{{')', '('}, {'}', '{'}, {']', '['}};
    if (s.empty())
    return true;

    if (s.size() % 2 != 0)
    return false;

    else if (s.size() % 2 == 0) {
        stack<char> charStack;                              //栈stack 定义在头文件stack中
        int flag(0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                charStack.push(s[i]);                       //push(item)新元素压入栈顶
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (charStack.empty())  /**/
                    return false;
                    
                char temp = s[i];
                if (convertTable[temp] == charStack.top())  //top()返回栈顶元素
                    charStack.pop();                        //pop()删除栈顶元素
                else if (convertTable[temp] != charStack.top()) {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1 || !charStack.empty())                //flag == 1 或者charStack非空，return false
            return false;
        return true;
    }
}

int main() {
    string s("){");
    cout << isValid(s);
    return 0;
}
