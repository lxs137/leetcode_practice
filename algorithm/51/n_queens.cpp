typedef pair<int, int> Coord;
typedef array<int, 4> Candidate;

class Solution {
public:
    vector<vector<Coord>> solutions;
    vector<Candidate> allCandidates;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0) {
            return res;
        } else if (n == 1) {
            vector<string> line({"Q"});
            res.emplace_back(line);
            return res;
        }
        prepare(n);
        vector<Candidate> candidates;
        solve(n, 0, candidates);
        for (auto &solution : solutions) {
            res.emplace_back(showStrSolution(n, solution));
        }
        return res;
    }
    void solve(int n, int chosen, vector<Candidate> &candidates) {
        if (chosen == n) {
            vector<Coord> solution;
            cout << "\nsolution: \n\t";
            for (auto &item : candidates) {
                cout << "(" << item[0] << "," << item[1] << ") ";
                solution.emplace_back(item[0], item[1]);
            }
            solutions.emplace_back(solution);
        } else if (chosen == 0) {
            for (auto &item : allCandidates) {
                candidates.push_back(item);
                solve(n, chosen + 1, candidates);
                candidates.pop_back();
            }
        } else {
            Candidate &lastChosen = candidates.back();
            for (int i = lastChosen[0] * n + lastChosen[1] + 1, size = n * n; i < size; i++) {
                Candidate candidate = allCandidates[i];
                bool canChosen = true;
                for (auto &item : candidates) {
                    if (item[0] == candidate[0] 
                        || item[1] == candidate[1]
                        || item[2] == candidate[2]
                        || item[3] == candidate[3]) {
                        canChosen = false;
                        break;
                    }
                }
                if (canChosen) {
                    candidates.push_back(candidate);
                    solve(n, chosen + 1, candidates);
                    candidates.pop_back();
                }
            }
        }
    }
    void prepare(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Candidate candidate = {i, j, i + j, i - j};
                allCandidates.emplace_back(candidate);
            }
        }
    }
    vector<string> showStrSolution(int n, vector<Coord> &solution) {
        vector<string> res;
        for (int i = 0; i < n; i++) {
            res.emplace_back(n, '.');
        }
        for (auto &item : solution) {
            res[item.first][item.second] = 'Q';
        }
        return res;
    }
};