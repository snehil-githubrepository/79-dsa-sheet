class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    //if cell empty 
                    if (board[i][j] == '.') {
                        //try putting 1 - 9 digits
                        for (char c = '1'; c <= '9'; c++) {
                            //isValid will check if we can put the digit at that cell
                            if (isValid(board, i, j, c)) {
                                board[i][j] = c;
                                
                                //true => we placed digit at right place
                                if (solve(board))
                                return true;
                                else {
                                //if not then we need to remove last placed digit
                                //backtrack 
                                board[i][j] = '.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            //we have filled everything in board
            return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == c) return false;
            
            if(board[row][i] == c) return false;
            
            //now we can divide 9x9 in 3x3 right 

            // |  -|  
            // |  => 3  (0)
            // |  _|
            // |  -|
            // |  => 3  (1)
            // |  _|
            // |  -|
            // |  => 3  (2)
            // |  _|      

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;

        }
        return true;
    };
};