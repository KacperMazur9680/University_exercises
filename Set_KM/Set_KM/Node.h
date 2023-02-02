#pragma once
using namespace std;

template <typename T>
struct Node {
    T data;

    Node* left = nullptr;

    Node* right = nullptr;

public:

    // Destruktor 
    ~Node()
    {
        delete left;
        delete right;
    }

    // Pokazanie wartoœci po kolei
    void inorder(Node* r)
    {
        if (r == nullptr) {
            return;
        }
        inorder(r->left);
        std::cout << r->data << " ";
        inorder(r->right);
    }

    // Sprawdzanie czy drzewo posiada node'a z podan¹ wartoœci¹
    int containsNode(Node* r, T d)
    {
        if (r == NULL) {
            return 0;
        }
        int x = r->data == d ? 1 : 0;
        return x | containsNode(r->left, d) | containsNode(r->right, d);
    }

    // Dodawanie node'a z wartoœci¹ do drzewa
    Node* insert(Node* r, T d)
    {
        // Dodanie node'a jeœli NULL
        if (r == NULL) {
            Node<T>* tmp = new Node<T>;
            tmp->data = d;
            tmp->left = tmp->right = NULL;
            return tmp;
        }

        // Przejœcie do lewego poddrzewa jeœli wartoœæ mniejsza od aktualnej
        if (d < r->data) {
            r->left = insert(r->left, d);
            return r;
        }

        // Przejœcie do prawego poddrzewa jeœli wartoœæ wiêksza od aktualnej
        else if (d > r->data) {
            r->right = insert(r->right, d);
            return r;
        }
        else
            return r;
    }
};