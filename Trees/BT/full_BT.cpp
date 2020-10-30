

#include <iostream>

using namespace std;

class BinaryTree
{
    public:
        struct BinaryTreeNode
        {
            int data;
            BinaryTreeNode * left;
            BinaryTreeNode * right;
            BinaryTreeNode * parent;
        };
        BinaryTreeNode * root;
        int left_height, right_height, level;
        BinaryTree()
        {
            root=NULL;
            left_height=right_height=0;
        }
        void insert_item(int item);
        
        BinaryTreeNode * find_place(BinaryTreeNode* current)
        {
            if(current->left ==NULL || current->right==NULL)
                return current;
            if(current->left !=NULL)
                current=current->left;
            else if(current->right !=NULL)
                current=current->right;
            
            find_place(current);
        }
        
        void add(BinaryTreeNode * new_node, BinaryTreeNode* parent, bool is_left_child)
        {
            new_node->parent=parent;
            if(is_left_child) { parent->left = new_node; cout<<"left ";}
            else {parent->right = new_node; cout<<"right ";}
            new_node->right=new_node->left = NULL;
            cout<<"("<<parent->data<<", "<<new_node->data<<")\n";
        }
    
};



void BinaryTree::insert_item(int item)
{
    BinaryTreeNode *btn = new BinaryTreeNode; 
    //if(btn==NULL) cout<<"NULL";
    btn->data=item;
    if(root==NULL)
    {
        root=btn;
        cout<<"Root \n";
        btn->left=NULL;
        btn->right=NULL;
        btn->parent = NULL;
    }
    else
    {
        BinaryTreeNode * current = root;
        BinaryTreeNode *pos=NULL;
        bool left_tree = false;

        pos = find_place(current);
        add(btn,pos,!pos->left);
    }
}

int main()
{
    BinaryTree bt;
    bt.insert_item(1);
    bt.insert_item(2);
    bt.insert_item(3);
    bt.insert_item(4);
    bt.insert_item(5);
    bt.insert_item(6);
    bt.insert_item(7);
    bt.insert_item(8);
    bt.insert_item(9);


    return 0;
}

