#ifndef TREE_H
#define TREE_H

#include "node.h"

template<typename T>
class Tree: public Node<T>{
private:
    Node<T> find_node(T data); // возвращает именно Node,а не Node*

public:

    Node<T> root_;

    Tree();
    ~Tree();

    void print_tree(Node<T> *node);

    void insert(T data);

};

template<typename T>
Tree<T>::Tree(){}

template<typename T>
Tree<T>::~Tree(){}

// возвращает именно Node,а не Node*
template<typename T>
Node<T> Tree<T>::find_node(T data){
    Node<T>* p = &root_;
    Node<T> l;
    while(p -> key_ != -1 && p -> key_ != data){
            if(data > p->key_){
                if (p->right_ == nullptr){
                    return l;
                }
                else{
                    p = p->right_;
                }
            }
            else{
                if (p->left_ == nullptr){
                    return l;
                }
                else{
                    p = p->left_;
                }
            }
    }
    return *p;
}

template<typename T>
void Tree<T>::print_tree(Node<T> *node){
    if (node -> key_ == -1){return;}
    if (node->left_ != nullptr){
        print_tree(node->left_);
    }
    std::cout << node -> key_ << "  ";
    if (node->right_ != nullptr){
        print_tree(node->right_);
    }
}

template<typename T>
void Tree<T>::insert(T data){
    Node<T> p = find_node(data);
    if (p.key_ != -1){return;}

    // node - вершина которую хотим добавить в дерево
    Node<T>* node = new Node<T>;
    node->update_key(data);

    if (root_.key_ == -1){
        root_ = *node;
        return;
    }

    Node<T>* f = &root_;

    while(1 == 1){
        if(data < (f -> key_)){
            if (f -> left_ == nullptr){
                f -> left_ = node;
                node->parent_ = f;
                return;
            }
            else if(f -> left_ -> key_ == -1){
                f -> left_ = node;
                node->parent_ = f;
                return;
            }
            else{
                f = f -> left_;
            }
        }
        else{
            if (f -> right_ == nullptr){
                f -> right_ = node;
                node->parent_ = f;
                return;
            }
            else if(f -> right_ -> key_ == -1){
                f -> right_ = node;
                node->parent_ = f;
                return;
            }
            else{
                f = f -> right_;
            }
        }
    }
}


#endif // TREE_H
