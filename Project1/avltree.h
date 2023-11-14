#pragma once
using namespace std;

struct node
{
    int key; //key��
    node* left_child; //���� �ڽĳ��
    node* right_child; //������ �ڽĳ��
    node* parent_node; //�θ� ���
    int left_subtree_size; //���� ����Ʈ���� ������
    node(int key) //������ �Լ�
    {
        this->key = key;
        parent_node = left_child = right_child = NULL;
        left_subtree_size = 0;
    }
};

class AVLtree
{
public:
    AVLtree(); //������ �Լ�
    int getHeight(node* current_node); //height�� ���ϴ� �Լ� 
    int getBalanceFactor(node* current_node); //balanceFactor�� ���ϴ� �Լ�
    int getDepth(node* current_node); //depth�� ���ϴ� �Լ�
    node* search(node* current_node, int x); //root�� currnt_node�� ����Ʈ������ key���� x�� ��带 ã�� �Լ�
    void balance(node* current_node); //root�� currnt_node�� ����Ʈ������ ������ ���ߴ� �Լ�
    void rightRotate(node* node_z); //rightRotate�� �����ϴ� �Լ�
    void leftRotate(node* node_z); //leftRotate�� �����ϴ� �Լ�
    void minimum(int x); //key���� x�� ��尡 ��Ʈ�� ����Ʈ�������� �ּ� key�� ������ ����� key�� depth�� ����ϴ� �Լ�
    void maximum(int x); //key���� x�� ��尡 ��Ʈ�� ����Ʈ�������� �ִ� key�� ������ ����� key�� depth�� ����ϴ� �Լ�
    void empty(); //tree�� ����ִ����� ����ϴ� �Լ�
    void size(); //tree�� ũ�⸦ ����ϴ� �Լ�
    void find(int x); //key ���� x�� ����� depth�� ����ϴ� �Լ�
    int insert(int x); //key���� x�� ��带 �����ϴ� �Լ�
    void rank(int x); //key���� x�� ����� depth�� rank�� ����ϴ� �Լ�
    void erase(int x); //key���� x�� ��带 �����ϴ� �Լ� 

private:
    int node_num; //tree�� ����� ����� ����
    node* root; //tree�� ��Ʈ ���
};

AVLtree::AVLtree() //������ �Լ�
{
    root = NULL;
    node_num = 0;
}

int AVLtree::getHeight(node* current_node) //height�� ���ϴ� �Լ� 
{
    if (current_node == NULL) //�Էµ� ��尡 �������� ���� ���
    {
        return 0;
    }
    else
    {
        int left_child_height = getHeight(current_node->left_child);
        int right_child_height = getHeight(current_node->right_child);
        int max_height = std::max(left_child_height, right_child_height);
        return max_height + 1;
    }
}

int AVLtree::getBalanceFactor(node* current_node) //balanceFactor�� ���ϴ� �Լ�
{
    if (current_node == NULL) //�Էµ� ��尡 �������� ���� ���
    {
        return 0;
    }
    int balance_factor = getHeight(current_node->left_child) - getHeight(current_node->right_child);
    return balance_factor;
}

int AVLtree::getDepth(node* current_node) //depth�� ���ϴ� �Լ�
{
    if (current_node == NULL)
    {
        return 0;;
    }

    int depth = 0;
    while (current_node != root)
    {
        current_node = current_node->parent_node;
        depth++;
    }

    return depth;;
}

node* AVLtree::search(node* current_node, int x) //root�� currnt_node�� ����Ʈ������ key���� x�� ��带 ã�� �Լ�
{
    return 0;
}

void AVLtree::balance(node* current_node) //root�� currnt_node�� ����Ʈ������ ������ ���ߴ� �Լ�
{
    if (current_node == NULL) //currenr_node�� ���� ���
    {
        std::cout << "�߸��� �Է��Դϴ�./balance"
            << "\n";
        return;
    }
    int current_node_balance_factor = getBalanceFactor(current_node); //currnet_node�� balance factor

    if (current_node_balance_factor <= 1 && current_node_balance_factor >= 1) //�������� 1������ ���
    {
        return;
    }
    else if (current_node_balance_factor > 1) //���� �ڽ� ����� ���̰� 2�̻����� �� ���� ���
    {
        if (getBalanceFactor(current_node->left_child) > 1) // LL ��ȯ
        {
            rightRotate(current_node);
        }
        if (getBalanceFactor(current_node->left_child) < -1) // LR ��ȯ
        {
            leftRotate(current_node->left_child);
            rightRotate(current_node);
        }
    }
    else if (current_node_balance_factor < -1) //������ �ڽ� ����� ���̰� 2�̻����� �� ���� ���
    {
        if (getBalanceFactor(current_node->right_child) > 1) // RL ��ȯ
        {
            rightRotate(current_node->right_child);
            leftRotate(current_node);
        }
        if (getBalanceFactor(current_node->right_child) < -1) // RR ��ȯ
        {
            leftRotate(current_node);
        }
    }
}

void AVLtree::rightRotate(node* node_z) //rightRotate�� �����ϴ� �Լ�
{
    node* node_y = node_z->left_child;
    node* T2_root = node_y->right_child;

    node_y->right_child = node_z;
    node_z->left_child = T2_root;

    if (node_z->parent_node == NULL) // node_z�� ��Ʈ��忴�� ���
    {
        root = node_y; //node_y�� ��Ʈ��Ʈ�� ����
        node_y->parent_node = NULL;
    }
    else if (node_z->parent_node->left_child == node_z) //node_z�� �θ����� ���� �ڽ� ��忴�� ���
    {
        node_z->parent_node->left_child = node_y;
    }
    else //node_z�� �θ����� ������ �ڽ� ��忴�� ���
    {
        node_z->parent_node->right_child = node_y;
    }
    node_y->parent_node = node_z->parent_node;
    node_z->parent_node = node_y;
    T2_root->parent_node = node_z;

    node_z->left_subtree_size = node_z->left_subtree_size - (node_y->left_subtree_size + 1); // node_z�� ���� ����Ʈ���� ������ ��ȭ
    return;
}

void AVLtree::leftRotate(node* node_z) //leftRotate�� �����ϴ� �Լ�
{
    node* node_y = node_z->right_child;
    node* T2_root = node_y->left_child;

    node_y->left_child = node_z;
    node_z->right_child = T2_root;

    if (node_z->parent_node == NULL) // node_z�� ��Ʈ��忴�� ���
    {
        root = node_y; //node_y�� ��Ʈ��Ʈ�� ����
        node_y->parent_node = NULL;
    }
    else if (node_z->parent_node->left_child == node_z) //node_z�� �θ����� ���� �ڽ� ��忴�� ���
    {
        node_z->parent_node->left_child = node_y;
    }
    else //node_z�� �θ����� ���� �ڽ� ��忴�� ���
    {
        node_z->parent_node->right_child = node_y;
    }
    node_y->parent_node = node_z->parent_node;
    node_z->parent_node = node_y;
    T2_root->parent_node = node_z;

    node_y->left_subtree_size = node_y->left_subtree_size + node_z->left_subtree_size + 1; // node_y�� ���� ����Ʈ���� ������ ��ȭ
    return;
}

void AVLtree::minimum(int x) //key���� x�� ��尡 ��Ʈ�� ����Ʈ�������� �ּ� key�� ������ ����� key�� depth�� ����ϴ� �Լ�
{
    node* minimum_node = search(root, x); //x�� key������ ������ ���
    while (minimum_node->left_child != NULL) //��尡 �����Ҷ� ���� ����
    {
        minimum_node = minimum_node->left_child; //minimum_node�� minimum_node�� ���� �ڽ� ���� �ٲ�
    }
    int minmum_node_depth = getDepth(minimum_node); //minimum_node�� depth�� ����
    std::cout << minmum_node_depth << "\n";
}

void AVLtree::maximum(int x) //key���� x�� ��尡 ��Ʈ�� ����Ʈ�������� �ִ� key�� ������ ����� key�� depth�� ����ϴ� �Լ�
{
    node* root_subtree = search(root, x); //x�� key������ ������ ���
    node* maximum_node = root_subtree;
    while (maximum_node->right_child != NULL) //��尡 �����Ҷ� ���� ����
    {
        maximum_node = maximum_node->right_child; //maximum_node�� minimum_node�� ������ �ڽ� ���� �ٲ�
    }
    int maxmum_node_depth = getDepth(maximum_node); ////maximum_node�� depth�� ����
    std::cout << maxmum_node_depth << "\n";
}

void AVLtree::empty() //tree�� ����ִ����� ����ϴ� �Լ�
{
    if (node_num == 0) //tree�� �������
    {
        std::cout << 1 << "\n";
        return;
    }
    else //tree�� ������� ���� ��
    {
        std::cout << 0 << "\n";
        return;
    }
}

void AVLtree::size() //tree�� ũ�⸦ ����ϴ� �Լ�
{
    std::cout << node_num << "\n";
    return;
}

void AVLtree::find(int x) //key ���� x�� ����� depth�� ����ϴ� �Լ�
{
    node* result = search(root, x); //key ���� x�� ��� search
    if (result != NULL)
    {
        int depth = getDepth(result); // Get the depth of the found node
        cout << depthg << "\n";
    }
    else
    {
        cout << "0" << "\n";
    }

}

int AVLtree::insert(int x) //key���� x�� ��带 �����ϴ� �Լ�
{
    node* new_node = new node(x);//���ο� ��� ����
    if (node_num == 0) //tree�� ������� ��
    {
        root = new_node;
        return getDepth(new_node);
    }

    node* current_node = root; //new_node�� ���ϵ� ���
    node* parent_node = NULL; //�θ� ��尡 �� ���
    int child_factor = 0; //���� �ڽ� ������� ������ �ڽ� ������� �����ϴ� ����

    while (current_node != NULL)
    {
        parent_node = current_node;
        if (current_node->key > x) //current_node key�� x���� Ŭ ��
        {
            current_node = current_node->left_child;
            child_factor = -1;
        }
        else if (current_node->key < x) //current_node key�� x���� ���� ��
        {
            current_node = current_node->right_child;
            child_factor = 1;
        }
        else if (current_node->key == x) //x�� key������ ������ ��尡 �̹� ������ ��
        {
            std::cout << "�̹� �����ϴ� ���Դϴ�./insert"
                << "\n";
            return;
        }
    }

    new_node->parent_node = parent_node;

    if (child_factor == -1) //���� �ڽ� ����� ���
    {
        parent_node->left_child = new_node;
    }
    else if (child_factor == 1) //������ �ڽ� ����� ���
    {
        parent_node->right_child = new_node;
    }
    else //������ �Ͼ�� ���
    {
        std::cout << "�߸��� child_factor ���Դϴ�./insert"
            << "\n";
        return;
    }
    return getDepth(new_node);
}

void AVLtree::rank(int x) { //key���� x�� ����� depth�� rank�� ����ϴ� �Լ�

}

void AVLtree::erase(int x) { //key���� x�� ��带 �����ϴ� �Լ� 

}

