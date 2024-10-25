# include <stdio.h>
# include <stdlib.h>


typedef struct tree{
    int data;
    struct tree* rightChild;
    struct tree* leftChild;
}tree;

typedef struct queue{
    tree* data;
    struct queue* next;
}queue;

queue* front = NULL;
queue* rear = NULL;

tree* parentnode = NULL;
void enqueue(tree* parent){
    queue* newnode = NULL;

    newnode = (queue*)malloc(sizeof(queue));
    newnode->data = parent;
    newnode->next = NULL;
    if (rear == NULL){
        front=rear=newnode;
    }else{
        rear->next = newnode;
        rear=newnode;
    }

}
void dequeue(){
    queue* temp = NULL;

    temp = front;
    if (front == NULL){
        printf("\nEmpty queue");
    }else{
        // printf("\n%d\n",front->data);
        front = front->next;
        free(temp);
    }
}

tree* createnode(int data){
    tree* newtree = malloc(sizeof(tree));

    newtree->data = data;
    newtree->leftChild = NULL;
    newtree->rightChild = NULL;

    return newtree;
}

tree* createTree(){
    tree* root = NULL;

    int data;
    char choice;
    char insideChoice;
    int size;
    
    if (root == NULL){
        printf("Enter root data: ");
        scanf("%d",&data);
        root = createnode(data);    // this is the real root node, notice this is the first element in the tree

        enqueue(root);

    }
    char ask = 'y';
    while(ask == 'y'){
        parentnode = front->data;
        printf("Do you want children nodes?(y/n) of %d: ",parentnode->data);
        scanf(" %c",&choice);
        int i=0;
        if (choice == 'y'){
            
            while(i!=2){
                printf("R/L: ");
                scanf(" %c",&insideChoice);
                if (insideChoice == 'r' && parentnode->rightChild == NULL){
                    printf("Enter right data: ");
                    scanf("%d",&data);
                    parentnode->rightChild = createnode(data);
                    enqueue(parentnode->rightChild);
                    i++;
                }else if (insideChoice == 'l' && parentnode->leftChild == NULL){
                    printf("Enter left data: ");
                    scanf("%d",&data);
                    parentnode->leftChild = createnode(data);
                    enqueue(parentnode->leftChild);
                    i++;
                }else{
                    printf("\nSelected position is already filled, try again\n");
                }
            }
            dequeue();  // remove the current parent, so as to move to the next parent
        }else{
            dequeue();
        }

        printf("Continue?(y/n): ");
        scanf(" %c",&ask);
    }

    return root;
}
void preorderTraversal(tree* root) {
    if (root == NULL) {
        return;
    }

    // First, print the data of the node (visit the node)
    printf("%d ", root->data);

    // Then recursively call the function on the left subtree
    preorderTraversal(root->leftChild);

    // Finally, recursively call the function on the right subtree
    preorderTraversal(root->rightChild);
}

int main(){
    printf("\n Lets create a tree\n\n");
    tree* root = createTree();
    preorderTraversal(root);
}