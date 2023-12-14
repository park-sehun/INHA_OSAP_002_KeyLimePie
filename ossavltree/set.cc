 #include "set.h"
 
 Int_AVLtree_set::Int_AVLtree_set()
    {
        AVLtree_Int_ds_creator ds_creator;
        DataStructure = (Int_AVLtree *)ds_creator.Create_Ds();
    }

    std::pair<int,int> Int_AVLtree_set::Minimum(int x) // key값이 x인 노드가 루트인 서브트리에서의 최소 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        return DataStructure->Minimum(x);
    }
    std::pair<int,int> Int_AVLtree_set::Maximum(int x) // key값이 x인 노드가 루트인 서브트리에서의 최대 key를 가지는 노드의 key와 depth를 출력하는 함수
    {
        return DataStructure->Maximum(x);
    }
    int Int_AVLtree_set::Find(int x) // key 값이 x인 노드의 depth를 출력하는 함수
    {
        return DataStructure->Find(x);
    }
    int Int_AVLtree_set::Insert(int x) // key값이 x인 노드를 삽입하는 함수
    {
        return DataStructure->Insert(x);
    }
    std::pair<int,int> Int_AVLtree_set::Rank(int x) // key값이 x인 노드의 depth와 rank를 출력하는 함수
    {
        return DataStructure->Rank(x);
    }
    int Int_AVLtree_set::Erase(int x) // key값이 x인 노드를 삭제하는 함수
    {
        return DataStructure->Erase(x);
    }
    bool Int_AVLtree_set::Empty() // tree가 비어있는지를 출력하는 함수
    {
        return DataStructure->Empty();
    }
    int Int_AVLtree_set::Size() // tree의 크기를 출력하는 함수
    {
        return DataStructure->Size();
    }