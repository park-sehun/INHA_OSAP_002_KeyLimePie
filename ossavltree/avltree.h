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
    int getRank(node* current_node, int x); //key값이 x보다 작은 노드의 개수를 재귀적으로 구하는 함수
    void UpdateLeftSubtreeSize(node* current_node);  //insert 직후 left_subtree_size를 업데이트 하는 함수
    node* Search(node* current_node, int x); //root가 currnt_node인 서브트리에서 key값이 x인 노드를 찾는 함수
    void Balance(node* current_node); //root가 currnt_node인 서브트리에서 균형을 맞추는 함수
    void RightRotate(node* node_z); //rightRotate를 실행하는 함수
    void LeftRotate(node* node_z); //leftRotate를 실행하는 함수
    void Minimum(int x); //key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    void Maximum(int x); //key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    void Empty(); //tree가 비어있는지를 출력하는 함수
    void Size(); //tree의 크기를 출력하는 함수
    void Find(int x); //key 값이 x인 노드의 depth를 출력하는 함수
    int Insert(int x); //key값이 x인 노드를 삽입하는 함수
    void Rank(int x); //key값이 x인 노드의 depth와 rank를 출력하는 함수
    void Erase(int x); //key값이 x인 노드를 삭제하는 함수 

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

int AVLtree::getRank(node* current_node, int x) {  //key값이 x보다 작은 노드의 개수를 재귀적으로 구하는 함수
    if (x == current_node->key_)  //현재 노드의 key가 x일 경우 해당 노드의 left_subtree_size값 리턴
    {
        return current_node->left_subtree_size;
    }
    else if (x < current_node->key_)  //x값이 현재 노드의 key값보다 작을 경우
    {
        if (current_node->left_child == NULL) //왼쪽 자식이 존재하지 않을 경우 해당 노드가 없다는 뜻이므로 탐색 실패
        {
            return -1;
        }
        else  //왼쪽 자식이 존재 할 경우 그곳으로 이동
            return getRank(current_node->left_child, x);
    }
    else //x값이 현재 노드의 key값보다 클 경우
    {
        if (current_node->right_child == NULL)  //오른쪽 자식이 존재하지 않을 경우 해당 노드가 없다는 뜻이므로 탐색 실패
        {
            return -1;
        }
        else //오른쪽 자식이 존재하는 경우
        {
            int right_subtree_size = getRank(current_node->right_child, x);  //right_size를 재귀적으로 구해옴.
            if (right_subtree_size == -1)   //x값을 가진 노드 탐색 실패 할 경우
                return -1;
            else  //
                return current_node->left_subtree_size + 1 + right_subtree_size;  //현재노드의 key값이 x보다 작으므로 현재노드의 왼쪽 서브트리 사이즈 + 1 + right size 리턴

        }
    }
}

void AVLtree::UpdateLeftSubtreeSize(node* current_node){  //insert 직후, rotation전에 left_subtree_size를 업데이트 하는 함수
    if(current_node==root)  //루트 도달 시 종료 
    {
        return;
    }
    else
    {
        if(current_node==current_node->parent_node->left_child)  //current_node가 부모의 왼쪽 자식일 경우 부모의 left_subtree_size 1 증가
        {
            current_node->parent_node->left_subtree_size++;
        }
        return UpdateLeftSubtreeSize(current_node->parent_node);  //재귀적으로 루트까지 업데이트
    }

}

node* AVLtree::Search(node* current_node, int x) //root가 current_node인 서브트리에서 key값이 x인 노드를 찾는 함수
{
    while (current_node != NULL) {  
        if (x==current_node->key_) { return current_node; }  //key값이 x인 노드 발견 성공시 해당 노드 포인터 리턴
        else if (x < current_node->key_) {  //x값이 현재 노드의 key값보다 작을 경우 현재노드의 left_child로 이동
            current_node = current_node->left_child;
        }
        else {  //x값이 현재 노드의 key값보다 클 경우 현재 노드의 right_child로 이동
            current_node = current_node->right_child;
        }
    }
    return NULL;  //key가 x인 노드를 찾지 못하고 leaf 노드에 도달 한 경우 x값을 가진 노드가 없다는 뜻이므로 NULL리턴
}

void AVLtree::Balance(node* current_node) //root가 currnt_node인 서브트리에서 균형을 맞추는 함수
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
            RightRotate(current_node);
        }
        if (getBalanceFactor(current_node->left_child) < -1) // LR 변환
        {
            LeftRotate(current_node->left_child);
            RightRotate(current_node);
        }
    }
    else if (current_node_balance_factor < -1) //오른쪽 자식 노드의 높이가 2이상으로 더 높은 경우
    {
        if (getBalanceFactor(current_node->right_child) > 1) // RL 변환
        {
            RightRotate(current_node->right_child);
            LeftRotate(current_node);
        }
        if (getBalanceFactor(current_node->right_child) < -1) // RR 변환
        {
            LeftRotate(current_node);
        }
    }
}

void AVLtree::RightRotate(node* node_z) //rightRotate를 실행하는 함수
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

void AVLtree::LeftRotate(node* node_z) //leftRotate를 실행하는 함수
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

void AVLtree::Minimum(int x) //key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    node* minimum_node = Search(root, x); //x를 key값으로 가지는 노드
    while (minimum_node->left_child != NULL) //노드가 존재할때 까지 실행
    {
        minimum_node = minimum_node->left_child; //minimum_node를 minimum_node의 왼쪽 자식 노드로 바꿈
    }
    int minimum_node_depth = getDepth(minimum_node); //minimum_node의 depth를 구함
    std::cout << minimum_node_depth << "\n";
}

void AVLtree::Maximum(int x) //key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    node* root_subtree = Search(root, x); //x를 key값으로 가지는 노드
    node* maximum_node = root_subtree;
    while (maximum_node->right_child != NULL) //노드가 존재할때 까지 실행
    {
        maximum_node = maximum_node->right_child; //maximum_node를 minimum_node의 오른쪽 자식 노드로 바꿈
    }
    int maximum_node_depth = getDepth(maximum_node); ////maximum_node의 depth를 구함
    std::cout << maximum_node_depth << "\n";
}

void AVLtree::Empty() //tree가 비어있는지를 출력하는 함수
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

void AVLtree::Size() //tree의 크기를 출력하는 함수
{
    std::cout << node_num << "\n";
    return;
}

void AVLtree::Find(int x) //key 값이 x인 노드의 depth를 출력하는 함수
{
    node* result = Search(root, x); //key 값이 x인 노드 search
    int depth = getDepth(result); // Get the depth of the found node
    std::cout << depth << "\n";
}

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

    UpdateLeftSubtreeSize(new_node);  //rotate 전 left_subtree_size 업데이트
    Balance(new_node);
    return getDepth(new_node);
}

void AVLtree::Rank(int x) { //key값이 x인 노드의 depth와 rank를 출력하는 함수
    int rank_of_x = getRank(root, x) + 1; //rank값 : key값이 x보다 작은 노드의 개수 +1 
    std::cout << rank_of_x << "\n";
}

void AVLtree::Erase(int x) { //key값이 x인 노드를 삭제하는 함수 

}

#endif
