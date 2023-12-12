#ifndef OSSAVLTREE_OSSAVLTREE_AVLTREE_H_
#define OSSAVLTREE_OSSAVLTREE_AVLTREE_H_
#include <iostream>
#include "node.h"
#include <data_structure.h>

// 데이터 타입에 따라, 그리고 내부 자료 구조형에 따라 기존 클래스 수정없이 확장 가능하도록 구현
class set
{
};

class Int_set : public set
{
public:
    virtual void minimum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual void maximum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual void find(int x) = 0; // key 값이 x인 노드의 depth를 출력하는 함수

    virtual void insert(int x) = 0; // key값이 x인 노드를 삽입하는 함수

    virtual void rank(int x) = 0; // key값이 x인 노드의 depth와 rank를 출력하는 함수

    virtual void erase(int x) = 0; // key값이 x인 노드를 삭제하는 함수

    virtual void empty() = 0; // tree가 비어있는지를 출력하는 함수

    virtual void size() = 0; // tree의 크기를 출력하는 함수
};

class Int_AVLtree_set : public Int_set
{
public:
    Int_AVLtree *DataStructure;

    Int_AVLtree_set()
    {
        AVLtree_Int_ds_creator ds_creator;
        DataStructure = (Int_AVLtree *)ds_creator.Create_Ds();
    }

    void minimum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        DataStructure->Minimum(x);
    }
    void maximum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        DataStructure->Maximum(x);
    }
    void find(int x) override // key 값이 x인 노드의 depth를 출력하는 함수
    {
        DataStructure->Find(x);
    }
    void insert(int x) override // key값이 x인 노드를 삽입하는 함수
    {
        DataStructure->Insert(x);
    }
    void rank(int x) override // key값이 x인 노드의 depth와 rank를 출력하는 함수
    {
        DataStructure->Rank(x);
    }
    void erase(int x) override // key값이 x인 노드를 삭제하는 함수
    {
        DataStructure->Erase(x);
    }
    void empty() override // tree가 비어있는지를 출력하는 함수
    {
        DataStructure->Empty();
    }
    void size() override // tree의 크기를 출력하는 함수
    {
        DataStructure->Size();
    }
};

#endif
