#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> ans;

        dfs(digits, 0, "", ans);
        return ans;
    }

private:
    const vector<string> digitToLetters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const string& digits, int i, string&& path, vector<string>& ans) {
        if (i == digits.length()) {
            ans.push_back(path);
            return;
        }

        for (const char letter : digitToLetters[digits[i] - '0']) {
            path.push_back(letter);
            dfs(digits, i + 1, move(path), ans);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    
    string digits1 = "23";
    vector<string> result1 = sol.letterCombinations(digits1);
    cout << "Output for Example 1:" << endl;
    for (const string& s : result1) {
        cout << s << " ";
    }
    cout << endl;

    string digits2 = "";
    vector<string> result2 = sol.letterCombinations(digits2);
    cout << "Output for Example 2:" << endl;
    for (const string& s : result2) {
        cout << s << " ";
    }
    cout << endl;

    string digits3 = "2";
    vector<string> result3 = sol.letterCombinations(digits3);
    cout << "Output for Example 3:" << endl;
    for (const string& s : result3) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}