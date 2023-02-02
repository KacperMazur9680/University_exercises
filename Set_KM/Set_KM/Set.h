#pragma once
#include "Node.h"
#include <stack>

template <typename T>
class Set {

    // Pocz¹tek drzewa poszukiwañ
    Node<T>* root;

    int size;

public:
    // Konstruktor domyœlny
    Set()
    {
        root = NULL;
        size = 0;
    }

    // Konstruktor kopiuj¹cy
    Set(const Set& s)
    {
        size = s.size;
        stack<Node<T>*> nodeStack;
        nodeStack.push(s.root);

        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();

            add(node->data);

            // Do³o¿enie wskaŸników do stosów jeœli by³y po prawej lub lewej
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }

    }

    // Konstruktor przenosz¹cy
    Set(Set&& s) {
        if (*this == s) return;
        root = s.root;
        size = s.size;
        s.root = nullptr;
    }

     //Destruktor
    ~Set() 
    {
        delete root;
    }

    // Dodawanie do zbioru
    void add(const T data)
    {
        if (!root->containsNode(root, data)) {
            root = root->insert(root, data);
            size++;
        }
    }

    // £¹czenie dwóch zbiorów
    Set unionSet(Set& s)
    {
        Set<T> res;

        // Tylko drugi jeœli brak pierwszego
        if (root == NULL)
            return s;

        // Tylko pierwszy jeœli brak drugiego
        if (s.root == NULL)
            return *this;

        // Dodawanie wartoœci pierszego zbioru do zbioru 'res'
        stack<Node<T>*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();

            res.add(node->data);

            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }

        // Dodawanie wartoœci drugiego zbioru do zbioru 'res'
        stack<Node<T>*> nodeStack1;
        nodeStack1.push(s.root);

        while (!nodeStack1.empty()) {
            Node<T>* node;
            node = nodeStack1.top();
            nodeStack1.pop();

            res.add(node->data);

            if (node->right)
                nodeStack1.push(node->right);
            if (node->left)
                nodeStack1.push(node->left);
        }

        return res;
    }

    // Czêœæ wspó³na dwóch zbiorów
    Set intersectionSet(Set& s)
    {
        Set<T> res;
        stack<Node<T>*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return res;
    }

    // Ró¿nica zbiorów
    Set operator-(Set& s)
    {
        Set<T> res;
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);

        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node->data)) {
                res.add(node->data);
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return res;
    }

    // Równoœæ zbiorów
    bool operator==(Set& s)
    {
        if (s.getSize() != size) {
            return false;
        }
        stack<Node<T>*> nodeStack;
        nodeStack.push(this->root);

        while (!nodeStack.empty()) {
            Node<T>* node;
            node = nodeStack.top();
            nodeStack.pop();
            if (!s.contains(node->data)) {
                return false;
            }
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return true;
    }

    // Sprawdzenie czy zbiór zawiera dan¹ wartoœæ 
    bool contains(T data)
    {
        return root->containsNode(root, data) ? true : false;
    }

    // Pokazanie zbioru
    void displaySet()
    {
        std::cout << "{ ";
        root->inorder(root);
        std::cout << "}" << endl;
    }

    // Zwrócenie wielkoœci zbioru
    int getSize()
    {
        return size;
    }

};