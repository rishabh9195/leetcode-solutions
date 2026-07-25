class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rows(9);
        vector<set<char>> cols(9);
        vector<set<char>> box(9);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;

                char ch=board[i][j];

                int boxindex= (i/3)*3+(j/3);

                if(rows[i].count(ch)||cols[j].count(ch)||box[boxindex].count(ch))
                return false;

                rows[i].insert(ch);
                cols[j].insert(ch);
                box[boxindex].insert(ch);
            }
        }
        return true;
    }
};