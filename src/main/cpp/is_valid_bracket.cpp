/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

#include <stdio.h>

#include <string>
#include <vector>

bool isValid(std::string str) {
    if (str.size() == 0) {
        return true;
    }

    std::vector<char> stack(str.size());
    uint32_t top = 0;

    for (int i = 0; i < str.size(); ++i) {
        char c = str.at(i);
        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else {
            if (--top < 0) {
                return false;
            }
            if (c == ')' && stack[top] != '(') {
                return false;
            }
            if (c == ']' && stack[top] != '[') {
                return false;
            }
            if (c == '}' && stack[top] != '{') {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    printf("%d\n", isValid("()"));
    printf("%d\n", isValid("()[]{}"));
    printf("%d\n", isValid("(]"));
    printf("%d\n", isValid("([)]"));
    printf("%d\n", isValid("{[]}"));
}
