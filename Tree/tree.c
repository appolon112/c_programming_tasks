#include <stdio.h>
#include <stdlib.h>

typedef int ContentType;

typedef enum { LEFT, RIGHT } Direction;

typedef struct TreeNode {
    ContentType data;  
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_node(ContentType content) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = content;
    newNode->left = newNode->right = NULL;
    return newNode;
   
}


size_t tree_size(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    size_t leftHeight = tree_size(root->left);
    size_t rightHeight = tree_size(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    //if- else 
}


void destroy_node(TreeNode* node) {
    if (node != NULL) {
        destroy_node(node->left);
        destroy_node(node->right);
        free(node);
    }
}



TreeNode* insert_node_raw(TreeNode* root, ContentType content, Direction direction) {
    if (root == NULL) {
        return create_node(content);
    }
    if (direction == LEFT) {
        root->left = insert_node_raw(root->left, content, direction);
    } else {
        root->right = insert_node_raw(root->right, content, direction);
    }
    return root;
}


TreeNode* insert_node(TreeNode* root, ContentType content) {
    if (root == NULL) {
        return create_node(content);
    }
    if (content < root->data) {
        root->left = insert_node(root->left, content);
    } else {
        root->right = insert_node(root->right, content);
    }
    return root;
}


TreeNode* find_node(TreeNode* root, ContentType data) {
    if (root == NULL) {
        return 0;
    }
    if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return find_node(root->left, data);
    } else {
        return find_node(root->right, data);
    }
}


int main() {
    // Примеры использования функций
    TreeNode* root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 3);
    root = insert_node(root, 7);
  

    printf("Размер дерева: %lu\n", tree_size(root));

    TreeNode* found = find_node(root, 7);
    if (found != NULL) {
        printf("Найден узел с данными: %d\n", found->data);
    }

    destroy_node(root);
    return 0;
}
