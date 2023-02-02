#pragma once
#include "Node.h"
#include <stack>

template <typename T>
class Set {

    // Pocz�tek drzewa poszukiwa�
    Node<T>* root;

    int size;

public:
    // Konstruktor domy�lny
    Set()
    {
        root = NULL;
        size = 0;
    }

    // Konstruktor kopiuj�cy
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

            // Do�o�enie wska�nik�w do stos�w je�li by�y po prawej lub lewej
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }

    }

    // Konstruktor przenosz�cy
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

    // ��czenie dw�ch zbior�w
    Set unionSet(Set& s)
    {
        Set<T> res;

        // Tylko drugi je�li brak pierwszego
        if (root == NULL)
            return s;

        // Tylko pierwszy je�li brak drugiego
        if (s.root == NULL)
            return *this;

        // Dodawanie warto�ci pierszego zbioru do zbioru 'res'
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

        // Dodawanie warto�ci drugiego zbioru do zbioru 'res'
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

    // Cz�� wsp�na dw�ch zbior�w
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

    // R�nica zbior�w
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

    // R�wno�� zbior�w
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

    // Sprawdzenie czy zbi�r zawiera dan� warto�� 
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

    // Zwr�cenie wielko�ci zbioru
    int getSize()
    {
        return size;
    }

};