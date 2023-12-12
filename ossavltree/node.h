#include <iostream>

struct node
{
    int key_; //key값
    node* left_child; //왼쪽 자식노드
    node* right_child; //오른쪽 자식노드
    node* parent_node; //부모 노드
    int left_subtree_size; //왼쪽 서브트리의 사이즈
    int height;  //노드 높이
    node(int key):key_(key), parent_node(NULL), left_child(NULL), right_child(NULL),left_subtree_size(0) { } //생성자 함수
};