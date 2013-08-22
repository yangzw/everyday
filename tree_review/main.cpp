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
    void pre_tree_walk();
    void mid_tree_walk();
    void pre_tree_walk2();
    void mid_tree_walk2();
    void post_tree_walk2();
    node<K,T>* tree_max(node<K,T>* rt);
    node<K,t>* tree_min(node<K,t>* rt);
    bool search(const K& srkey, T*& data) const;
    bool search(*const K& srkey) const;
    node<K,T>* RB_insert(const T&data, const K& insrtkey);
    bool RB_DELETE(const K& dkey);
    void RB_DELETE(node<K,T>* x);
    bool empty() const;
    bool getszie() const;
private:
    node<K,T>* root;
    node<K,T>* nill;
    int size;
    void pre_tree_walk(node<K,T>* root);
    void mid_tree_walk(node<K,T>* root);
    void post_tree_walk(node<K,T>* root);
    void tree_destoy(node<K,T>* current);
    node<K,T>* tree_successor(node<K,T>* x);
    node<K,T>* rbsearch(const K& srkdy) const;
    void left_rotate(node<K,T>* x);
    void right_rotate(node<K,T>* x);
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


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
