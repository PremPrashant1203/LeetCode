class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                for (char c = '1'; c <= '9'; c++) {
                    bool valid = true;

                    for (int k = 0; k < 9; k++) {
                        if (board[i][k] == c || board[k][j] == c) {
                            valid = false;
                            break;
                        }
                    }

                    int r = (i / 3) * 3;
                    int col = (j / 3) * 3;

                    for (int x = r; x < r + 3 && valid; x++) {
                        for (int y = col; y < col + 3; y++) {
                            if (board[x][y] == c) {
                                valid = false;
                                break;
                            }
                        }
                    }

                    if (valid) {
                        board[i][j] = c;

                        if (solve(board)) return true;

                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna