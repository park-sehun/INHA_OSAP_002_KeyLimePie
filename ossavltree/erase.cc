#include "set.h"

void Int_AVLtree::Erase(int x) { //key값이 x인 노드를 삭제하는 함수 
    Int_AVLtree_Node* delete_node = search(root, x);

    if (delete_node == NULL) {
        std::cout << 0 << "\n";
        return;
    }

    int depth = getDepth(delete_node);

    Int_AVLtree_Node* parent_node_of_del = delete_node->parent_node;
    Int_AVLtree_Node* child_node;

    if (delete_node->left_child == NULL && delete_node->right_child == NULL) { //del_node의 자식 노드가 존재하지 않음
        child_node = NULL;
    }
    else if (delete_node->left_child == NULL && delete_node->right_child != NULL) { //del_node가 오른쪽 자식 노드만 가짐
        child_node = delete_node->right_child;
    }
    else if (delete_node->left_child != NULL && delete_node->right_child == NULL) { //delete_node가 왼쪽 자식 노드만 가짐
        child_node = delete_node->left_child;
    }
    else { //delete_node가 자식 노드 두 개를 모두 가짐   
        child_node = delete_node->right_child;

        while (child_node->left_child != NULL) {
            child_node = child_node->left_child;
        }

        delete_node->key_ = child_node->key_;
        delete_node = child_node;
        parent_node_of_del = delete_node->parent_node;
        child_node = delete_node->right_child;
    }

    UpdateLeftSubtreeSize(delete_node, -1);

    if (parent_node_of_del == NULL) { //root를 삭제
        root = child_node;
        if (child_node != NULL) {
            root->parent_node = NULL;
        }
    }
    else if (delete_node == parent_node_of_del->left_child) { //삭제할 노드가 부모의 왼쪽 자식
        parent_node_of_del->left_child = child_node;
        if (child_node != NULL) {
            child_node->parent_node = parent_node_of_del;
        }
    }
    else { //삭제할 노드가 부모의 오른쪽 자식
        parent_node_of_del->right_child = child_node;
        if (child_node != NULL) {
            child_node->parent_node = parent_node_of_del;
        }
    }
    Int_AVLtree_Node* tmp_parent = delete_node->parent_node;
    setHeight(tmp_parent);
    delete delete_node;
    node_num--;
    balance(tmp_parent,false);

    std::cout<< depth<<"\n"; //depth를 출력해야 함
}