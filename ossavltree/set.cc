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