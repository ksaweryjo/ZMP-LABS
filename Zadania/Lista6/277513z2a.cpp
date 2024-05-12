// Ksawery Józefowski nr 277513 zadanie 2a

#include <iostream>
#include <cstdio>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int var1) : key(var1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int var1) {
        if (node == nullptr) {
            return new Node(var1);
        }

        if (var1 <= node->key) {
            node->left = insert(node->left, var1);
        } else {
            node->right = insert(node->right, var1);
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

    void sort() {
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
    bst.sort();

    return 0;
}
