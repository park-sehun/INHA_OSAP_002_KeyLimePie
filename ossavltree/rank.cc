#include "set.h"

void Int_AVLtree::Rank(int x)
{ // key값이 x인 노드의 depth와 rank를 출력하는 함수
    Int_AVLtree_Node *node_of_x = search(getRoot(), x);
    if (node_of_x == NULL)
    {
        std::cout << 0 << "\n";
        return;
    }
    int rank_of_x = getRank(getRoot(), x) + 1; // rank값 : key값이 x보다 작은 노드의 개수 +1
    int depth = getDepth(node_of_x);
    std::cout << depth << " " << rank_of_x << "\n";
}