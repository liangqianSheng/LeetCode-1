#include "headers.h"

class Solution
{
public:
    void dfs(vector<string> &combinations,
             const unordered_map<char, string> &phoneMap, const string &digits,
             int index, string &combination)
    {
        if (index == digits.length())
        {
            combinations.push_back(combination);
            return; //出口
        }
        char digit = digits[index];
        const string &letters = phoneMap.at(digit);
        for (const char &letter : letters)
        {
            combination.push_back(letter);
            dfs(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }

    vector<string> LetterCombinationsofaPhoneNumber(string digits)
    {
        vector<string> combinations;
        if (digits.empty())
        {
            return combinations;
        }
        unordered_map<char, string> phoneMap{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        string combination;
        dfs(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }
};

TEST(LetterCombinationsofaPhoneNumber, LetterCombinationsofaPhoneNumber_1)
{
    Solution s;
    string in = "23";
    vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(s.LetterCombinationsofaPhoneNumber(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}