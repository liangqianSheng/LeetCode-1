#include "headers.h"

class Solution
{
public:
    int Longest(vector<int> &nums)
    {
        return 1;
    }
};

TEST(Longest, Longest_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.Longest(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}