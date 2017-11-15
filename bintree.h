#ifndef BINTREE
#define BINTREE

#include <algorithm>

struct BinTree{
    BinTree* left=nullptr;
    BinTree* right=nullptr;
    int weight;
    char symbol;
    BinTree(int val){
        this->weight=val;
        this->symbol='a'+val;
    }

    static BinTree* insert(BinTree* root, int val){
        if(root==nullptr)return new BinTree(val);
        if(root->weight==val)return root;
        if(root->weight>val)root->left=insert(root->left,val);
        else root->right=insert(root->right,val);
        return root;
    };
};

#endif // BINTREE

