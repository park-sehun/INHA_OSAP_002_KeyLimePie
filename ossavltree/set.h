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
#ifndef KEYLIMEPIE_OSSAVLTREE_SET_H_
#define KEYLIMEPIE_OSSAVLTREE_SET_H_

#include <iostream>

#include "data_structure.h"
#include "node.h"

// 데이터 타입에 따라, 그리고 내부 자료 구조형에 따라 기존 클래스 수정없이 확장 가능하도록 구현
class set
{
};

class Int_set : public set
{
public:
    virtual std::pair<int,int> Minimum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual std::pair<int,int> Maximum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual int Find(int x) = 0; // key 값이 x인 노드의 depth를 출력하는 함수

    virtual int Insert(int x) = 0; // key값이 x인 노드를 삽입하는 함수

    virtual std::pair<int,int> Rank(int x) = 0; // key값이 x인 노드의 depth와 rank를 출력하는 함수

    virtual int Erase(int x) = 0; // key값이 x인 노드를 삭제하는 함수

    virtual bool Empty() = 0; // tree가 비어있는지를 출력하는 함수

    virtual int Size() = 0; // tree의 크기를 출력하는 함수
};

class Int_AVLtree_set : public Int_set
{
public:
    Int_AVLtree_set()
    {
        AVLtree_Int_ds_creator ds_creator;
        DataStructure = (Int_AVLtree *)ds_creator.Create_Ds();
    }

    std::pair<int,int> Minimum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        return DataStructure->Minimum(x);
    }
    std::pair<int,int> Maximum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        return DataStructure->Maximum(x);
    }
    int Find(int x) override // key 값이 x인 노드의 depth를 출력하는 함수
    {
        return DataStructure->Find(x);
    }
    int Insert(int x) override // key값이 x인 노드를 삽입하는 함수
    {
        return DataStructure->Insert(x);
    }
    std::pair<int,int> Rank(int x) override // key값이 x인 노드의 depth와 rank를 출력하는 함수
    {
        return DataStructure->Rank(x);
    }
    int Erase(int x) override // key값이 x인 노드를 삭제하는 함수
    {
        return DataStructure->Erase(x);
    }
    bool Empty() override // tree가 비어있는지를 출력하는 함수
    {
        return DataStructure->Empty();
    }
    int Size() override // tree의 크기를 출력하는 함수
    {
        return DataStructure->Size();
    }

private:
    Int_AVLtree *DataStructure;
};

#endif
