// Ksawery Józefowski nr 277513 zadanie 2

#include <cstdio>
#include <vector>
#include <queue>
#include <stdexcept>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int var1) : key(var1), left(nullptr), right(nullptr) {}
};

class BST {
private:
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
    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    Node* negateTree(Node* node) const {
        if (!node) {
            return nullptr;
        }
        Node* newNode = new Node(-node->key);
        newNode->left = negateTree(node->left);
        newNode->right = negateTree(node->right);
        return newNode;
    }

    Node* addTrees(Node* node1, Node* node2) const {
        if(!node1 && !node2) {
            return nullptr;
        }
        int newKey = (node1 ? node1->key : 0) + (node2 ? node2->key : 0);
        Node* newNode = new Node(newKey);
        newNode->left = addTrees(node1 ? node1->left : nullptr, node2 ? node2->left : nullptr);
        newNode->right = addTrees(node1 ? node1->right : nullptr, node2 ? node2->right : nullptr);
        return newNode;
    }

    Node* subtractTrees(Node* node1, Node* node2) const {
        if (!node1 && !node2) {
            return nullptr;
        }
        int newKey = (node1 ? node1->key : 0) - (node2 ? node2->key : 0);
        Node* newNode = new Node(newKey);
        newNode->left = subtractTrees(node1 ? node1->left : nullptr, node2 ? node2->left : nullptr);
        newNode->right = subtractTrees(node1 ? node1->right : nullptr, node2 ? node2->right : nullptr);
        return newNode;
    }

    Node* findNode(Node* node, size_t index) const {
        if (!node) {
            return nullptr;
        }
        std::vector<Node*> nodes;
        nodes.push_back(node);
        size_t currentIndex = 0;

        while (currentIndex < nodes.size()) {
            Node* current = nodes[currentIndex];
            if (currentIndex == index) {
                return current;
            }
            if (current->left) {
                nodes.push_back(current->left);
            }
            if (current->right) {
                nodes.push_back(current->right);
            }
            currentIndex++;
        }
        return nullptr;
    }

    void inOrderTraversal(Node* node) const {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            printf("%d ", node->key);
            inOrderTraversal(node->right);
        }
    }

public:
    Node* root;
    BST() : root(nullptr) {}
    
    BST(const std::vector<int>& keys) : root(nullptr) {
        for (int key : keys) {
            root = insert(root, key);
        }
    }

    ~BST() {
        destroyTree(root);
    }

    BST operator-() const {
        BST result;
        result.root = negateTree(root);
        return result;
    }

    BST operator+(const BST& other) const {
        BST result;
        result.root = addTrees(root, other.root);
        return result;
    }

    BST operator-(const BST& other) const {
        BST result;
        result.root = subtractTrees(root, other.root);
        return result;
    }

    int operator[](size_t index) const {
        Node* node = findNode(root, index);
        if (node) {
            return node->key;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void sort() const {
        inOrderTraversal(root);
        printf("\n");
    }
};

int main() {
    int n, k;
    printf("Podaj ilosc elementow w drzewie t1 oraz t2: ");
    scanf("%d %d", &n, &k);
    std::vector<int> values1(n);
    std::vector<int> values2(k);

    for (int i = 0; i < n; i++) {
        printf("Podaj %d element drzewa t1: ", i + 1);
        scanf("%d", &values1[i]);
    }
    for (int i = 0; i < k; i++) {
        printf("Podaj %d element drzewa t2: ", i + 1);
        scanf("%d", &values2[i]);
    }

    BST t1(values1);
    BST t2(values2);

    // In-order printing
    printf("Drzewo t1: ");
    t1.sort();

    printf("Drzewo t2: ");
    t2.sort();

    BST t1_neg = -t1;
    printf("Drzewo -t1: ");
    t1_neg.sort();

    BST t1_plus_t2= t1+ t2;
    printf("Drzewo t1 + t2: ");
    t1_plus_t2.sort();

    BST t2_minus_t1= t2- t1;
    printf("Drzewo t2 - t1: ");
    t2_minus_t1.sort();

    printf("Drzewo t1[]: ");
    for (size_t i = 0; i < n; i++) {
        try {
            printf("%d ", t1[i]);
        } catch (const std::out_of_range&) {
            break;
        }
    }

    return 0;
}
