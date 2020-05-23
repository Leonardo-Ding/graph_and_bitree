#include <iostream>
#include <stack>

typedef struct TreeNode{
    char data;
    TreeNode *left, *right;
} TreeNode;

// void CreateBiTree(TreeNode** T) { 
//     //if (T = nullptr) return;
//     char ch;
//     std::cin >> ch;
//     if (ch == '#') {
//         *T = nullptr;
//         //return;
//     }
//     else {
//         *T = new TreeNode();
//         (*T)->data = ch;
//         CreateBiTree(&(*T)->left);
//         CreateBiTree(&(*T)->right);
//     }
// }
void CreateBiTree(TreeNode* &T) { 
    //if (T = nullptr) return;
    char ch;
    std::cin >> ch;
    if (ch == '#') {
        T = nullptr;
        //return;
    }
    else {
        T = new TreeNode();
        T->data = ch;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}
void PreOrder(TreeNode *T) {
    TreeNode* p = T;
    std::stack<TreeNode*> s;
    while (p !=nullptr || !s.empty()) {
        if (p != nullptr) {
            s.push(p);
            std::cout << p->data << std::endl;
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

//中序遍历非递归
void MidOrder(TreeNode *T){
    TreeNode *p = T;
    std::stack<TreeNode*> s;
    while (p != nullptr || !s.empty()){
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            std::cout << p->data << std::endl;
            p = p->right;
        }
    }
}

//后序遍历非递归
void PostOrder(TreeNode *T) {
    TreeNode *p = T;
    TreeNode *last = nullptr;
    std::stack<TreeNode*> s;
    while (p != nullptr || !s.empty()) {
        while (p != nullptr){
            s.push(p);
            p = p->left;
        }
        p = s.top();
        if (p->right == nullptr || p->right == last){
            s.pop();
            std::cout << p->data << std::endl;
            last = p;
            p = nullptr;
        }
        else {
            p = p->right;
        }
    }
}

int main() {
    TreeNode* T;
    std::cout << "创建二叉树，请输入字符，叶子树以#号代替" << std::endl;
    CreateBiTree(T);
    std::cout << "前序遍历：" << std::endl;
    PreOrder(T);
    std::cout << "中序遍历：" << std::endl;
    MidOrder(T);
    std::cout << "后序遍历：" << std::endl;
    PostOrder(T);
    return 0;
}