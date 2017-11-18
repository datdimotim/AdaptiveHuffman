// Лабораторная работа №5
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#ifndef CODETREE
#define CODETREE

#include<iostream>
#include<string.h>
#include<vector>

namespace code_tree {
    struct Node{
        char symbol;
        long weight;
        Node* parent;
        Node* left;
        Node* right;
        Node* next=nullptr;
        Node* back=nullptr;
        Node(char symbol, long weight, Node* parent, Node* left, Node* right){
            this->symbol=symbol;
            this->weight=weight;
            this->parent=parent;
            this->left=left;
            this->right=right;
        }
    };

    void encode(std::istream &in, std::ostream &code);
    void decode(std::istream &in, std::ostream &code);
}

namespace demo_haffman{
    struct BT{
        char symbol;
        long weight;
        BT* left=nullptr;
        BT* right=nullptr;
        ~BT(){
            if(left!=nullptr)delete left;
            if(right!=nullptr)delete right;
        }
        BT(char symbol, long weight, BT* left,BT* right){
            this->symbol=symbol;
            this->weight=weight;
            this->left=left;
            this->right=right;
        }
    };

    struct State{
        int currentSymbol;
        char* msg=nullptr;
        BT* root=nullptr;

        State(int currentSymbol,const char* msg, code_tree::Node* root){
            this->currentSymbol=currentSymbol;
            this->msg=new char[strlen(msg)+1];
            (*(this->msg))='\0';
            stpcpy(this->msg,msg);
            this->root=captureTree(root);
        }

        ~State(){
            if(root!=nullptr)delete root;
            if(msg!=nullptr)delete[] msg;
        }
        static BT* captureTree(code_tree::Node* root){
            if(root==nullptr)return nullptr;
            return new BT(root->symbol,
                          root->weight,
                          captureTree(root->left),
                          captureTree(root->right));
        }
    };


    void demoEncode(std::vector<State*> &states, char* msg);
}
#endif // CODETREE

