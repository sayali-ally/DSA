https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node{
    Node* links[26];
    bool endWord = false;
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(char ch: word){
            int j = ch-'a';
            if(temp->links[j]==NULL){
                temp->links[j]=new Node();
            }
            temp=temp->links[j];
        }
        temp->endWord=true;
    }
    
    bool search(string word) {
        Node* temp =root;
        for(char ch: word){
            int j=ch-'a';
            if(temp->links[j]==NULL){
                return false;
            }
            temp=temp->links[j];
        }
        return temp->endWord;   
    }
    
    bool startsWith(string word) {
        Node* temp=root;
        for(char ch: word){
            int j=ch-'a';
            if(temp->links[j]==NULL){
                return false;
            }
            temp=temp->links[j];
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
