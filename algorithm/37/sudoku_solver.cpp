typedef pair<int, int> Coord;
typedef array<vector<Coord>, 3> Units;
typedef vector<Coord> Peers;

class Solution {
public:
    map<Coord, Units> unitsMap;
    map<Coord, Peers> peersMap;
    void solveSudoku(vector<vector<char>>& board) {
        prepare();
        if (solveByUniqueCandidate(board))
            return;        
        search(board);
    }
    bool search(vector<vector<char>>& board) {
        vector<pair<Coord, vector<char>>> candidates;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                Coord coord = make_pair(i, j);
                if (board[i][j] != '.')
                    continue;
                vector<char> candidate = getCandidate(coord, board);
                if (candidate.size() == 0) {
                    return false;
                }
                else
                    candidates.emplace_back(coord, candidate);
            }
        }
        if (candidates.size() == 0)
            return true;
        sort(candidates.begin(), candidates.end(), [](pair<Coord, vector<char>> &a, pair<Coord, vector<char>> &b) {
            return a.second.size() < b.second.size();
        });
        auto selected = candidates.begin();
        int i = selected->first.first, j = selected->first.second;
        for (char ch : selected->second) {
            board[i][j] = ch;
            if (search(board))
                return true;
        }
        board[i][j] = '.';
        return false;
    }
    // @return: has solved
    bool solveByUniqueCandidate(vector<vector<char>> &board) {
        bool hasSetCell = false, hasEmptyCell = false;
        do {
            hasSetCell = false;
            hasEmptyCell = false;
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    Coord coord = make_pair(i, j);
                    if(board[i][j] != '.')
                        continue;
                    vector<char> candidateCh = getCandidate(coord, board);
                    if(candidateCh.size() == 1) {
                        board[i][j] = candidateCh[0];
                        hasSetCell = true;
                    } else {
                        hasEmptyCell = true;
                    }
                }
            }
            cout << "epoch..." << endl;
        } while(hasSetCell && hasEmptyCell);
        return !hasEmptyCell;
    }
    vector<char> getCandidate(Coord &coord, vector<vector<char>> &board) {
        vector<char> candidate({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        set<char> candidateSet(candidate.begin(), candidate.end());
        Peers &peers = peersMap.at(coord);
        for(auto &item : peers) {
            candidateSet.erase(board[item.first][item.second]);
        }
        candidate.assign(candidateSet.begin(), candidateSet.end());
        return candidate;
    }
    void printCandidates(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                Coord coord = make_pair(i, j);
                if(board[i][j] != '.') {
                    cout << "(" << i << "," << j << "):   " << board[i][j] << endl;
                    continue;
                }
                vector<char> candidateCh = getCandidate(coord, board);
                cout << "(" << i << "," << j << "): ? ";
                for(auto &ch : candidateCh)
                    cout << ch << " ";
                cout << endl;
            }
        }
    }
    void prepare() {
        vector<vector<Coord>> units;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int sub_i = 3* (i / 3), sub_j = 3 * (j / 3);
                vector<Coord> unit1({
                    make_pair(i, j), make_pair(i, (j+1)%9), make_pair(i, (j+2)%9),
                    make_pair(i, (j+3)%9), make_pair(i, (j+4)%9), make_pair(i, (j+5)%9),
                    make_pair(i, (j+6)%9), make_pair(i, (j+7)%9), make_pair(i, (j+8)%9)
                }), unit2({
                    make_pair(i, j), make_pair((i+1)%9, j), make_pair((i+2)%9, j),
                    make_pair((i+3)%9, j), make_pair((i+4)%9, j), make_pair((i+5)%9, j),
                    make_pair((i+6)%9, j), make_pair((i+7)%9, j), make_pair((i+8)%9, j)
                }), unit3({
                    make_pair(sub_i, sub_j), make_pair(sub_i, sub_j+1), make_pair(sub_i, sub_j+2),
                    make_pair(sub_i+1, sub_j), make_pair(sub_i+1, sub_j+1), make_pair(sub_i+1, sub_j+2),
                    make_pair(sub_i+2, sub_j), make_pair(sub_i+2, sub_j+1), make_pair(sub_i+2, sub_j+2)
                });

                Peers peers(unit3);
                auto itself = find(peers.begin(), peers.end(), make_pair(i, j));
                if (itself != peers.end())
                    peers.erase(itself);
                for(int k = 3; k < 9; k++) {
                    peers.emplace_back(i, (sub_j+k)%9);
                    peers.emplace_back((sub_i+k)%9, j);
                }

                Units units({unit1, unit2, unit3});
                unitsMap.emplace(make_pair(i, j), units);
                peersMap.emplace(make_pair(i, j), peers);
            }
        }
    }
    void printPrepare() {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                Coord coord = make_pair(i, j);
                Units &units = unitsMap.at(coord);
                Peers &peers = peersMap.at(coord);
                cout << "(" << coord.first << "," << coord.second << "):\n    ";
                for(int u_i = 0; u_i < 3; u_i++) {
                    for(auto &item : units[u_i])
                        cout << item.first << "," << item.second << "  ";
                    cout << endl << "    ";
                }
                for(auto &item : peers)
                    cout << item.first << "," << item.second << "  ";
                cout << endl;
            }
        }
    }
};