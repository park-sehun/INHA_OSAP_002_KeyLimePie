/*
BSD-3-Clause
Copyright (c) 2023, Jihwan Kim
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
DISCLAIMED. IN NO EVENT SHALL Jihwan Kim Yun BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

작성자 : 김지환
작성일 : 2023년 12월 13일
*/
#ifndef OSSAVLTREE_NODE_H_
#define OSSAVLTREE_NODE_H_
#include <iostream>
#include <iostream>
class Node
{
};

class Int_Node : public Node
{
public:
    Int_Node() : key_(0) {}
    Int_Node(int x) : key_(x) {}
    void setKey_(int x) { key_ = x; }
    int getKey_() { return key_; }

private:
    int key_; // key값
};

class Int_AVLtree_Node : public Int_Node
{
public:
    Int_AVLtree_Node() : Int_Node(0), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0) {}
    Int_AVLtree_Node(int x) : Int_Node(x), parent_node(NULL), left_child(NULL), right_child(NULL), left_subtree_size(0), height(0) {} // 생성자 함수
    void setLeft_child(Int_AVLtree_Node *n) { left_child = n; }
    Int_AVLtree_Node *getLeft_child() { return left_child; }
    void setRight_child(Int_AVLtree_Node *n) { right_child = n; }
    Int_AVLtree_Node *getRight_child() { return right_child; }
    void setParent_node(Int_AVLtree_Node *n) { parent_node = n; }
    Int_AVLtree_Node *getParent_node() { return parent_node; }
    void setLeft_subtree_size(int x) { left_subtree_size = x; }
    int getLeft_subtree_size() { return left_subtree_size; }
    void setHeight(int x) { height = x; }
    int getHeight() { return height; }

private:
    Int_AVLtree_Node *left_child;  // 왼쪽 자식노드
    Int_AVLtree_Node *right_child; // 오른쪽 자식노드
    Int_AVLtree_Node *parent_node; // 부모 노드
    int left_subtree_size;         // 왼쪽 서브트리의 사이즈
    int height;                    // 높이
};

// 팩토리 메서드 적용, 단일 책임원칙을 위해 객체 생성역할 분리, 팩토리 메서드에 위임
class Node_creator
{
};

class Int_node_creator : public Node_creator
{
public:
    Int_Node *CreateNode(int x)
    {
        return Get_Node(x);
    }
    virtual Int_Node *Get_Node(int x) = 0;
};

class AVLtree_Int_node_creator : public Int_node_creator
{
public:
    Int_AVLtree_Node *Get_Node(int x)
    {
        return new Int_AVLtree_Node(x);
    }
};

#endif