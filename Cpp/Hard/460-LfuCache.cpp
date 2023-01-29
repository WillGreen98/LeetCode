/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
struct Node {
    int key;
    int val;
    int cnt;
    Node(int k, int v) : key(k), val(v), cnt(1) {}
};

class LFUCache {
    private:
        int capacity;
        int size;
        std::unordered_map<int, Node*> m;
        std::map<int, std::list<Node*>> freq;

        void updateNode(Node* node) {
            freq[node->cnt].remove(node);
            if(freq[node->cnt].size() == 0) freq.erase(node->cnt);
            node->cnt++;
            freq[node->cnt].push_back(node);
        }

    public:
        LFUCache(int capacity) : capacity(capacity), size(0) {}

        int get(int key) {
            if(m.count(key) == 0) return -1;
            auto node = m[key];
            updateNode(node);

            return node->val;
        }

        void put(int key, int value) {
            if(capacity <= 0) return;

            if(m.count(key) != 0) {
                auto node = m[key];
                node->val = value;
                updateNode(node);

                return;
            }

            if(size == capacity) {
                auto it = freq.begin();
                auto node = *it->second.begin();

                freq[node->cnt].pop_front();
                if(freq[node->cnt].size() == 0) freq.erase(node->cnt);
                m.erase(node->key);
                size--;
            }

            auto node = new Node(key, value);

            m[key] = node;
            freq[1].push_back(node);
            size++;
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
