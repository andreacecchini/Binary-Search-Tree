#include <iostream>
#include "binarysearchtree.h"


BSTNode::BSTNode(BSTKey key){
    this->key = key;
    this->parent = this->right = this->left = nullptr;
}
BSTNode::BSTNode(BSTKey key, BSTNode *parent , BSTNode *left , BSTNode *right){
    this->key = key;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

//Getters
BSTNode *BSTNode::get_parent(){
    return this->parent;
}

BSTNode *BSTNode::get_left(){
    return this->left;
}

BSTNode *BSTNode::get_right(){
    return this->right;
}

//Setters
void BSTNode::set_parent(BSTNode *new_parent){
    this->parent = new_parent;
}
void BSTNode::set_left(BSTNode *new_left){
    this->left = new_left;
}
void BSTNode::set_right(BSTNode *new_right){
    this->right = new_right;
}


void BSTNode::destroy(){
    delete this;
}

/************************************/

BST::BST(){
    this->root = nullptr;
    this->size = 0;
}

static void  bst_clear_rec(BSTNode *n){
    if(n != nullptr){
        bst_clear_rec(n->get_left());
        bst_clear_rec(n->get_right());
        n->destroy();
    }
}

void BST::clear(){
    bst_clear_rec(this->root);
    this->set_root(nullptr);
    this->set_size(0);
}

void BST::destroy(){
    this->clear();
    delete this;
}

//Getters
BSTNode *BST::get_root(){
    return this->root;
}

int BST::get_size(){
    return this->size;
}


//Setters
void BST::set_root(BSTNode *new_root){
    this->root = root;
}

void BST::set_size(int new_size){
    this->size = size;
}

bool BST::is_empty(){
    return !this->get_size();
}


void BST::insert(BSTNode *new_node){
    BSTNode *y = nullptr;
    BSTNode *x = this->get_root();
    while( x != nullptr){
        y = x;
        if(new_node->get_key() < x->get_key()) x = x->get_left();
        else x = x->get_right();
    }
    new_node->set_parent(y);
    if( y == nullptr) this->set_root(new_node);
    else if(new_node->get_key() < y->get_key()) 
        y->set_left(new_node);
    else
        y->set_right(new_node);
}

void BST::insert_rec(BSTNode *starting_point , BSTNode *new_node){
    static BSTNode *y = nullptr;
    //Base step
    if(starting_point == nullptr){
        new_node->set_parent(y);
        if( y == nullptr ) this->set_root(new_node);
        if(new_node->get_key() < y->get_key()) y->set_left(new_node);
        else y->set_right(new_node);
    }
    //Recursive step
    y = starting_point;
    if(new_node->get_key() < starting_point->get_key())
        this->insert_rec(starting_point->get_left(), new_node);
    else
        this->insert_rec(starting_point->get_right() , new_node);
}

BSTNode *BST::search(BSTKey k){
    BSTNode *tmp = this->get_root();
    while(tmp != nullptr || k == tmp->get_key()){
        if(k < tmp->get_key()) tmp = tmp->get_left();
        else tmp = tmp->get_right();
    }
    return tmp;
}


BSTNode *BST::search_rec(BSTNode *start ,BSTKey k){
    if(start == nullptr || k == start->get_key()) return start;
    if(k < start->get_key()) return this->search_rec(start->get_left(), k);
    else return this->search_rec(start->get_right(), k);
}