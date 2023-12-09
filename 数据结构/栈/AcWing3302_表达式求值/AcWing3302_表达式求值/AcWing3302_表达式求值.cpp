#include <deque>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>

void Eval(std::stack<int, std::deque<int>> &nums, std::stack<char, std::deque<char>> &ops) {
    int num2 = nums.top();
    nums.pop();
    int num1 = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();

    if (op == '+') {
        nums.push(num1 + num2);
    } else if (op == '-') {
        nums.push(num1 - num2);
    } else if (op == '*') {
        nums.push(num1 * num2);
    } else {
        nums.push(num1 / num2);
    }
}

int main(int argc, char* argv[])
{
    std::map<char, int> prio{{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'(', -1}};
    
    std::string exp;
    std::cin >> exp;

    std::stack<int, std::deque<int>> nums;
    std::stack<char, std::deque<char>> ops;
    for (int i = 0; i < exp.size(); ++i) {
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            int j = i + 1;
            while (j < exp.size() && isdigit(exp[j])) {
                num = num * 10 + (exp[j] - '0');
                ++j;
            }
            nums.push(num);
            i = j - 1;
            
            continue;
        }
        
        if (exp[i] == '(') {
            ops.push(exp[i]);
        } else if (exp[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                Eval(nums, ops);
            }
            ops.pop();
        } else {
            bool need_eval = (!ops.empty()) && (prio[exp[i]] <= prio[ops.top()]);
            while (need_eval) {
                Eval(nums, ops);
                need_eval = (!ops.empty()) && (prio[exp[i]] <= prio[ops.top()]);
            }
            ops.push(exp[i]);
        }
    }    

    while (!ops.empty()) {
        Eval(nums, ops);
    }
    
    std::cout << nums.top();
    
    return 0;
}
