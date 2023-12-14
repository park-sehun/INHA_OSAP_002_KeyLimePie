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
#ifndef KEYLIMEPIE_OSSAVLTREE_DATA_STRUCTURE_H_
#define KEYLIMEPIE_OSSAVLTREE_DATA_STRUCTURE_H_

#include <iostream>
#include "node.h"

class Ds
{
public:
};

class Int_ds : public Ds
{
public:
    virtual std::pair<int, int> Minimum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    virtual std::pair<int, int> Maximum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    virtual int Find(int x) = 0;                    // key 값이 x인 노드의 depth를 출력하는 함수
    virtual int Insert(int x) = 0;                  // key값이 x인 노드를 삽입하는 함수
    virtual std::pair<int, int> Rank(int x) = 0;    // key값이 x인 노드의 depth와 rank를 출력하는 함수
    virtual int Erase(int x) = 0;                   // key값이 x인 노드를 삭제하는 함수
    virtual bool Empty() = 0;                       // tree가 비어있는지를 출력하는 함수
    virtual int Size() = 0;                         // tree의 크기를 출력하는 함수
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

    std::pair<int, int> Minimum(int x) override; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    std::pair<int, int> Maximum(int x) override; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    int Find(int x) override;                    // key 값이 x인 노드의 depth를 출력하는 함수
    int Insert(int x) override;                  // key값이 x인 노드를 삽입하는 함수
    std::pair<int, int> Rank(int x) override;    // key값이 x인 노드의 depth와 rank를 출력하는 함수
    int Erase(int x) override;                   // key값이 x인 노드를 삭제하는 함수
    bool Empty() override;                       // tree가 비어있는지를 출력하는 함수
    int Size() override;                         // tree의 크기를 출력하는 함수
private:
    Int_AVLtree_Node *root; // tree의 루트 노드
    int node_num;           // tree의 저장된 노드의 숫자
};

// 팩토리 메서드 적용, 단일 책임원칙을 위해 객체 생성역할 분리, 팩토리 메서드에 위임
class ds_creator
{
public:
    Ds *Create_Ds();
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
    Int_AVLtree *Get_Ds();
};

#endif