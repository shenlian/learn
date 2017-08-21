#include<iostream>
#include<stdio.h>
#include<exception>
#include<stack>
using namespace std;

//定义结构体
typedef struct TreeNode{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(char x):
        val(x), left(NULL),right(NULL){}
}Node;


Node* ConstructCore(char* startPreorder, char* endPreorder, char* startInorder, char* endInorder);

Node* Construct(char* preorder, char* inorder, int length){
    if(preorder == NULL || inorder == NULL || length <= 0) return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

Node* ConstructCore(char* startPreorder, char* endPreorder, char* startInorder, char* endInorder){
    char rootValue = startPreorder[0];
    Node* root = new Node(rootValue);

    if(startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder){
            return root;
        }
    }
    
    char* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue) ++rootInorder;

    int leftLength = rootInorder - startInorder;
    char* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0){
        root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder){
        root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}

Node* buildBstreeByPre(){
    int num;
    cin>>num;
    char pre[num],mid[num];
    for(int i = 0; i < num ; i++){
        cin>>pre[i];
    }
    for(int i = 0; i < num ; i++){
        cin>>mid[i];
    }
    return Construct(pre, mid, num);    
}

void reverseBstreePre(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->val<<endl;
    reverseBstreePre(root->left);
    reverseBstreePre(root->right);
}

void noReverseBstreePre(Node* root){
    int num = 0;
    cout<<root->val<<endl;
    num++;
    stack<Node*> b_stk;
    b_stk.push(root);
    while(!b_stk.empty()){
        Node* top = b_stk.top();
        cout<<"top "<<top->val<<endl;
        if(num > 6) break;
        if(top->left != NULL){
            cout<<top->left->val<<endl;
            num++;
            b_stk.push(top->left);
            continue;
        }
        b_stk.pop();
        if(top->right != NULL){
            num++;
            cout<<top->right->val<<endl;
            b_stk.push(top->right);
            continue;
        }
    }
}
int main(){
    Node* bstress = buildBstreeByPre();
    noReverseBstreePre(bstress);
    return 0;
}
