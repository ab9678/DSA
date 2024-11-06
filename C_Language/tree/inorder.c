// code to implement inorder traversal in binary tree

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node *right, *left;
}node;

node* createnode(int data){
    node* newnode = malloc(sizeof(node));
    newnode -> left = newnode -> right = NULL;
    newnode -> data = data;
    return newnode;
}

void inorder (node* root){
    if(root == NULL){
        return;
    }else{
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}


int main(){
    node* root = createnode(9);
    root->left = createnode(5);
    root->right = createnode(10);
    root->left->left = createnode(4);
    root->left->left->left = createnode(3);
    root->left->right = createnode(6);
    root->right->left = createnode(11);

    inorder(root);
    printf("\n");
}