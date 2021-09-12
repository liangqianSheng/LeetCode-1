#include "headers.h"

class Solution
{
public:
    bool rows[9][9] = {false};
    bool columns[9][9] = {false};
    bool box[3][3][9] = {false};
    vector<pair<int, int>> spaces;
    bool finish = false;

    void dfs(vector<vector<char>> &board, int pos)
    {
        if (pos == spaces.size())
        {
            finish = true;
            return;
        }
        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !finish; ++digit)
        {
            if (!rows[i][digit] && !columns[j][digit] && !box[i / 3][j / 3][digit])
            {
                rows[i][digit] = true;
                columns[j][digit] = true;
                box[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '1';
                dfs(board, pos + 1);
                rows[i][digit] = false;
                columns[j][digit] = false;
                box[i / 3][j / 3][digit] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        //create a vector for spaces
        // bool rows[9][10] = {false};
        // bool columns[9][10] = {false};
        // bool box[3][3][10] = {false};
        // vector<pair<int, int>> spaces;

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    spaces.emplace_back(i, j);
                    continue; //continue!
                }
                int num = board[i][j] - '1';
                rows[i][num] = true;
                columns[j][num] = true;
                box[i / 3][j / 3][num] = true;
            }
        }
        //dfs
        dfs(board, 0);
    }
};

TEST(Sudoku, Sudoku_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.Sudoku(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}