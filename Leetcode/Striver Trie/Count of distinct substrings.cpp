/*You are required to complete this method */
class trieNode {
public:
    trieNode* children[26];
    trieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
int countDistinctSubstring(string s) {
    int n = s.size();
    trieNode* root = new trieNode();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        trieNode* temp = root;
        for (int j = i; j < n; j++) {
            if (temp->children[s[j] - 'a'] == NULL) {
                temp->children[s[j] - 'a'] = new trieNode();
                ans++;
            }
            temp = temp->children[s[j] - 'a'];
        }
    }
    return ans;
}