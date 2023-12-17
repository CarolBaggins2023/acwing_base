#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        std::vector<int> next(needle.size(), 0);
        for (int i = 1, j = 0; i < needle.size(); ++i) {
            while (j > 0 && needle[j] != needle[i]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                next[i] = j + 1;
                ++j;
            }
        }

        for (int i = 0, j = 0; i < haystack.size(); ++i) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next[j - 1];
            }
            if (needle[j] == haystack[i]) {
                if (j == needle.size() - 1) {
                    return i - needle.size() + 1;
                }
                ++j;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
