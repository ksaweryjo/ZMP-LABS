// Ksawery Józefowski nr 277513 zadanie 1

#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int var1): key(var1), left(nullptr), right(nullptr), height(1) {}
};

int Height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(Height(root -> left), Height(root -> right)) + 1;
}

bool searchTree(Node* root, int key) {
    if (root == nullptr) {
        return false;
    }
    else if (root->key == key) {
        return true;
    }
    return searchTree(root->left, key) || searchTree(root->right, key);
}

void countLnN(Node* root, int& leaves, int& Nodes) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        leaves++;
    }
    else {
        Nodes++;
    }
    countLnN(root->left, leaves, Nodes);
    countLnN(root->right, leaves, Nodes);
}

Node* mergeTrees(Node* root1, Node* root2, int var1) {
    Node* newRoot = new Node(var1);
    newRoot->left = root1;
    newRoot->right = root2;
    return newRoot;
}

int Balance(Node* N) {
    if (N == nullptr) {
        return 0;
    }
    return Height(N -> left) - Height(N -> right);
}

Node* rightRotate(Node* y) {
    Node* x = y -> left;
    Node* T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    y -> height = max(Height(y -> left), Height(y -> right)) + 1;
    x -> height = max(Height(x -> left), Height(x -> right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x -> right;
    Node* T2 = y -> left;
    y -> left = x;
    x -> right = T2;
    x -> height = max(Height(x -> left), Height(x -> right)) + 1;
    y -> height = max(Height(y -> left), Height(y -> right)) + 1;
    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return (new Node(key));
    }
    if (key < node -> key) {
        node->left = insert(node->left, key);
    }
    else if (key >= node -> key) { // Przyjmiemy że powtarzające się wartości będą w prawym poddrzewie
        node->right = insert(node->right, key);
    }

    node -> height = Height(node);
    int balanceFactor = Balance(node);
    if (balanceFactor > 1) {
        if (key < node -> left -> key) {
            return rightRotate(node);
        }
        else if (key > node -> left -> key) {
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1) {
        if (key > node -> right -> key) {
            return leftRotate(node);
        }
        else if (key < node -> right -> key) {
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }
    }
    return node;
}

void printTree(Node* root, string indent, bool last) {
    if (root != nullptr) {
        printf("%s", indent.c_str());
        if (last) {
            printf("L----");
            indent += "   ";
        }
        else {
            printf("R----");
            indent += "|  ";
        }
        printf("%d\n", root -> key);
        printTree(root -> left, indent, false);
        printTree(root -> right, indent, true);
    }
}

int main() {
    Node* root = nullptr;
    int n, s;
    printf("Podaj ilosc elementow: ");
    scanf("%d", &n);
    printf("Podaj wartosc do wyszukania: ");
    scanf("%d", &s);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Podaj element %d: ", n-i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    printf(searchTree(root, s) ? "\nZnaleziono %d\n" : "\nNie znaleziono %d\n");

    int leaves = 0;
    int nodes = 0;
    countLnN(root, leaves, nodes);
    printf("Liczba lisci: %d\n", leaves);
    printf("Liczba nodes: %d\n", nodes - 1); // Zakłądam że root i leaves nie są nodem

    int h = Height(root);
    printf("Wysokosc drzewa: %d\n", h);

    printTree(root, "", true);

    // TreeNode* mergedTree = mergeTrees(root1, root2, 10);
    return 0;
}