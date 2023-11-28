#include "avltree.h"

void AVLtree::Find(int x) //key 값이 x인 노드의 depth를 출력하는 함수
{
    node* result = Search(root, x); //key 값이 x인 노드 search
    int depth = getDepth(result); // Get the depth of the found node
    std::cout << depth << "\n";
}