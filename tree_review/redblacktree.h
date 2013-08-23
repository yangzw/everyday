#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include <iostream>

using namespace std;

enum Color {black = 0,red};
enum Tags {left = 0,right};

template<class K,class T> class redblacktree;

template<class K,class T>
class node
{
    friend class redblacktree<K,T>;
private:
    K key;
    T data;
    Color color;
    node<K,T>* rightchild;
    node<K,T>* leftchild;
    node<K,T>* parent;

    node()
    {
        color = red;
        rightchild = leftchild = parent = NULL;
    }
    node(const T& data,const K& key)
    {
        this->data = data;
        this-key = key;
        this-color = color;
        rightchild = leftchild = parent = NULL;
    }

    node<K,T>& operator = (const node<K,T>& Node)
    {
        this->color = Node.color;
        this->rightchild = Node.rightchild;
        this->leftchild = Node.leftchild;
        this->parent = Node.parent;
        this->key = Node.key;
        this->data = Node.data;
    }
public:
    void visit(){};
};

template<class K,class T>
class redblacktree
{
public:
    redblacktree()
    {
        nill = new node<K,T>(black);
        nill->parent = nill;
        nill->leftchild = nill;
        nill->rightchild = nill;
        root = nill;
        size = 0;
    }
    ~redblacktree()
    {
        tree_destroy(root);
    }
    void clear();
    //递归前中序周游
    void pre_tree_walk();
    void mid_tree_walk();
    //非递归前中后序周游
    void pre_tree_walk2();
    void mid_tree_walk2();
    void post_tree_walk2();
    //层序周游
    void level_order_tree_walk();
    //返回子树中最大/小的节点
    node<K,T>* tree_max(node<K,T>* rt);
    node<K,t>* tree_min(node<K,t>* rt);
    //查找
    bool search(const K& srkey, T*& data) const;
    bool search(*const K& srkey) const;
    //删除和插入操作
    node<K,T>* RB_insert(const T&data, const K& insrtkey);
    bool RB_DELETE(const K& dkey);
    void RB_DELETE(node<K,T>* x);
    bool empty() const;
    bool getszie() const;
private:
    node<K,T>* root;
    node<K,T>* nill;
    int size;
    //递归前中序周游的递归部分
    void pre_tree_walk(node<K,T>* root);
    void mid_tree_walk(node<K,T>* root);
    void tree_destoy(node<K,T>* current);
    //求某一个节点的前驱和后继
    node<K,T>* tree_successor(node<K,T>* x);
    node<K,T>* rbsearch(const K& srkdy) const;
    //旋转节点
    void left_rotate(node<K,T>* x);
    void right_rotate(node<K,T>* x);
    //插入和删除以后的调整
    vod RB_insert_fixup(node<K,T>* x);
    void RB_DELETE_fixup(node<K,T>* x);
};

template<class K,class T>
void redblacktree<K,T>::clear()
{
    node<K,T>* current = root;
    tree_destoy(root);
    root = nill;
}

template<class K,class T>
void redblacktree<K,T>::tree_destroy(node<K,T>* current)
{
    if(current != nill)
    {
        tree_destoy(current->leftchild);
        tree_destoy(current->rightchild);
        delete current;
    }
}

template<class K,class T>
bool redblacktree<K,T>::empty() const
{
    return sieze == 0;
}

template<class K,class T>
int redblacktree<K,T>::get_size() const
{
    return size;
}

template<class K,class T>
bool redblacktree<K,T>::search(const K& srkey) const
{
    node<K,T> * x = rbsearch(srkey);
    if(x = nill)
        return false;
    else
        return true;
}

template<class K,class T>
bool redblacktree<K,T>::search(const K& srkey, T*& datapoint) const
{
    node<K,T>* x = rbsearch(srkey);
    if(x == nill)
    {
        datapoint = NULL;
        return false;
    }
    else
    {
        datapoint = &x->data;
        return true;
    }
}

template<class K,class T>
node<K,T>* redblacktree<K,T>::rbsearch(const K& srkey) const
{
    node<K,T>* x = root;
    while(x != nill && srkdy != x->key)
    {
        if(srkdy > x->key)
            x = x->rightchild;
        else
            x= x->leftchild;
    }
    return x;
}

template<class K,class T>
void redblacktree<K,T>::per_tree_walk()
{
    pre_tree_walk(root);
    cout << endl;
}

template<class K,class T>
void redblacktree<K,T>::mid_tree_walk()
{
    mid_tree_walk(root);
    cout << endl;
}

template<class K,class T>
void redblacktree<K,T>::pre_tree_walk(node<K,T>* root)
{
    if(root != nill)
    {
        root->visit();
        mid_tree_walk(root->leftchild);
        mid_tree_walk(root->rightchild);
    }
}
 template<class K,class T>
 void redblacktree<K,T>::mid_tree_walk(node<K,T>* root)
{
    if(root != nill)
    {
        pre_tree_walk(root->leftchild);
        root->visit();
        pre_tree_walk(root->rightchild);
    }
}

template<class K,class T>
void redblacktree<K,T>::pre_tree_walk2()
{
    using std::stack
    stack<node<K,T> *> astack;
    node<K,T>* point = root;
    while(!astack.empty() || point)
    {
        if(point)
        {
            point->visit();
            astack.push(point);
            point = point->leftchild;
        }
        else
        {
            point = astack.top();
            astack.pop();
            point = point->rightchild;
        }
    }
}

template<class K,class T>
void redblacktree<K,T>::mid_tree_walk2()
{
    using std::stack
    stack<node<K,T>* astack;
    node<K,T>* point = root;
    while(!astack.empty() || point)
    {
        astack.push(point);
        point = point->leftchild;
    }
    else
    {
        point = astack.top();
        point->visit();
        point = point->rightchild;
        satck.pop();
    }
}

template<class K,class T>
class stackElement
{
public:
    node<K,T>* point;
    Tags tag;
};

template<class K,class T>
void redblacktree<K,T>::post_tree_walk2()
{
    using std::stack;
    stackElement<K,T> element;
    stack<stackElement<K,T> > astack;
    node<K,T>* point = root;
    if(root == NULL)
        return;
    while(true)
    {
        while(point != NULL)
        {
            element.point = point;
            element.tag = left;
            astack.push(element);
            point = point->leftchild;
        }
        element = astack.top();
        astack.pop();
        point = element.point;
        while(element.tag == right)
        {
            point->visit();
            if(astack.empty())
                return;
            else
            {
                element = astack.top();
                astack.pop();
                point = element.point;
            }
        }
        element.tag = right;
        astack.push(element);
        point = point->rightchild;
    }
}

template<class K,class T>
void redblacktree<K,T>::level_order_tree_walk()
{
    using std::queue;
    queue<node<K,T>*> aqueue;
    node<K,T>* point = root;
    if(point)
        aqueue.push(point);
    while(!aqueue.empty())
    {
        point = queue.front();
        point->visit();
        aqueue.pop();
        if(point->leftchild)
            aqueue.push(point->leftchild);
        if(point->rightchild)
            aqueue->push(point->rightchild);
    }
}

template<class K,class T>
node<K,T>* redblacktree<K,T>::tree_successor(node<K,T>* x)
{
    if(x->rightchild != nill)
        return tree_min(x->rightchild);
    node<K,T>* y = x->parent;
    while(y != nill && x == y->rightchild)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template<class K,class T>
node<K,T>* redblacktree<K,T>::tree_predecessor(node<K,T>* x)
{
    if(x->leftchild != nill)
        return tree_max(x->leftchild);
    node<K,T>* y = x->parent;
    while(y != nill && x == y->leftchild)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

template<class K,class T>
void redblacktree<K,T>::left_rotate(node<K,T>* x)
{
    node<K,T>* y = x->rightchild;
    x->rightchild = y->leftchild;
    y->leftchild->parent = x;
    y->leftchild = x;
    y->parent = x->parent;
    if(x->parent == nill)
        root = y;
    else if(x == x->parent->leftchild)
         x->parent->leftchild = y;
    else
        x->parent->rightchild = y;
    x->parent = y;
    nill->parent = nill;
}

template<class K,class T>
void redblacktree<K,T>::right_rotate(node<K,T>* x)
{
    node<K,T>* y = x->leftchild;
    x->leftchild = y->rightchild;
    y->rightchild->parent = x;
    y->rightchild = x;
    y->parent = x->parent;
    if(x->parent == nill)
        root = y;
    else if(x == x->parent->leftchild)
        x->parent->leftchild = y;
    else
        x->parent->rightchild = y;
    x->parent = y;
    nill->parent = nill;
}

template<class K,class T>
node<K,T>* redblacktree<K,T>::RB_insert(const T& data,const K&insrtkey)
{
    node<K,T>* x = new node<K,T>(data,insrtkey,red);
    x->parent = x->rightchild = x->leftchild = nill;
    node<K,T>* current = root;
    node<K,T>* y = nill;
    while(current != nill)
    {
        y = current;
        if(insrtkey > current->key)
            current = current->rightchild;
        else
            current = current->leftchild;
    }
    x->parent = y;
    if(y == nill)
    {
        root = x;
        x->color = black;
    }
    else
    {
        if(x->key > y->key)
            y->rightchild = x;
        else
            y->leftchild = x;
    }
    RB_insert_fixup(x);
    ++ size;
    return x;
}

template<class K,class T>
void redblacktree<K,T>::RB_insert_fixup(node<K,T>* x)
{
    while(x != root && x->parent->color == red)
    {
        if(x->parent == x->parent->parent->leftchild)
        {
            node<K,T>* uncle = x->parent->parent->rightchild;
            if(uncle->color == red)
            {
                uncle->color = black;
                x->parent->color = black;
                x = x->parent->parent;
            }
            else
            {
                if(x == x->parent->rightchild)
                {
                    left_rotate(x->parent);
                    x = x->leftchild;
                }
                x->parent->color = black;
                x->parent->parent->color = red;
                right_rotate(x->parent->parent);
            }
        }
        else
        {
            node<K,T>* uncle = x->parent->parent->leftchild;
            if(uncle->color == red)
            {
                uncle->color = black;
                x->parent->color = black;
                x = x->parent->parent;
            }
            else
            {
                if(x == x->parent->leftchild)
                {
                    right_rotate(x->parent);
                    x = x->rightchild;
                }
                x->parent->color = black;
                x->parent->parent->color = red;
                left_rotate(x->parent->parent);
            }
        }
    }
}

template<class K,class T>
bool redblacktree<K,T>::RB_DELETE(const K& dkey)
{
    node<K,T>* x = rbsearch(dkey);
    if(x == nill)
    {
        cout << "can't find the key to be deleted" << endl;
        return false;
    }
    else
    {
        RB_DELETE(x);
        size --;
    }
    return true;
}

template<class K,class T>
void redblacktree<K,T>::RB_DELETE(node<K,T>* x)
{
    node<K,T>* z = NULL;
    if(x->rightchild == nill || x->leftchild == nill)
        z = x;
    else
        z = tree_successor(x);
    node<K,T>* y = NULL;
    if(z->leftchild != nill)
        y = z->leftchild;
    else
        y = z->rightchild;
    y->parent = z->parent;
    if(z->parent == nill)
        root = y;
    else if(z == z->parent->leftchild)
        z->parent->leftchild  = y;
    else
        z->parent->rightchild = y;
    if(x != z)
    {
        x->key = z->key;
        x->data = z->data;
    }
    if(z->color == black)
        RB_DELETE_fixup(y);
    delete z;
    nill->parent = nill;
}

template<class K,class T>
void redblacktree<K,T>::RB_DELETE_fixup(node<k,T>* x)
{
    while(x != root && x->color == black)
    {
        node<K,T>* w = NULL;
        if(x == x->parent->leftchild)
        {
            w = x->parent->rightchild;
            if(w->color == red)
            {
                w->color = black;
                w->parent->color = red;
                left_rotate(w->parent);
                w = x->parent->rightchild;
            }
            if(w->color == black)
            {
                if(w->leftchild->color == black && w->rightchild->color == black)
                {
                    if(x->parent->color == red)
                    {
                        w->color == red;
                        x = root;
                    }
                    else
                    {
                        w->color = red;
                        x = x->parent;
                    }
                }
                else if(w->leftchild == red && w->rightchild->color == black)
                {
                    w->color = red;
                    w->leftchild->color = black;
                    right_rotate(w);
                    w = w->parent;
                }
                if(w->rightchild->color == red)
                {
                    w->color = w->parent->color;
                    w->parent->color = black;
                    w->rightchild->color = black;
                    left_rotate(w->parent);
                    x = root;
                }
            }
        }
        else
        {
            w = x->parent->leftchild;
            if(w->color == red)
            {
                w->color = black;
                w->parent->color = red;
                right_rotate(w->parent);
                w = x->parent->leftchild;
            }
            if(w->color == black)
            {
                if(w->rightchild->color == black && w->leftchild->color == black)
                {
                    if(x->parent->color == red)
                    {
                        w->color == red;
                        x = root;
                    }
                    else
                    {
                        w->color = red;
                        x = x->parent;
                    }
                }
                else if(w->rightchild == red && w->leftchild->color == black)
                {
                    w->color = red;
                    w->rightchild->color = black;
                    left_rotate(w);
                    w = w->parent;
                }
                if(w->leftchild->color == red)
                {
                    w->color = w->parent->color;
                    w->parent->color = black;
                    w->leftchild->color = black;
                    right_rotate(w->parent);
                    x = root;
                }
            }
        }
    }
    x->color = black;
    nill->color = black;
}

#endif // REDBLACKTREE_H_INCLUDED
