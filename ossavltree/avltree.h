#ifndef OSSAVLTREE_OSSAVLTREE_AVLTREE_H_
#define OSSAVLTREE_OSSAVLTREE_AVLTREE_H_
#include <iostream>

struct node
{
    int key_; //key값
    node* left_child; //왼쪽 자식노드
    node* right_child; //오른쪽 자식노드
    node* parent_node; //부모 노드
    int left_subtree_size; //왼쪽 서브트리의 사이즈
    node(int key):key_(key), parent_node(NULL), left_child(NULL), right_child(NULL),left_subtree_size(0) { } //생성자 함수
};

class AVLtree
{
public:
    AVLtree(); //생성자 함수
    int getHeight(node* current_node); //height를 구하는 함수 
    int getBalanceFactor(node* current_node); //balanceFactor를 구하는 함수
    int getDepth(node* current_node); //depth를 구하는 함수
    node* search(node* current_node, int x); //root가 currnt_node인 서브트리에서 key값이 x인 노드를 찾는 함수
    void balance(node* current_node); //root가 currnt_node인 서브트리에서 균형을 맞추는 함수
    void rightRotate(node* node_z); //rightRotate를 실행하는 함수
    void leftRotate(node* node_z); //leftRotate를 실행하는 함수
    void minimum(int x); //key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    void maximum(int x); //key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    void empty(); //tree가 비어있는지를 출력하는 함수
    void size(); //tree의 크기를 출력하는 함수
    void find(int x); //key 값이 x인 노드의 depth를 출력하는 함수
    int insert(int x); //key값이 x인 노드를 삽입하는 함수
    void rank(int x); //key값이 x인 노드의 depth와 rank를 출력하는 함수
    void erase(int x); //key값이 x인 노드를 삭제하는 함수 

private:
    int node_num; //tree의 저장된 노드의 숫자
    node* root; //tree의 루트 노드
};

AVLtree::AVLtree(): root(NULL), node_num(0) { }//생성자 함수

int AVLtree::getHeight(node* current_node) //height를 구하는 함수 
{
    if (current_node == NULL) //입력된 노드가 존재하지 않을 경우
    {
        return 0;
    }
    else
    {
        int left_child_height = getHeight(current_node->left_child);
        int right_child_height = getHeight(current_node->right_child);
        int max_height = std::max(left_child_height, right_child_height);
        return max_height + 1;
    }
}

int AVLtree::getBalanceFactor(node* current_node) //balanceFactor를 구하는 함수
{
    if (current_node == NULL) //입력된 노드가 존재하지 않을 경우
    {
        return 0;
    }
    int balance_factor = getHeight(current_node->left_child) - getHeight(current_node->right_child);
    return balance_factor;
}

int AVLtree::getDepth(node* current_node) //depth를 구하는 함수
{
    if (current_node == NULL)
    {
        return 0;
    }

    int depth = 0;
    while (current_node != root) // current_node가 root 노드면 탈출
    {
        current_node = current_node->parent_node;
        depth++;
    }

    return depth;
}

node* AVLtree::search(node* current_node, int x) //root가 currnt_node인 서브트리에서 key값이 x인 노드를 찾는 함수
{
    return 0;
}

void AVLtree::balance(node* current_node) //root가 currnt_node인 서브트리에서 균형을 맞추는 함수
{
    if (current_node == NULL) //currenr_node가 없는 경우
    {
        std::cout << "잘못된 입력입니다./balance"
            << "\n";
        return;
    }
    int current_node_balance_factor = getBalanceFactor(current_node); //currnet_node의 balance factor

    if (current_node_balance_factor <= 1 && current_node_balance_factor >= -1) //높이차가 1이하인 경우(balancefactor가 -1에서 1사이인 경우)
    {
        return;
    }
    else if (current_node_balance_factor > 1) //왼쪽 자식 노드의 높이가 2이상으로 더 높은 경우
    {
        if (getBalanceFactor(current_node->left_child) > 1) // LL 변환
        {
            rightRotate(current_node);
        }
        if (getBalanceFactor(current_node->left_child) < -1) // LR 변환
        {
            leftRotate(current_node->left_child);
            rightRotate(current_node);
        }
    }
    else if (current_node_balance_factor < -1) //오른쪽 자식 노드의 높이가 2이상으로 더 높은 경우
    {
        if (getBalanceFactor(current_node->right_child) > 1) // RL 변환
        {
            rightRotate(current_node->right_child);
            leftRotate(current_node);
        }
        if (getBalanceFactor(current_node->right_child) < -1) // RR 변환
        {
            leftRotate(current_node);
        }
    }
}

void AVLtree::rightRotate(node* node_z) //rightRotate를 실행하는 함수
{
    node* node_y = node_z->left_child;
    node* T2_root = node_y->right_child;

    node_y->right_child = node_z;
    node_z->left_child = T2_root;

    if (node_z->parent_node == NULL) // node_z가 루트노드였을 경우
    {
        root = node_y; //node_y를 루트노트로 설정
        node_y->parent_node = NULL;
    }
    else if (node_z->parent_node->left_child == node_z) //node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->parent_node->left_child = node_y;
    }
    else //node_z가 부모노드의 오른쪽 자식 노드였을 경우
    {
        node_z->parent_node->right_child = node_y;
    }
    node_y->parent_node = node_z->parent_node;
    node_z->parent_node = node_y;
    T2_root->parent_node = node_z;

    node_z->left_subtree_size = node_z->left_subtree_size - (node_y->left_subtree_size + 1); // node_z의 왼쪽 서브트리의 사이즈 변화
    return;
}

void AVLtree::leftRotate(node* node_z) //leftRotate를 실행하는 함수
{
    node* node_y = node_z->right_child;
    node* T2_root = node_y->left_child;

    node_y->left_child = node_z;
    node_z->right_child = T2_root;

    if (node_z->parent_node == NULL) // node_z가 루트노드였을 경우
    {
        root = node_y; //node_y를 루트노트로 설정
        node_y->parent_node = NULL;
    }
    else if (node_z->parent_node->left_child == node_z) //node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->parent_node->left_child = node_y;
    }
    else //node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->parent_node->right_child = node_y;
    }
    node_y->parent_node = node_z->parent_node;
    node_z->parent_node = node_y;
    T2_root->parent_node = node_z;

    node_y->left_subtree_size = node_y->left_subtree_size + node_z->left_subtree_size + 1; // node_y의 왼쪽 서브트리의 사이즈 변화
    return;
}

void AVLtree::minimum(int x) //key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    node* minimum_node = search(root, x); //x를 key값으로 가지는 노드
    while (minimum_node->left_child != NULL) //노드가 존재할때 까지 실행
    {
        minimum_node = minimum_node->left_child; //minimum_node를 minimum_node의 왼쪽 자식 노드로 바꿈
    }
    int minimum_node_depth = getDepth(minimum_node); //minimum_node의 depth를 구함
    std::cout << minmum_node_depth << "\n";
}

void AVLtree::maximum(int x) //key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    node* root_subtree = search(root, x); //x를 key값으로 가지는 노드
    node* maximum_node = root_subtree;
    while (maximum_node->right_child != NULL) //노드가 존재할때 까지 실행
    {
        maximum_node = maximum_node->right_child; //maximum_node를 minimum_node의 오른쪽 자식 노드로 바꿈
    }
    int maximum_node_depth = getDepth(maximum_node); ////maximum_node의 depth를 구함
    std::cout << maxmum_node_depth << "\n";
}

void AVLtree::empty() //tree가 비어있는지를 출력하는 함수
{
    if (node_num == 0) //tree가 비었을때
    {
        std::cout << 1 << "\n";
        return;
    }
    else //tree가 비어있지 않을 때
    {
        std::cout << 0 << "\n";
        return;
    }
}

void AVLtree::size() //tree의 크기를 출력하는 함수
{
    std::cout << node_num << "\n";
    return;
}

void AVLtree::find(int x) //key 값이 x인 노드의 depth를 출력하는 함수
{
    node* result = search(root, x); //key 값이 x인 노드 search
    int depth = getDepth(result); // Get the depth of the found node
    cout << depth << "\n";
}

int AVLtree::insert(int x) //key값이 x인 노드를 삽입하는 함수
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
            return;
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
        return;
    }
    return getDepth(new_node);
}

void AVLtree::rank(int x) { //key값이 x인 노드의 depth와 rank를 출력하는 함수

}

void AVLtree::erase(int x) { //key값이 x인 노드를 삭제하는 함수 

}

#endif
