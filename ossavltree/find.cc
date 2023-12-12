#include "set.h"

void Int_AVLtree::Find(int x) //key 값이 x인 노드의 depth를 출력하는 함수
{
    Int_AVLtree_Node* result = search(root, x); //key 값이 x인 노드 search
    int depth = getDepth(result); // Get the depth of the found node
    std::cout << depth << "\n";
}