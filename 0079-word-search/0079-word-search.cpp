class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;
    bool find(vector<vector<char>>& board, string& word, int i, int j, int idx) {

        if(word.length() == idx) {
            return true;
        }

        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }

        if(board[i][j] != word[idx]) {
            return false;
        }



        // mark visit
        char temp = board[i][j];

        board[i][j] = '$';


        // explore
        for(auto& dir: directions) {

            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(find(board, word, i_, j_, idx + 1)) {
                return true;
            }
        }

        // revert back
        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++) {

            for(int j=0; j<n; j++) {

                if(board[i][j] == word[0] && find(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};