#include "avltree.h"

void AVLtree::Rank(int x) { //key값이 x인 노드의 depth와 rank를 출력하는 함수
    int rank_of_x = getRank(root, x) + 1; //rank값 : key값이 x보다 작은 노드의 개수 +1 
    std::cout << rank_of_x << "\n";
}