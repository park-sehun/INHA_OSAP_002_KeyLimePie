#include "avltree.h"

void AVLtree::Rank(int x) { //key값이 x인 노드의 depth와 rank를 출력하는 함수
    node* node_of_x = Search(root, x);
    if (node_of_x == NULL) {  //key값이 x인 노드를 찾지 못한 경우 0출력 후 종료
        std::cout << 0 << "\n"; 
        return;
    }
    int rank_of_x = getRank(root, x) + 1; //rank값 : key값이 x보다 작은 노드의 개수 +1
    int depth = getDepth(node_of_x);
    std::cout <<depth<<" " << rank_of_x << "\n";
}