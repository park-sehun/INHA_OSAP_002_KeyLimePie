#include "avltree.h"

int AVLtree::Erase(int x) { //key값이 x인 노드를 삭제하는 함수 
    node* delete_node = Search(root, x);

    if (delete_node == NULL) {
        return 0;
    }

    int depth = getDepth(delete_node);

    node* parent_node_of_del = delete_node->parent_node;
    node* child_node;

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

    UpdateLeftSubtreeSize(delete_node, -1);  //root 삭제시 아래 if문 수행후 UpdateLeftSubtreeSize를 호출 할 경우 root가 바뀐 상태라 탈출하지 못하고 NULL 포인터를 참조하는 문제가 있으므로 미리 수행.

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
    node* tmp_parent = delete_node->parent_node;  //노드 삭제후 height와 balance를 수행 할 부모노드 포인터 잠시 저장
    delete delete_node;
    setHeight(tmp_parent);
    node_num--;
    Balance(tmp_parent, false);

    return depth; //depth를 출력해야 함
}