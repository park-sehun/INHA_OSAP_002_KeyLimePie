#include "set.h"

void Int_AVLtree::Erase(int x)
{ // key값이 x인 노드를 삭제하는 함수
    Int_AVLtree_Node *delete_node = search(getRoot(), x);

    if (delete_node == NULL)
    {
        std::cout << 0 << "\n";
        return;
    }

    int depth = getDepth(delete_node);

    Int_AVLtree_Node *parent_node_of_del = delete_node->getParent_node();
    Int_AVLtree_Node *child_node;

    if (delete_node->getLeft_child() == NULL && delete_node->getRight_child() == NULL)
    { // del_node의 자식 노드가 존재하지 않음
        child_node = NULL;
    }
    else if (delete_node->getLeft_child() == NULL && delete_node->getRight_child() != NULL)
    { // del_node가 오른쪽 자식 노드만 가짐
        child_node = delete_node->getRight_child();
    }
    else if (delete_node->getLeft_child() != NULL && delete_node->getRight_child() == NULL)
    { // delete_node가 왼쪽 자식 노드만 가짐
        child_node = delete_node->getLeft_child();
    }
    else
    { // delete_node가 자식 노드 두 개를 모두 가짐
        child_node = delete_node->getRight_child();

        while (child_node->getLeft_child() != NULL)
        {
            child_node = child_node->getLeft_child();
        }

        delete_node->setKey_(child_node->getKey_());
        delete_node = child_node;
        parent_node_of_del = delete_node->getParent_node();
        child_node = delete_node->getRight_child();
    }

    UpdateLeftSubtreeSize(delete_node, -1);

    if (parent_node_of_del == NULL)
    { // root를 삭제
        setRoot(child_node);
        if (child_node != NULL)
        {
            getRoot()->setParent_node(NULL);
        }
    }
    else if (delete_node == parent_node_of_del->getLeft_child())
    { // 삭제할 노드가 부모의 왼쪽 자식
        parent_node_of_del->setLeft_child(child_node);
        if (child_node != NULL)
        {
            child_node->setParent_node(parent_node_of_del);
        }
    }
    else
    { // 삭제할 노드가 부모의 오른쪽 자식
        parent_node_of_del->setRight_child(child_node);
        if (child_node != NULL)
        {
            child_node->setParent_node(parent_node_of_del);
        }
    }
    Int_AVLtree_Node *tmp_parent = delete_node->getParent_node();
    setHeight(tmp_parent);
    delete delete_node;
    setNode_num(getNode_num() - 1);
    balance(tmp_parent, false);

    std::cout << depth << "\n"; // depth를 출력해야 함
}