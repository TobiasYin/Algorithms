//
// Created by Tobias on 2019/2/3.
//

#ifndef ALGORITHMS_BINARYSEARCHTREE_H
#define ALGORITHMS_BINARYSEARCHTREE_H

#include<iostream>
#include <cassert>

using namespace std;

template<typename K, typename V>
class BinarySearchTree {
private:
    struct Node {
        K key;
        V value;
        Node *leftChild;
        Node *rightChild;

        Node(K key, V value) {
            this->key = key;
            this->value = value;
            rightChild = leftChild = NULL;
        }

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->rightChild = node->rightChild;
            this->leftChild = node->leftChild;
        }
    };

    Node *root;
    int count;

public:
    BinarySearchTree() {
        root = NULL;
        count = 0;
    }

    ~BinarySearchTree() {
        destroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(K key, V value) {
        root = insert(root, key, value);
    }

    V *search(K key) {
        Node *node = root;
        while (node != NULL) {
            if (node->key == key) {
                return &(node->value);
            }
            if (node->key > key) {
                node = node->leftChild;
            } else
                node = node->rightChild;
        }
        return NULL;
    }

    bool contain(K key) {
        V *v = search(key);
        return v != NULL;
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    K minimum() {
        assert(!isEmpty());
        Node *node = minimum(root);
        return node->key;
    }

    K maximum() {
        assert(!isEmpty());
        Node *node = maximum(root);
        return node->key;
    }

    K removeMin() {
        K min = minimum();
        root = removeMin(root);
        return min;
    }

    K removeMax() {
        K max = maximum();
        root = removeMax(root);
        return max;
    }

    void remove(K key) {
        root = remove(root, key);
    }


private:
    Node insert(Node *node, K key, V value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (node->key > key)
            node->leftChild = insert(node->leftChild, key, value);
        else if (node->key < key)
            node->rightChild = insert(node->rightChild, key, value);
        else node->value = value;
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->leftChild);
        cout << node->key << " : " << node->value << " , ";
        inOrder(node->rightChild);
    }

    void destroy(Node *node) {
        if (node == NULL)
            return;
        destroy(node->leftChild);
        destroy(node->rightChild);
        delete node;
        count--;
    }

    Node *minimum(Node *node) {
        if (node->leftChild == NULL)
            return node;
        return minimum(node->leftChild);
    }

    Node *maximum(Node *node) {
        if (node->rightChild == NULL)
            return node;
        return maximum(node->rightChild);
    }

    Node *removeMin(Node *node) {
        if (node->leftChild == NULL) {
            Node *temp = node->rightChild;
            delete node;
            count--;
            return temp;
        }
        node->leftChild = removeMin(node->rightChild);
        return node;
    }

    Node *removeMax(Node *node) {
        if (node->rightChild == NULL) {
            Node *temp = node->leftChild;
            delete node;
            count--;
            return temp;
        }
        node->rightChild = removeMin(node->rightChild);
        return node;
    }

    Node *remove(Node *node, K key) {
        if (node == NULL)
            return NULL;
        else if (node->key > key) {
            node->leftChild = remove(node->leftChild, key);
        } else if (node->key < key) {
            node->rightChild = remove(node->rightChild, key);
        } else {
            if (node->rightChild == NULL) {
                Node *temp = node->leftChild;
                delete node;
                count--;
                return temp;
            }
            if (node->leftChild == NULL) {
                Node *temp = node->rightChild;
                delete node;
                count--;
                return temp;
            }

            Node *min = new Node(minimum(node->rightChild));
            min->leftChild = node->leftChild;
            min->rightChild = removeMin(node->rightChild);
            delete node;
            return min;
        }
        return node;
    }
};

#endif //ALGORITHMS_BINARYSEARCHTREE_H
