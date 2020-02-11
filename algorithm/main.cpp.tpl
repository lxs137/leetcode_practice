#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <array>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <regex>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};
ListNode* array2ListNodes(vector<int> vals) {
    if (vals.size() == 0) {
        return nullptr;
    }
    ListNode *ptr = nullptr;
    for (auto it = vals.rbegin(); it != vals.rend(); it++) {
        ptr = new ListNode(*it, ptr);
    }
    return ptr;
}
void printListNodes(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
}

class-solution-impl

int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    // vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    // vector<Interval> nums;
    // nums.emplace_back(1, 3);
    // nums.emplace_back(6, 9);
    // vector<vector<int>> matrix({{1}, {4}, {7}});
    // Interval interval(2, 5);
    auto res = solution->uniquePaths(1, 100);
    cout << res << endl;
    // for (auto &line : res) {
    //     for (auto &item : line) {
    //         cout << item << " ";
    //     }
    //     cout << endl;
    // }
}
