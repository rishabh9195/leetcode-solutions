class Solution {
public:

    vector<vector<string>> ans;
    vector<int> x;

    bool place(int row, int col)
    {
        for(int j = 0; j < row; j++)
        {
        
            if(x[j] == col)
                return false;

            
            if(abs(x[j] - col) == abs(j - row))
                return false;
        }

        return true;
    }

    void nQueens(int row, int n)
    {
        for(int col = 0; col < n; col++)
        {
            if(place(row, col))
            {
                x[row] = col;

                if(row == n - 1)
                {
                    vector<string> board(n, string(n, '.'));

                    for(int i = 0; i < n; i++)
                        board[i][x[i]] = 'Q';

                    ans.push_back(board);
                }
                else
                {
                    nQueens(row + 1, n);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
         x.resize(n);

        nQueens(0, n);

        return ans;
    }
};