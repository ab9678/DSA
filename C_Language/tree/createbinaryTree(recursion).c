// create a binary tree 

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
    int data;
    struct node* rightChild;
    struct node* leftChild;
}node;
int i=0;
int size;
void display(node* root);
node* createTree();
node* createnode(int data);
node* createRoot();
node* createnode(int data){
    node* newnode = NULL;

    newnode = (node*)malloc(sizeof(node));
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;
    newnode->data = data;
    return newnode;
}

node* createRoot(){
    printf("Enter size : ");
    scanf("%d",&size);

    node* head = createTree();
    display(head);
}

node* createTree(){
    
    if (i>=size){
        return NULL;
    }
    
    
    int d;
    printf("Enter data: ");
    scanf("%d",&d);

    node* head = createnode(d);
    i++;



    // recursively call the function now this will create nodes, at left, ask for data, etc and do the same in rigth at the same time ut seperately
    if (i<size){
    head->leftChild = createTree();
    }     // since I call left first it will always call left until null is returned but null come when the size is exhausted so we can do is, create both of them seperately until nul comes for each of them
    
    if (i<size){
    head->rightChild = createTree();
    }
    
    

    return head;

}

// void display(node* root){
//     if (root == NULL){
//         printf("No child");
//         return;
//     }
    
//     display(root->leftChild);
//     printf("%d",root->data);
//     display(root->rightChild);

//     printf("\t\t");
// }
// Function to display the binary tree with parent-child relationships
void display(node* root) {
    if (root == NULL) {
        return; // Base case: stop if the node is NULL
    }

    // Print the current node and its left and right children (if they exist)
    printf("Node %d: ", root->data);

    if (root->leftChild != NULL) {
        printf("Left Child = %d, ", root->leftChild->data);
    } else {
        printf("Left Child = NULL, ");
    }

    if (root->rightChild != NULL) {
        printf("Right Child = %d\n", root->rightChild->data);
    } else {
        printf("Right Child = NULL\n");
    }

    // Recursively display the left and right children
    display(root->leftChild);
    display(root->rightChild);
}


int main(){
    createRoot();

}