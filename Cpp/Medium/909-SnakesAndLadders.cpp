/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
    private:
        pair<int, int> getCoordinate(int square, int boardSize) {
            int quotient = (square - 1) / boardSize;
            int remainder = (square - 1) % boardSize;
            int row = boardSize - 1 - quotient;
            int col = quotient % 2 == 0 ? remainder : boardSize - 1 - remainder;
            return make_pair(row, col);
        }

    public:
        int snakesAndLadders(vector<vector<int>> &board) {
            if(board.empty() || board[0].empty()) return 0;
            int boardSize = board.size();
            int minSteps = 0;

            queue<int> q;
            vector<bool> visited(boardSize * boardSize + 1, false);

            q.push(1);
            visited[1] = true;

            while (!q.empty()) {
                int currentQueueSize = q.size();

                for(int i = 0; i < currentQueueSize; i++) {
                    int currentSquare = q.front();
                    q.pop();

                    if(currentSquare == boardSize * boardSize) return minSteps;

                    for(int nextSquare = currentSquare + 1; nextSquare <= min(boardSize * boardSize, currentSquare + 6); nextSquare++) {
                        pair<int,int> nextSquareCoordinate = getCoordinate(nextSquare, boardSize);
                        int nextSquareRow = nextSquareCoordinate.first;
                        int nextSquareCol = nextSquareCoordinate.second;
                        int destinationSquare = board[nextSquareRow][nextSquareCol] == -1 ? nextSquare : board[nextSquareRow][nextSquareCol];

                        if(!visited[destinationSquare]) {
                            q.push(destinationSquare);
                            visited[destinationSquare] = true;
                        }
                    }
                }

                minSteps++;
            }

            return -1;
        }
};
// @lc code=end
