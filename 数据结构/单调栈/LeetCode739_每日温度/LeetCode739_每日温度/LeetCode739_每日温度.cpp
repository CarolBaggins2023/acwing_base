#include <deque>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int, std::deque<int>> stk;
        stk.push(temperatures.size() - 1);
        res[temperatures.size() - 1] = 0;
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            res[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
