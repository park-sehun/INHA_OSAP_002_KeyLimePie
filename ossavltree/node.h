#include <iostream>

class Node {

};

class Int_Node : public Node {
public:
    int key_; //key값
    Int_Node():key_(0) {}
    Int_Node(int x):key_(x) {}
};

class Int_AVLtree_Node : public Int_Node{
public:
    Int_AVLtree_Node* left_child; //왼쪽 자식노드
    Int_AVLtree_Node* right_child; //오른쪽 자식노드
    Int_AVLtree_Node* parent_node; //부모 노드
    int left_subtree_size; //왼쪽 서브트리의 사이즈
    int height;
    Int_AVLtree_Node() :Int_Node(0), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0) {}
    Int_AVLtree_Node(int x) :Int_Node(x), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0)  {  } //생성자 함수
};

//팩토리 메서드 적용, 단일 책임원칙을 위해 객체 생성역할 분리, 팩토리 메서드에 위임
class Node_creator {

};

class Int_node_creator : public Node_creator{
public:
    Int_Node* CreateNode(int x) {
        return Get_Node(x);
    }
    virtual Int_Node* Get_Node(int x) = 0;
};

class AVLtree_Int_node_creator:public Int_node_creator {
public:
    Int_AVLtree_Node* Get_Node(int x) {
        return new Int_AVLtree_Node(x);
    }
};