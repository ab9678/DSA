# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node *right, *left;
}node;

node* createroot(int data){
    node* root = NULL;
    root = (node* )malloc(sizeof(node));

    root->right = NULL;
    root->left = NULL;
    root->data = data;
    return root;  
}

node* createnode(int data){
    node* newnode = NULL;
    newnode = (node* )malloc(sizeof(node));

    newnode->right = NULL;
    newnode->left = NULL;
    newnode ->data = data;
    return newnode;
}


int main(){
    node* root = createroot(5);
    root->right = createnode(6);
    root->left = createnode(4);
    root->left->left = createnode(3);
    root->left->right = NULL;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");


}


void preorder (node* root){
    if (root == NULL){
        return;
    }

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder (node* root){
    if (root == NULL){
        return;
    }
    preorder(root->left);
    printf("%d\t",root->data);
    
    preorder(root->right);
}
void postorder (node* root){
    if (root == NULL){
        return;
    }

    
    preorder(root->left);
    preorder(root->right);    
    printf("%d\t",root->data);

}