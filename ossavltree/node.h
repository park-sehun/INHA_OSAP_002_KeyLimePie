#include <iostream>

class Node
{
};

class Int_Node : public Node
{
public:
    Int_Node() : key_(0) {}
    Int_Node(int x) : key_(x) {}
    void setKey_(int x) { key_ = x; }
    int getKey_() { return key_; }

private:
    int key_; // key값
};

class Int_AVLtree_Node : public Int_Node
{
public:
    Int_AVLtree_Node() : Int_Node(0), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0) {}
    Int_AVLtree_Node(int x) : Int_Node(x), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0) {} // 생성자 함수
    void setLeft_child(Int_AVLtree_Node *n) { left_child = n; }
    Int_AVLtree_Node *getLeft_child() { return left_child; }
    void setRight_child(Int_AVLtree_Node *n) { right_child = n; }
    Int_AVLtree_Node *getRight_child() { return right_child; }
    void setParent_node(Int_AVLtree_Node *n) { parent_node = n; }
    Int_AVLtree_Node *getParent_node() { return parent_node; }
    void setLeft_subtree_size(int x) { left_subtree_size = x; }
    int getLeft_subtree_size() { return left_subtree_size; }
    void setHeight(int x) { height = x; }
    int getHeight() { return height; }

private:
    Int_AVLtree_Node *left_child;  // 왼쪽 자식노드
    Int_AVLtree_Node *right_child; // 오른쪽 자식노드
    Int_AVLtree_Node *parent_node; // 부모 노드
    int left_subtree_size;         // 왼쪽 서브트리의 사이즈
    int height;                    // 높이
};

// 팩토리 메서드 적용, 단일 책임원칙을 위해 객체 생성역할 분리, 팩토리 메서드에 위임
class Node_creator
{
};

class Int_node_creator : public Node_creator
{
public:
    Int_Node *CreateNode(int x)
    {
        return Get_Node(x);
    }
    virtual Int_Node *Get_Node(int x) = 0;
};

class AVLtree_Int_node_creator : public Int_node_creator
{
public:
    Int_AVLtree_Node *Get_Node(int x)
    {
        return new Int_AVLtree_Node(x);
    }
};