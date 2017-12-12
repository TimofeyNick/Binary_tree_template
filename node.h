#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
public:

    T key_;

    Node();
    ~Node();

    Node *parent_, *left_, *right_;

    void update_key(T data);

    Node operator=(const Node* p);

};

template<typename T>
Node<T>::Node(){
    key_ = -1;
    left_ = nullptr;
    right_ = nullptr;
    parent_ = nullptr;
}

template<typename T>
Node<T>::~Node() {}

template <typename T>
void Node<T>::update_key(T data){
    key_ = data;
}

template<typename T>
Node<T> Node<T>::operator=(const Node *p){
    this->key_ = (*p).key_;
    this->parent_ = (*p).parent_;
    this->right_ = (*p).right_;
    this->left_ = (*p).left_;
    return *this;
}


#endif // NODE_H
