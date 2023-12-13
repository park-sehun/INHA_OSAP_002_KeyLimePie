/*
BSD-3-Clause
Copyright (c) 2023, Huiju Lee
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
DISCLAIMED. IN NO EVENT SHALL Huiju Lee BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

작성자 : 이희주
작성일 : 2023년 11월 26일
*/

#include "set.h"

int Int_AVLtree::Erase(int x)
{ // key값이 x인 노드를 삭제하는 함수
    Int_AVLtree_Node *delete_node = Search(getRoot(), x);

    if (delete_node == NULL)
    {
        return 0;
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
    Balance(tmp_parent, false);

    return depth; // depth를 출력해야 함
}