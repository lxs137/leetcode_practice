class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        else if (n == 2)
            return "11";
        string prevStr = "11";
        int chCounter = 0;
        char prevCh;
        string nextStr = "";
        while (n > 2) {
            prevCh = prevStr[0];
            chCounter = 1;
            for(int i = 1; i <= prevStr.size(); i++) {
                if (prevStr[i] != prevCh || i == prevStr.size()) {
                    nextStr.push_back('0' + chCounter);
                    nextStr.push_back(prevCh);
                    prevCh = prevStr[i];
                    chCounter = 1;
                } else {
                    chCounter++;
                }
            }
            prevStr = nextStr;
            nextStr = "";
            n--;
        }
        return prevStr;
    }
};