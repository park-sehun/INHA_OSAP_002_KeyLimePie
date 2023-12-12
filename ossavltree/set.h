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
    virtual void Minimum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual void Maximum(int x) = 0; // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수

    virtual void Find(int x) = 0; // key 값이 x인 노드의 depth를 출력하는 함수

    virtual void Insert(int x) = 0; // key값이 x인 노드를 삽입하는 함수

    virtual void Rank(int x) = 0; // key값이 x인 노드의 depth와 rank를 출력하는 함수

    virtual void Erase(int x) = 0; // key값이 x인 노드를 삭제하는 함수

    virtual void Empty() = 0; // tree가 비어있는지를 출력하는 함수

    virtual void Size() = 0; // tree의 크기를 출력하는 함수
};

class Int_AVLtree_set : public Int_set
{
public:
    Int_AVLtree_set()
    {
        AVLtree_Int_ds_creator ds_creator;
        DataStructure = (Int_AVLtree *)ds_creator.Create_Ds();
    }

    void Minimum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        DataStructure->Minimum(x);
    }
    void Maximum(int x) override // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        DataStructure->Maximum(x);
    }
    void Find(int x) override // key 값이 x인 노드의 depth를 출력하는 함수
    {
        DataStructure->Find(x);
    }
    void Insert(int x) override // key값이 x인 노드를 삽입하는 함수
    {
        DataStructure->Insert(x);
    }
    void Rank(int x) override // key값이 x인 노드의 depth와 rank를 출력하는 함수
    {
        DataStructure->Rank(x);
    }
    void Erase(int x) override // key값이 x인 노드를 삭제하는 함수
    {
        DataStructure->Erase(x);
    }
    void Empty() override // tree가 비어있는지를 출력하는 함수
    {
        DataStructure->Empty();
    }
    void Size() override // tree의 크기를 출력하는 함수
    {
        DataStructure->Size();
    }

private:
    Int_AVLtree *DataStructure;
};

#endif
