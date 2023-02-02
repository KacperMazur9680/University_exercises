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

    // Pokazanie warto�ci po kolei
    void inorder(Node* r)
    {
        if (r == nullptr) {
            return;
        }
        inorder(r->left);
        std::cout << r->data << " ";
        inorder(r->right);
    }

    // Sprawdzanie czy drzewo posiada node'a z podan� warto�ci�
    int containsNode(Node* r, T d)
    {
        if (r == NULL) {
            return 0;
        }
        int x = r->data == d ? 1 : 0;
        return x | containsNode(r->left, d) | containsNode(r->right, d);
    }

    // Dodawanie node'a z warto�ci� do drzewa
    Node* insert(Node* r, T d)
    {
        // Dodanie node'a je�li NULL
        if (r == NULL) {
            Node<T>* tmp = new Node<T>;
            tmp->data = d;
            tmp->left = tmp->right = NULL;
            return tmp;
        }

        // Przej�cie do lewego poddrzewa je�li warto�� mniejsza od aktualnej
        if (d < r->data) {
            r->left = insert(r->left, d);
            return r;
        }

        // Przej�cie do prawego poddrzewa je�li warto�� wi�ksza od aktualnej
        else if (d > r->data) {
            r->right = insert(r->right, d);
            return r;
        }
        else
            return r;
    }
};