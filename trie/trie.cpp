struct Node {
    Node* links[10];
};
class trie{
    Node* root;
public:
    trie(){
        root=new Node();
    }
    void insert(string word){
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            int j=word[i]-'0';
            if(temp->links[j]==NULL)
            {
                temp->links[j]=new Node();
            }
            temp=temp->links[j];
        }
    }
    int maxL(string word){
        int count =0;
        Node* temp=root;
        for(int i=0;i<word.size();i++){
            int j=word[i]-'0';
            if(temp->links[j]==NULL){
                return count;
            }
            count++;
            temp=temp->links[j];
        }
        return count;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trie mytrie;
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            mytrie.insert(to_string(arr1[i]));
        }
        for(int i=0;i<arr2.size();i++){
            ans=max(ans,mytrie.maxL(to_string(arr2[i])));
        }
        return ans;
    }
};
