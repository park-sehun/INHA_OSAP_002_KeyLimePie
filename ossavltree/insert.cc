/*
BSD-3-Clause
Copyright (c) 2023, Beongchul Yun
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
DISCLAIMED. IN NO EVENT SHALL Beongchul Yun BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

작성자 : 윤병철
작성일 : 2023년 11월 14일
*/
#include "data_structure.h"

int Int_AVLtree::Insert(int x) // key값이 x인 노드를 삽입하는 함수
{
    AVLtree_Int_node_creator node_creator;
    Int_AVLtree_Node *new_node = (Int_AVLtree_Node *)node_creator.CreateNode(x); // 새로운 노드 생성
    if (getNode_num() == 0)                                                      // tree가 비어있을 때
    {
        setRoot(new_node);
        setNode_num(getNode_num() + 1);
        return getDepth(new_node);
    }

    Int_AVLtree_Node *current_node = getRoot(); // new_node가 삽일될 노드
    Int_AVLtree_Node *parent_node = NULL;       // 부모 노드가 될 노드
    int child_factor = 0;                       // 왼쪽 자식 노드인지 오른쪽 자식 노드인지 결정하는 인자

    while (current_node != NULL)
    {
        parent_node = current_node;
        if (current_node->getKey_() > x) // current_node key가 x보다 클 때
        {
            current_node = current_node->getLeft_child();
            child_factor = -1;
        }
        else if (current_node->getKey_() < x) // current_node key가 x보다 작을 때
        {
            current_node = current_node->getRight_child();
            child_factor = 1;
        }
        else if (current_node->getKey_() == x) // x를 key값으로 가지는 노드가 이미 존재할 때
        {
            return -1;
        }
    }

    new_node->setParent_node(parent_node);

    if (child_factor == -1) // 왼쪽 자식 노드일 경우
    {
        parent_node->setLeft_child(new_node);
    }
    else if (child_factor == 1) // 오른쪽 자식 노드일 경우
    {
        parent_node->setRight_child(new_node);
    }
    else // 에러가 일어났을 경우
    {
        return -1;
    }
    setNode_num(getNode_num() + 1);
    UpdateLeftSubtreeSize(new_node, 1);
    setHeight(new_node);
    Balance(new_node, true);
    return getDepth(new_node);
}