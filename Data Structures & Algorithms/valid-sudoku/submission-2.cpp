class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> columnSetsVector(board.size());
        vector<unordered_set<int>> squareSetsVector(9);

        for(int i=0; i<board.size(); i++){
            unordered_set<int> rowSet;
            for(int j=0; j<board[i].size(); j++){
                int n = board[i][j] - '0';
                // row check
                if(board[i][j] != '.'){
                    auto it = rowSet.find(n);
                    if(it != rowSet.end()){
                        return false;
                    }
                    rowSet.insert(n);

                    // column check
                    auto it2 = columnSetsVector[j].find(n);
                    if(it2 != columnSetsVector[j].end()){
                        return false;
                    }
                    columnSetsVector[j].insert(n);

                    // square check
                    int squareIdx = (i/3) *3 + (j/3);
                    auto it3 = squareSetsVector[squareIdx].find(n);
                    if(it3 != squareSetsVector[squareIdx].end()){
                        return false;
                    }
                    squareSetsVector[squareIdx].insert(n);
                }
            }   
        }
        return true;
    }
};
