#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp;
        return found;
    }
};

/*
 * Approach: Depth-First Search (DFS) with Backtracking
 * * Logic:
 * 1. Iteration: We loop through every cell in the grid. The moment we find a cell
 * that matches the first character of 'word', we launch a recursive DFS helper.
 * 2. Recursion (DFS): The function 'dfs' attempts to build the rest of the word
 * starting from (i, j).
 * - Base Case (Success): If 'index' equals the word length, we have matched everything. Return true.
 * - Base Case (Fail): If we go out of bounds (i, j invalid) or if board[i][j]
 * does not match word[index], we return false.
 * 3. Visited Management: The problem forbids using the same cell twice in a single word path.
 * - Instead of using a separate O(M*N) 'visited' boolean matrix, we save space by modifying
 * the board in-place.
 * - We store the current character in 'temp' and overwrite board[i][j] with '#' (or any non-alpha char).
 * 4. Exploration: We recursively call 'dfs' for neighbors (i+1, i-1, j+1, j-1) looking
 * for 'index + 1'.
 * 5. Backtracking: After the recursive calls return, we MUST restore board[i][j]
 * to 'temp'. This "un-visits" the cell, allowing other potential paths starting
 * from different locations to use this cell later.
 * * Time Complexity: O(N * 3^L)
 * N is the number of cells. L is the length of the word. For each cell, we explore
 * 3 directions (we don't go back where we came from) for depth L.
 * * Space Complexity: O(L)
 * The recursion stack depth is equal to the length of the word.
 */