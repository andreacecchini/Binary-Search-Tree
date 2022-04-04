

typedef int BSTKey;

class BSTNode{
    BSTKey key;
    BSTNode *parent, *left, *right; 
    public:
        BSTNode(BSTKey key);
        BSTNode(BSTKey key , BSTNode *parent , BSTNode *left , BSTNode *right);
        //Getters
        BSTNode *get_parent();
        BSTNode *get_left();
        BSTNode *get_right();
        BSTKey get_key();
        //Setters
        void set_parent(BSTNode *new_parent);
        void set_left(BSTNode *new_left);
        void set_right(BSTNode *new_right);
        void set_key(BSTKey new_key);
        //Destroy node
        void destroy();

};


class BST{
    BSTNode *root;
    int size;
    public:
        BST();

        //Getters
        BSTNode *get_root();
        int get_size();
        int get_height();
        //Setters
        void set_root(BSTNode *new_root);
        void set_size(int new_size);
        void clear();
        void destroy();
        //Insert a node in the tree
        void insert(BSTNode *new_node);
        void insert_rec(BSTNode *starting_point , BSTNode *new_node);
        //Search a node of the tree
        BSTNode *search(BSTKey k);
        BSTNode *search_rec(BSTNode *start,BSTKey k);
        //Delete a node of the tree
        void delete_node(BSTNode *n);
        //Checks
        bool is_empty();
        //Print key
        void print();
        void pretty_print();

};
