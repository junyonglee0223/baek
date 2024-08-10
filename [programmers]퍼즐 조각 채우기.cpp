#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define x first
#define y second 
typedef pair<int, int> p;

struct Piece {
    vector<p> cells;
    int weight, height;

    Piece() {
        this->weight = 0;
        this->height = 0;
    }

    Piece(vector<p> _cells) {
        this->cells = _cells;
        normalize_cell();
    }

    void normalize_cell() {
        int minX = 1e9, minY = 1e9;
        for (const auto& cell : cells) {
            minX = min(minX, cell.x);
            minY = min(minY, cell.y);
        }
        for (auto& cell : cells) {
            cell.x -= minX;
            cell.y -= minY;
        }
        weight = 0;
        height = 0;
        for (const auto& cell : cells) {
            weight = max(weight, cell.x);
            height = max(height, cell.y);
        }
        sort(cells.begin(), cells.end());
    }

    void rotate_clockwise() {
        for (auto& cell : cells) {
            int temp = cell.x;
            cell.x = cell.y;
            cell.y = -temp;
        }
        normalize_cell();
    }

    bool equals(const Piece& other) const {
        if (cells.size() != other.cells.size()) return false;
        for (size_t i = 0; i < cells.size(); ++i) {
            if (cells[i] != other.cells[i]) return false;
        }
        return true;
    }
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isInRange(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, const vector<vector<int>>& board, vector<vector<bool>>& visited, vector<p>& cells, int target) {
    int n = board.size();
    queue<p> q;
    q.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();

        cells.push_back({ curX, curY });

        for (int i = 0; i < 4; ++i) {
            int nxtX = curX + dx[i];
            int nxtY = curY + dy[i];

            if (isInRange(nxtX, nxtY, n) && !visited[nxtX][nxtY] && board[nxtX][nxtY] == target) {
                visited[nxtX][nxtY] = true;
                q.push({ nxtX, nxtY });
            }
        }
    }
}

vector<Piece> extract_pieces(const vector<vector<int>>& board, int target) {
    int n = board.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<Piece> pieces;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j] && board[i][j] == target) {
                vector<p> cells;
                bfs(i, j, board, visited, cells, target);
                pieces.push_back(Piece(cells));
            }
        }
    }

    return pieces;
}

int match_pieces(vector<Piece>& board_pieces, vector<Piece>& table_pieces) {
    int matched_area = 0;

    for (auto it_b = board_pieces.begin(); it_b != board_pieces.end(); ) {
        bool matched = false;

        for (auto it_t = table_pieces.begin(); it_t != table_pieces.end(); ) {
            Piece& table_piece = *it_t;

            for (int rotation = 0; rotation < 4; ++rotation) {
                if (it_b->equals(table_piece)) {
                    matched_area += it_b->cells.size();
                    it_t = table_pieces.erase(it_t);
                    it_b = board_pieces.erase(it_b);
                    matched = true;
                    break;
                }
                table_piece.rotate_clockwise();
            }
            if (matched) break;
            else ++it_t;
        }

        if (!matched) {
            ++it_b;
        }
    }

    return matched_area;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<Piece> board_pieces = extract_pieces(game_board, 0); 
    vector<Piece> table_pieces = extract_pieces(table, 1);

    int answer = match_pieces(board_pieces, table_pieces); 
    return answer;
}

int main() {
    vector<vector<int>> game_board = {
        {1, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 0}
    };

    vector<vector<int>> table = {
        {1, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}
    };

    int result = solution(game_board, table);
    cout << "Result: " << result << endl;

    return 0;
}
