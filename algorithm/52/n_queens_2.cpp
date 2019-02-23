typedef pair<int, int> Coord;
typedef array<int, 4> Candidate;

class Solution {
public:
    int solutionsCount = 0;
    vector<Candidate> allCandidates;

    int totalNQueens(int n) {
        if (n <= 1) {
            return n;
        }
        prepare(n);
        vector<Candidate> candidates;
        solve(n, 0, candidates);
        return solutionsCount;
    }
    void solve(int n, int chosen, vector<Candidate> &candidates) {
        if (chosen == n) {
            vector<Coord> solution;
            solutionsCount++;
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
};