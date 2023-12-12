/*
BSD-3-Clause
Copyright (c) 2023, KeyLimePie team
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL KeyLimePie team BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

작성자 : KeyLimePie team
작성일 : 2023년 12월 13일
*/
#include <node.h>

class Ds
{
public:
};

class Int_ds : public Ds
{
public:
    virtual void Minimum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    virtual void Maximum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    virtual void Find(int x) = 0;    // key 값이 x인 노드의 depth를 출력하는 함수
    virtual void Insert(int x) = 0;  // key값이 x인 노드를 삽입하는 함수
    virtual void Rank(int x) = 0;    // key값이 x인 노드의 depth와 rank를 출력하는 함수
    virtual void Erase(int x) = 0;   // key값이 x인 노드를 삭제하는 함수
    virtual void Empty() = 0;        // tree가 비어있는지를 출력하는 함수
    virtual void Size() = 0;         // tree의 크기를 출력하는 함수
};

class Int_AVLtree : public Int_ds
{
public:
    Int_AVLtree();                                           // 생성자 함수
    int getBalanceFactor(Int_AVLtree_Node *current_node);    // balanceFactor를 구하는 함수
    int getDepth(Int_AVLtree_Node *current_node);            // depth를 구하는 함수
    void Balance(Int_AVLtree_Node *current_node, bool flag); // root가 currnt_node인 서브트리에서 균형을 맞추는 함수
    void RightRotate(Int_AVLtree_Node *node_z);              // rightRotate를 실행하는 함수
    void LeftRotate(Int_AVLtree_Node *node_z);               // leftRotate를 실행하는 함수
    void setHeight(Int_AVLtree_Node *current_node);
    int getRank(Int_AVLtree_Node *current_node, int x);                   // key값이 x보다 작은 노드의 개수를 재귀적으로 구하는 함수
    void UpdateLeftSubtreeSize(Int_AVLtree_Node *current_node, int flag); // insert 직후 left_subtree_size를 업데이트 하는 함수
    Int_AVLtree_Node *Search(Int_AVLtree_Node *current_node, int x);      // root가 currnt_node인 서브트리에서 key값이 x인 노드를 찾는 함수
    Int_AVLtree_Node *getRoot() { return root; }
    void setRoot(Int_AVLtree_Node *n) { root = n; }
    int getNode_num() { return node_num; }
    void setNode_num(int x) { node_num = x; }

    void Minimum(int x) override; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    void Maximum(int x) override; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    void Find(int x) override;    // key 값이 x인 노드의 depth를 출력하는 함수
    void Insert(int x) override;  // key값이 x인 노드를 삽입하는 함수
    void Rank(int x) override;    // key값이 x인 노드의 depth와 rank를 출력하는 함수
    void Erase(int x) override;   // key값이 x인 노드를 삭제하는 함수
    void Empty() override;        // tree가 비어있는지를 출력하는 함수
    void Size() override;         // tree의 크기를 출력하는 함수
private:
    Int_AVLtree_Node *root; // tree의 루트 노드
    int node_num;           // tree의 저장된 노드의 숫자
};

// 팩토리 메서드 적용, 단일 책임원칙을 위해 객체 생성역할 분리, 팩토리 메서드에 위임
class ds_creator
{
public:
    Ds *Create_Ds()
    {
        return Get_Ds();
    }
    virtual Ds *Get_Ds() = 0;
};

class Int_ds_creator : public ds_creator
{
public:
    virtual Int_ds *Get_Ds() override = 0;
};

class AVLtree_Int_ds_creator : public Int_ds_creator
{
public:
    Int_AVLtree *Get_Ds()
    {
        return new Int_AVLtree();
    }
};

Int_AVLtree::Int_AVLtree() : root(NULL), node_num(0) {} // 생성자 함수

int Int_AVLtree::getBalanceFactor(Int_AVLtree_Node *current_node) // balanceFactor를 구하는 함수
{
    if (current_node == NULL) // 입력된 노드가 존재하지 않을 경우
    {
        return 0;
    }
    int left_height = 0, right_height = 0;
    if (current_node->getLeft_child() != NULL) // 좌측 자식이없을 경우 좌측 height는 0
    {
        left_height = current_node->getLeft_child()->getHeight() + 1;
    }
    if (current_node->getRight_child() != NULL) // 우측 자식이 없을 경우 우측 height는 0
    {
        right_height = current_node->getRight_child()->getHeight() + 1;
    }
    int balance_factor = left_height - right_height;
    return balance_factor;
}

int Int_AVLtree::getDepth(Int_AVLtree_Node *current_node) // depth를 구하는 함수
{
    if (current_node == NULL)
    {
        return 0;
    }

    int depth = 0;
    while (current_node != getRoot()) // current_node가 root 노드면 탈출
    {
        current_node = current_node->getParent_node();
        depth++;
    }

    return depth;
}

int Int_AVLtree::getRank(Int_AVLtree_Node *current_node, int x)
{                                     // key값이 x보다 작은 노드의 개수를 재귀적으로 구하는 함수
    if (x == current_node->getKey_()) // 현재 노드의 key가 x일 경우 해당 노드의 left_subtree_size값 리턴
    {
        return current_node->getLeft_subtree_size();
    }
    else if (x < current_node->getKey_()) // x값이 현재 노드의 key값보다 작을 경우
    {
        if (current_node->getLeft_child() == NULL) // 왼쪽 자식이 존재하지 않을 경우 해당 노드가 없다는 뜻이므로 탐색 실패
        {
            return -1;
        }
        else // 왼쪽 자식이 존재 할 경우 그곳으로 이동
            return getRank(current_node->getLeft_child(), x);
    }
    else // x값이 현재 노드의 key값보다 클 경우
    {
        if (current_node->getRight_child() == NULL) // 오른쪽 자식이 존재하지 않을 경우 해당 노드가 없다는 뜻이므로 탐색 실패
        {
            return -1;
        }
        else // 오른쪽 자식이 존재하는 경우
        {
            int right_subtree_size = getRank(current_node->getRight_child(), x); // right_size를 재귀적으로 구해옴.
            if (right_subtree_size == -1)                                        // x값을 가진 노드 탐색 실패 할 경우
                return -1;
            else                                                                      //
                return current_node->getLeft_subtree_size() + 1 + right_subtree_size; // 현재노드의 key값이 x보다 작으므로 현재노드의 왼쪽 서브트리 사이즈 + 1 + right size 리턴
        }
    }
}

void Int_AVLtree::UpdateLeftSubtreeSize(Int_AVLtree_Node *current_node, int flag)
{                                                       // insert 직후, rotation전에 left_subtree_size를 업데이트 하는 함수
    if (current_node == getRoot() || getRoot() == NULL) // 루트,NULL 도달 시 종료
    {
        return;
    }
    else
    {
        if (current_node == current_node->getParent_node()->getLeft_child()) // current_node가 부모의 왼쪽 자식일 경우 부모의 left_subtree_size 1 증가
        {
            current_node->getParent_node()->setLeft_subtree_size(current_node->getParent_node()->getLeft_subtree_size() + flag);
        }
        return UpdateLeftSubtreeSize(current_node->getParent_node(), flag); // 재귀적으로 루트까지 업데이트
    }
}

Int_AVLtree_Node *Int_AVLtree::Search(Int_AVLtree_Node *current_node, int x) // root가 current_node인 서브트리에서 key값이 x인 노드를 찾는 함수
{
    while (current_node != NULL)
    {
        if (x == current_node->getKey_())
        {
            return current_node;
        } // key값이 x인 노드 발견 성공시 해당 노드 포인터 리턴
        else if (x < current_node->getKey_())
        { // x값이 현재 노드의 key값보다 작을 경우 현재노드의 left_child로 이동
            current_node = current_node->getLeft_child();
        }
        else
        { // x값이 현재 노드의 key값보다 클 경우 현재 노드의 right_child로 이동
            current_node = current_node->getRight_child();
        }
    }
    return NULL; // key가 x인 노드를 찾지 못하고 leaf 노드에 도달 한 경우 x값을 가진 노드가 없다는 뜻이므로 NULL리턴
}

void Int_AVLtree::setHeight(Int_AVLtree_Node *current_node) // 노드의 height 변수를 세팅해주는 함수
{
    if (current_node == NULL) //부모 노드의 parent 혹은 Null에 도달했을 경우 재귀 종료
    {
        return;
    }
    if (current_node->getLeft_child() == NULL && current_node->getRight_child() == NULL)
    { // 리프노드의 height는 0
        current_node->setHeight(0);
    }
    else
    { // 좌,우 자식의 height중 더 높은것 +1이 자신의 height가 됨.
        int left_height = -1, right_height = -1;
        if (current_node->getLeft_child() != NULL)  //왼쪽자식의 height 불러오기
        {
            left_height = current_node->getLeft_child()->getHeight();
        }
        if (current_node->getRight_child() != NULL)  //오른쪽 자식의 height 불러오기
        {
            right_height = current_node->getRight_child()->getHeight();
        }
        current_node->setHeight(std::max(left_height, right_height) + 1);
    }
    return setHeight(current_node->getParent_node()); // 재귀호출을 통해 추가된 리프노드부터 부모까지 height 업데이트
}

void Int_AVLtree::Balance(Int_AVLtree_Node *current_node, bool flag) // root가 currnt_node인 서브트리에서 균형을 맞추는 함수 , flag가 true면 insert ,false면 delete
{
    if (current_node == NULL) // currenr_node가 없는 경우
    {
        return;
    }
    int current_node_balance_factor = getBalanceFactor(current_node); // currnet_node의 balance factor

    if (current_node_balance_factor <= 1 && current_node_balance_factor >= -1) // 높이차가 1이하인 경우(balancefactor가 -1에서 1사이인 경우)
    {
        return Balance(current_node->getParent_node(), flag);
    }
    else if (current_node_balance_factor >= 1) // 왼쪽 자식 노드의 높이가 2이상으로 더 높은 경우
    {
        if (getBalanceFactor(current_node->getLeft_child()) >= 0) // LL 변환
        {
            RightRotate(current_node);
        }
        else // LR 변환
        {
            LeftRotate(current_node->getLeft_child());
            RightRotate(current_node);
        }
        if (flag)  //insert의 경우 balance 한번만 수행함. erase의 경우 재귀적으로 root까지 balance check 필요.
        {
            return;
        }
    }
    else if (current_node_balance_factor <= -1) // 오른쪽 자식 노드의 높이가 2이상으로 더 높은 경우
    {
        if (getBalanceFactor(current_node->getRight_child()) > 0) // RL 변환
        {
            RightRotate(current_node->getRight_child());
            LeftRotate(current_node);
        }
        else // RR 변환
        {
            LeftRotate(current_node);
        }
        if (flag)  //insert의 경우 balance 한번만 수행함. erase의 경우 재귀적으로 root까지 balance check 필요.
        {
            return;
        }
    }
    return Balance(current_node->getParent_node(), flag);
}

void Int_AVLtree::RightRotate(Int_AVLtree_Node *node_z) // rightRotate를 실행하는 함수
{
    Int_AVLtree_Node *node_y = node_z->getLeft_child();
    Int_AVLtree_Node *T2_root = node_y->getRight_child();

    node_y->setRight_child(node_z);
    node_z->setLeft_child(T2_root);

    if (node_z->getParent_node() == NULL) // node_z가 루트노드였을 경우
    {
        setRoot(node_y); // node_y를 루트노트로 설정
        node_y->setParent_node(NULL);
    }
    else if (node_z->getParent_node()->getLeft_child() == node_z) // node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->getParent_node()->setLeft_child(node_y);
    }
    else // node_z가 부모노드의 오른쪽 자식 노드였을 경우
    {
        node_z->getParent_node()->setRight_child(node_y);
    }
    node_y->setParent_node(node_z->getParent_node());
    node_z->setParent_node(node_y);
    if (T2_root != NULL)  //NULL일 경우 NullPointerError유발위험때문에 체크 후 연결
    {
        T2_root->setParent_node(node_z);
    }

    node_z->setLeft_subtree_size(node_z->getLeft_subtree_size() - (node_y->getLeft_subtree_size() + 1)); // node_z의 왼쪽 서브트리의 사이즈 변화
    setHeight(node_z);
    return;
}

void Int_AVLtree::LeftRotate(Int_AVLtree_Node *node_z) // leftRotate를 실행하는 함수
{
    Int_AVLtree_Node *node_y = node_z->getRight_child();
    Int_AVLtree_Node *T2_root = node_y->getLeft_child();

    node_y->setLeft_child(node_z);
    node_z->setRight_child(T2_root);

    if (node_z->getParent_node() == NULL) // node_z가 루트노드였을 경우
    {
        setRoot(node_y); // node_y를 루트노트로 설정
        node_y->setParent_node(NULL);
    }
    else if (node_z->getParent_node()->getLeft_child() == node_z) // node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->getParent_node()->setLeft_child(node_y);
    }
    else // node_z가 부모노드의 왼쪽 자식 노드였을 경우
    {
        node_z->getParent_node()->setRight_child(node_y);
    }
    node_y->setParent_node(node_z->getParent_node());
    node_z->setParent_node(node_y);
    if (T2_root != NULL)  //NULL일 경우 NullPointerError유발위험때문에 체크 후 연결
    {
        T2_root->setParent_node(node_z);
    }
    node_y->setLeft_subtree_size(node_y->getLeft_subtree_size() + node_z->getLeft_subtree_size() + 1); // node_y의 왼쪽 서브트리의 사이즈 변화
    setHeight(node_z);
    return;
}

void Int_AVLtree::Minimum(int x) // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    Int_AVLtree_Node *minimum_node = Search(getRoot(), x); // x를 key값으로 가지는 노드
    while (minimum_node->getLeft_child() != NULL)          // 노드가 존재할때 까지 실행
    {
        minimum_node = minimum_node->getLeft_child(); // minimum_node를 minimum_node의 왼쪽 자식 노드로 바꿈
    }
    int minimum_node_depth = getDepth(minimum_node); // minimum_node의 depth를 구함
    std::cout << minimum_node->getKey_() << " " << minimum_node_depth << "\n";
}

void Int_AVLtree::Maximum(int x) // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
{
    Int_AVLtree_Node *root_subtree = Search(getRoot(), x); // x를 key값으로 가지는 노드
    Int_AVLtree_Node *maximum_node = root_subtree;
    while (maximum_node->getRight_child() != NULL) // 노드가 존재할때 까지 실행
    {
        maximum_node = maximum_node->getRight_child(); // maximum_node를 minimum_node의 오른쪽 자식 노드로 바꿈
    }
    int maximum_node_depth = getDepth(maximum_node); ////maximum_node의 depth를 구함
    std::cout << maximum_node->getKey_() << " " << maximum_node_depth << "\n";
}

void Int_AVLtree::Empty() // tree가 비어있는지를 출력하는 함수
{
    if (getNode_num() == 0) // tree가 비었을때
    {
        std::cout << 1 << "\n";
        return;
    }
    else // tree가 비어있지 않을 때
    {
        std::cout << 0 << "\n";
        return;
    }
}

void Int_AVLtree::Size() // tree의 크기를 출력하는 함수
{
    std::cout << getNode_num() << "\n";
    return;
}