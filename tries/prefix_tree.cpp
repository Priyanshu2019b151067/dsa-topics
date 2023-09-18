// if we want to search a particular pattern in a string we need to use tries
class Node{
    public:
    Node * arr[26];
    bool terminate = false;
};
class Trie {
public: 
    Node * head;
    Trie() {
        head= new Node();
    }
    
    void insert(string word) {
        auto first = head;
        for(int i = 0;i < word.size();i++){
            if(first->arr[word[i]-'a'] == NULL){
                first->arr[word[i]-'a'] = new Node();
            }
            first = first->arr[word[i]-'a'];
        }
        first->terminate = true;
    }
    
    bool search(string word) {
        auto first = head;
        for(int i = 0;i < word.size();i++){
            
            if(first->arr[word[i]-'a']==NULL){
                return false;
            }
            first = first->arr[word[i]-'a'];
        }
        return first->terminate;
        
    }
    
    bool startsWith(string prefix) {
         auto first = head;
        for(int i = 0;i < prefix.size();i++){
            
            if(first->arr[prefix[i]-'a']==NULL){
                return false;
            }
           
            first = first->arr[prefix[i]-'a'];
        }
        return true;
        
    }
};

