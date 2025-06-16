class Trie {
public:
    struct trieNode {
        bool endOfWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* root = new trieNode();
        root->endOfWord = false;
        for (int i = 0; i < 26; i++) {
            root->children[i] = NULL;
        }
        return root;
    }

    trieNode* root;
    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* temp = root;
        for (auto &x : word) {
            if (temp->children[x - 'a'] == NULL) {
                temp->children[x - 'a'] = getNode();
            }
            temp = temp->children[x - 'a'];
        }
        temp->endOfWord = true;
    }

    bool search(string word) {
        trieNode* temp = root;
        for (auto &x : word) {
            if (temp->children[x - 'a'] == NULL) {
                return false;
            } else temp = temp->children[x - 'a'];
        }
        return temp->endOfWord;
    }

    bool startsWith(string prefix) {
        trieNode* temp = root;
        for (auto &x : prefix) {
            if (temp->children[x - 'a'] == NULL) {
                return false;
            } else temp = temp->children[x - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */