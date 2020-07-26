#include <iostream>
#include <string.h>
#include "FamilyTree.hpp"
#include <string>
#define count 10
using namespace std;
using namespace family;

node::node(string name)
{
    this->data = name;
    this->left = NULL;
    this->right = NULL;
}

Tree::Tree(string name)
{
    node *n = new node(name);
    this->root = n;
}

bool Tree::addf(string name, node *n, string y)

{
    if (n != NULL)
    {
        if (n->data == name)
        {
            if (n->left != NULL)
                return false;

            node *nn = new node(y);
            n->left = nn;
            return true;
        }
        if (this->addf(name, n->left, y))
        {
            this->addf(name, n->left, y);
            return true;
        }

        return this->addf(name, n->right, y);
    }
    return false;
}

bool Tree::addm(string name, node *n, string y)

{
    if (n != NULL)
    {
        if (n->data == name)
        {
            if (n->right != NULL)
                return false;
            node *nn = new node(y);
            n->right = nn;
            return true;
        }
        // checks if true then do it
        if (this->addm(name, n->left, y))
        {
            this->addm(name, n->left, y);
            return true;
        }
        // check the right one
        return this->addm(name, n->right, y);
    }
    return false;
}

Tree& Tree::addFather(string x, string y)
{
    if (this->root == NULL)
        throw runtime_error("tree is empty");
    if (this->addf(x, this->root, y) == false)
        throw runtime_error("son name isnt contained in the tree or already has a father");
    this->addf(x, this->root, y);
    return *this;
}
Tree& Tree::addMother(string x, string y)
{
    if (this->root == NULL)
        throw runtime_error("tree is empty");
    if (this->addm(x, this->root, y) == false)
        throw runtime_error("son name isnt contained in the tree or already has a motehr");
    this->addm(x, this->root, y);
    return *this;
}

bool Tree::search(string name, node *n)
{
    if (n == NULL)
        return false;
    if (n->data == name)
        return true;
    if (search(name, n->left))
        return true;
    return search(name, n->right);
}

string Tree::relation(string name)
{
    if (this->root == NULL)
        throw runtime_error("tree is empty");
    if (this->root->data == name)
        return "me";

    if (this->root->left != NULL && this->root->left->data == name)
        return "father";

    if (this->root->right != NULL && this->root->right->data == name)
        return "mother";

    if (this->search(name, this->root->left))
        return this->relation(name, this->root->left);

    if (this->search(name, this->root->right))
        return this->relation(name, this->root->right);

    return "unrelated";
}

string Tree::relation(string name, node *n)
{
    if (n->left != NULL && n->left->data == name)
        return "grandfather";

    if (n->right != NULL && n->right->data == name)
        return "grandmother";

    if (this->search(name, n->left))
        return "great-" + relation(name, n->left);

    return "great-" + relation(name, n->right);
}

string Tree::find(string name)
{
    if (this->root == NULL)
        throw runtime_error("tree is empty");

    if (name == "mother")
    {
        if (this->root->right != NULL)
            return this->root->right->data;
        else
            throw runtime_error("no mother in the tree");
    }

    if (name == "father")
    {
        if (this->root->left != NULL)
            return this->root->left->data;
        else
            throw runtime_error("no left in the tree");
    }

    if (name == "me")
        return this->root->data;

    if (root->left != NULL && this->find(name, this->root->left, name) != "not found in the tree" && this->find(name, this->root->left, name) != " ")
        return this->find(name, this->root->left, name);
    if (root->right != NULL && this->find(name, this->root->right, name) != "not found in the tree" && this->find(name, this->root->right, name) != " ")

        return this->find(name, this->root->right, name);

    else
        throw runtime_error("relation not added to the tree");
}

string Tree::find(string name, node *n, string s)
{

    if (name == "grandfather")
    {
        if (n->left != NULL)
            return n->left->data;
        else
            return " ";
    }

    if (name == "grandmother")
    {
        if (n->right != NULL)
            return n->right->data;
        else
            return " ";
    }

    if (name.substr(0, 6) == "great-")
    {
        if (n->left != NULL && find(name.substr(6), n->left, s) != " ")
            return find(name.substr(6), n->left, s);

        if (n->right != NULL && find(name.substr(6), n->right, s) != " ")
            return find(name.substr(6), n->right, s);

        return "not found in the tree";
    }

    else
        throw runtime_error(" The tree cannot handle the " + s + "relation");
}

void Tree::remove(node *n)
{
    if (n == NULL)
        return;
    if (n->left == NULL && n->right == NULL)
    {
        delete (n);
        return;
    }
    remove(n->left);
    remove(n->right);
    delete (n);
}

bool Tree::searchremove(node *n, string name)
{
    if (n == NULL)
        return false;

    if (n->left != NULL && n->left->data == name)
    {
        remove(n->left);
        n->left = NULL;
        return true;

        return true;
    }
    if (n->right != NULL && n->right->data == name)
    {

        remove(n->right);
        n->right = NULL;

        return true;
    }

    if (search(name, n->left))
        return searchremove(n->left, name);
    else

        return searchremove(n->right, name);
}

void Tree::remove(string name)
{
    if (this->root->data == name)
        throw runtime_error("cannot remove root");

    if (name == this->root->data)
    {
        remove(this->root->left);
        remove(this->root->right);
        this->root = NULL;
        return;
    }

    if (searchremove(this->root, name) == false)
        throw runtime_error("name not found");
    searchremove(this->root, name);
}

void Tree::display1(node *curr, int spaces)
{
    if (curr != NULL)
    {
        //cout << "->" + curr->data;
        spaces += count;
        this->display1(curr->right, spaces);
        cout << endl;
        for (int i = 0; i < spaces; i++)
            cout << " ";
        cout << curr->data << endl;
        this->display1(curr->left, spaces);
    }
}
void Tree::display()
{
    int i = 0;
    display1(this->root, i);
}
