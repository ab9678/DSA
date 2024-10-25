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
}