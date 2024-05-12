// Ksawery Józefowski nr 277513 zadanie 2b

#include <iostream>
#include <cstdio>
#include <algorithm>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int var1) : key(var1), left(nullptr), right(nullptr), height(1) {}
};

class BST {
private:
    Node* root;

    int Height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return std::max(Height(node->left), Height(node->right)) + 1;
    }

    int Balance(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return Height(node->left) - Height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = Height(y);
        x->height = Height(x);
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = Height(x);
        y->height = Height(y);
        return y;
    }

    Node* insert(Node* node, int var1) {
        if (node == nullptr) {
            return new Node(var1);
        }

        if (var1 < node->key) {
            node->left = insert(node->left, var1);
        } else if (var1 > node->key) {
            node->right = insert(node->right, var1);
        } else if (var1 >= node->key) { // Przyjmiemy że powtarzające się wartości będą w prawym poddrzewie
            node->right = insert(node->right, var1);
        }
        
        node->height = 1 + std::max(Height(node->left), Height(node->right));
        
        int balance = Balance(node);

        if (balance > 1 && var1 < node->left->key)
            return rightRotate(node);
        
        if (balance < -1 && var1 > node->right->key)
            return leftRotate(node);
        
        if (balance > 1 && var1 > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        if (balance < -1 && var1 < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Odczytywanie drzewa w sposób in-order zwraca posortowane liczby dla BST
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            printf("%d ", node->key);
            inOrderTraversal(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int var1) {
        root = insert(root, var1);
    }

    void sortAndPrint() {
        inOrderTraversal(root);
        printf("\n");
    }
};

int main() {
    int n;
    printf("Podaj ilosc liczb: ");
    scanf_s("%d", &n);

    BST bst;

    for (int i = 0; i < n; ++i) {
        int num;
        printf("Podaj liczbe %d: ", i + 1);
        scanf_s("%d", &num);
        bst.insert(num);
    }

    printf("Posortowane: \n");
    bst.sortAndPrint();

    return 0;
}
