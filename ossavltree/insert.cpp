#include "avltree.h"

int AVLtree::Insert(int x) //key값이 x인 노드를 삽입하는 함수
{
    node* new_node = new node(x);//새로운 노드 생성
    if (node_num == 0) //tree가 비어있을 때
    {
        root = new_node;
        return getDepth(new_node);
    }

    node* current_node = root; //new_node가 삽일될 노드
    node* parent_node = NULL; //부모 노드가 될 노드
    int child_factor = 0; //왼쪽 자식 노드인지 오른쪽 자식 노드인지 결정하는 인자

    while (current_node != NULL)
    {
        parent_node = current_node;
        if (current_node->key_ > x) //current_node key가 x보다 클 때
        {
            current_node = current_node->left_child;
            child_factor = -1;
        }
        else if (current_node->key_ < x) //current_node key가 x보다 작을 때
        {
            current_node = current_node->right_child;
            child_factor = 1;
        }
        else if (current_node->key_ == x) //x를 key값으로 가지는 노드가 이미 존재할 때
        {
            std::cout << "이미 존재하는 값입니다./insert"
                << "\n";
            return 0;
        }
    }

    new_node->parent_node = parent_node;

    if (child_factor == -1) //왼쪽 자식 노드일 경우
    {
        parent_node->left_child = new_node;
    }
    else if (child_factor == 1) //오른쪽 자식 노드일 경우
    {
        parent_node->right_child = new_node;
    }
    else //에러가 일어났을 경우
    {
        std::cout << "잘못된 child_factor 값입니다./insert"
            << "\n";
        return 0;
    }

    UpdateLeftSubtreeSize(new_node);  //rotate 전 left_subtree_size 업데이트
    Balance(new_node);
    return getDepth(new_node);
}