// Лабораторная работа №5
// codetree.h
// Тимофеев Дмитрий, группа 6383
// 12.11.17
//
// Бинарные деревья и алгоритмы сжатия

#ifndef CODETREE
#define CODETREE

#include<iostream>

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

    class DemoTree{
    public:
        DemoTree();
        ~DemoTree();
        Node* updateTree(unsigned char symbol);

    private:
        Node* symbols[256]={nullptr};
        Node* esc;
        Node* root=nullptr;
    };

    void encode(std::istream &in, std::ostream &code);
    void decode(std::istream &in, std::ostream &code);
}

#endif // CODETREE

