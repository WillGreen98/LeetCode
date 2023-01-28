/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
    set<int> values;

    public:
        SummaryRanges() {}

        void addNum(int value) { values.insert(value); }

        vector<vector<int>> getIntervals() {
            vector<vector<int>> res;
            auto it = values.begin();

            while(it != values.end()) {
                int start = *it;
                int end = start;

                while(it != values.end() && *it == end) end++, it++;
                res.push_back({start, end - 1});
            }

            return res;
        }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end