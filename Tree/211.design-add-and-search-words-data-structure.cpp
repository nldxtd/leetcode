/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class TreeNod {
public:
    bool word;
    TreeNod* children[26];
    TreeNod() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    TreeNod* root; 
    WordDictionary() {
        root = new TreeNod();
    }
    
    void addWord(string word) {
        TreeNod* node = root;
        for (auto c : word) {
            if (!node->children[c-'a']) {
                node->children[c-'a'] = new TreeNod();
            }
            node = node->children[c-'a'];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }

    bool searchWord(TreeNod* node, string& word, int index) {
        if (node == nullptr) return false;
        if (index == word.size()) { return node->word; }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchWord(node->children[i], word, index+1)) return true;
            }
            return false;
        } else {
            return searchWord(node->children[word[index]-'a'], word, index+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

