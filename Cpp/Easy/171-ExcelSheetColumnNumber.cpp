class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int columnNumber = 0;
            for(int i = 0; i < columnTitle.size(); i++) columnNumber = columnNumber * 26 + (columnTitle[i] - 'A' + 1);

            return columnNumber;
        }
};