class Node {
public:
    int val;
    int key;
    Node* left;
    Node* right;
    Node(){
        val =0;
        key=-1;
        left = NULL;
        right = NULL;
    }
    Node(int x){
        val =x;
        left = NULL;
        right = NULL;
    }
    void display(Node* node1){
        if(0){
    cout<<endl;
    if(node1==NULL)
        cout<<"nothing";
    while(node1!=NULL){
        cout<<node1->key<<" ";
        node1=node1->right;
    }
    cout<<endl;
        }
    return;
}
};
class LRUCache {
public:
    unordered_map<int,Node *>mp;
    int capacity1 ;
    int present;
    Node* lru_node = NULL;
    Node* mru_node = NULL;
    LRUCache(int capacity) {
        this->capacity1 = capacity;
        this->lru_node = NULL;
        this->mru_node = NULL;
        this->present = 0;
    }
    
    int get(int key) {
        //cout<<"get "<<key<<endl;
        if(lru_node!=NULL)
        lru_node->display(lru_node);
        if(this->mp.count(key)!=0){
            //if(this->mp[key]->val==14)
                //cout<<"hi"<<endl;
            if(this->mp[key]!=this->mru_node){
                mp[key]->right->left=mp[key]->left;
                if(this->lru_node!=this->mp[key])
                    this->mp[key]->left->right = this->mp[key]->right;
                else{
                    this->lru_node = this->mp[key]->right;
                    lru_node->left = NULL;
                }
                this->mp[key]->right = NULL;
                this->mp[key]->left = this->mru_node;
                this->mru_node->right = this->mp[key];
                this->mru_node = this->mp[key];
                
                }
                lru_node->display(lru_node);
            return(this->mp[key]->val);
        }
        else{
        if(lru_node!=NULL)
        lru_node->display(lru_node);
        
            return(-1);
        }
        
    }
    
    void put(int key, int value) {
        //cout<<key<<" put  "<<value<<endl;
        if(lru_node!=NULL)
        lru_node->display(lru_node);
        if(this->mp.count(key)!=0 ){
            this->mp[key]->val = value;
            
            if(this->mp[key]!=this->mru_node){
                mp[key]->right->left=mp[key]->left;
                if(this->lru_node!=this->mp[key]){
                    
                    //cout<<this->mp[key]->left->key<<endl;
                    this->mp[key]->left->right = this->mp[key]->right;
                }
                else{
                lru_node = this->mp[key]->right;
                lru_node->left = NULL;
            }
                
                this->mp[key]->right = NULL;
                this->mp[key]->left = this->mru_node;
                this->mru_node->right = this->mp[key];
                this->mru_node = this->mp[key];
            }
            //return(this->mp[key]->val);
        }
        else{
            Node* new_node = new Node();
            new_node->val = value;
            new_node->key = key;
            this->mp[key] = new_node;
            this->present+=1;
            if(present==1){
                this->mru_node = new_node;
                this->lru_node = new_node;
            }
            else{
            this->mru_node->right = this->mp[key];
            this->mp[key]->left = this->mru_node;
            this->mru_node = this->mp[key];
            if(this->present>this->capacity1){
                //cout<<lru_node->key<<endl;
                //cout<<"hi"<<endl;
                this->mp.erase(lru_node->key);
                this->lru_node = this->lru_node->right;

                //cout<<lru_node->key<<endl;
                this->lru_node->left = NULL;
                present-=1;
                
            }
            }
        }
        
        
        if(0)
        lru_node->display(lru_node);
    }
};
