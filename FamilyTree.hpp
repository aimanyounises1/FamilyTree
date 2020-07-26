#pragma once
#include <iostream>
#include <string.h>
using namespace std;
namespace family
{
    class node
    {
    public:
        string data;
        node *left;
        node *right;
        node(string);
    };
    class Tree
    {
    public:
        node *root;
        Tree &addFather(string, string);
        Tree &addMother(string, string);
        Tree(string);
        string find(string);
        string relation(string);
        bool search(string, node *);
        string relation(string, node *);
        void display();
        void remove(string);
        bool addf(string, node *, string);
        bool addm(string, node *, string);
        string find(string, node *, string);
        bool searchremove(node *, string);
        void remove(node *n);
        void display1(node *, int);
    };
} // namespace family