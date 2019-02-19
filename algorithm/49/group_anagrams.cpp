class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, int> anagramMap;
        vector<vector<string>> res;
        multiset<char> temp;

        for (string &str : strs) {
            temp.clear();
            for (char ch : str)
                temp.insert(ch);
            auto findRes = anagramMap.find(temp);
            if (findRes == anagramMap.end()) {
                anagramMap.emplace(temp, res.size());
                vector<string> line({str});
                res.emplace_back(line);
            } else {
                res[findRes->second].emplace_back(str);
            }
        }
        return res;
    }
};