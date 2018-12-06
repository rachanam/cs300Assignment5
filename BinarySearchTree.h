/*
 * Name: Rachana Mandal
 * Student id: 950699300 
 * BinarySearchTree: Modified to return item from search() instead of returning boolean
 * */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;
};

template <class T>
class BinarySearchTree
{

  public:
    BinarySearchTree();
    void printInOrder() { printInOrder(root); }
    void printPreOrder() { printPreOrder(root); }
    void printPostOrder() { printPostOrder(root); }
    int height() { return height(root); }
    void insert(T &item) { insert(root, item); }
    T search(T &item) { return search(root, item); }
    T findMax(T &e) { return findMax(root, e); }
    T findMin(T &e) { return findMin(root, e); }
    void deletenode(T &item) { deletenode(root, item); }
    ~BinarySearchTree() { destroy(root); }

  private:
    BSTNode<T> *root;
    void printInOrder(BSTNode<T> *);
    void printPreOrder(BSTNode<T> *);
    void printPostOrder(BSTNode<T> *);
    void destroy(BSTNode<T> *);
    int height(BSTNode<T> *);
    int max(int, int);
    void insert(BSTNode<T> *&, T &);
    T search(BSTNode<T> *, T &);
    T findMax(BSTNode<T> *, T &);
    T findMin(BSTNode<T> *, T &);
    void deletenode(BSTNode<T> *&, T &);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template <class T>
void BinarySearchTree<T>::printInOrder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        printInOrder(p->left);
        cout << p->data << " ";
        printInOrder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::printPreOrder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        printPreOrder(p->left);
        printPreOrder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::printPostOrder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        printPostOrder(p->left);
        printPostOrder(p->right);
        cout << p->data << " ";
    }
}
template <class T>
int BinarySearchTree<T>::max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

template <class T>
int BinarySearchTree<T>::height(BSTNode<T> *p)
{
    if (p != NULL)
    {
        return 1 + max(height(p->left), height(p->right));
    }
    return -1;
}

template <class T>
void BinarySearchTree<T>::destroy(BSTNode<T> *p)
{
    if (p != NULL)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = NULL;
    }
}

template <class T>
void BinarySearchTree<T>::insert(BSTNode<T> *&p, T &item)
{
    if (p == NULL)
    {
        p = new BSTNode<T>;
        p->data = item;
        p->left = p->right = NULL;
    }
    else if (item < p->data)
    {
        insert(p->left, item);
    }
    else
    {
        insert(p->right, item);
    }
}

template <class T>
T BinarySearchTree<T>::search(BSTNode<T> *p, T &item)
{
    if (p == NULL)
        return item;
    else if (item == p->data)
        return p->data;
    else if (item < p->data)
        return search(p->left, item);
    else
        return search(p->right, item);
}

template <class T>
T BinarySearchTree<T>::findMax(BSTNode<T> *p, T &e)
{
    if (p == NULL)
        return e;
    else if (p->right == NULL)
        return p->data;
    else
        return findMax(p->right, e);
}

template <class T>
T BinarySearchTree<T>::findMin(BSTNode<T> *p, T &e)
{
    if (p == NULL)
        return e;
    else if (p->left == NULL)
        return p->data;
    else
        return findMin(p->left, e);
}

template <class T>
void BinarySearchTree<T>::deletenode(BSTNode<T> *&p, T &item)
{
    //item not found, do nothing
    if (p == NULL)
        return;
    else if (item < p->data) //item is on the left subtree
        deletenode(p->left, item);
    else if (item > p->data) //item is on the right subtree
        deletenode(p->right, item);
    else
    { //item is equal to data,  it is found
        if (p->left != NULL && p->right != NULL)
        { // with two children
            int e = -1;
            p->data = findMax(p->left, e);
            deletenode(p->left, p->data);
        }
        else
        {
            BSTNode<T> *old = p;
            if (p->left != NULL)
                p = p->left;
            else
                p = p->right;

            delete old;
        }
    }
}

#endif /* BINARYSEARCHTREE_H_ */