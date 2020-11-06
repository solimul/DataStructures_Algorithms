

#include <iostream>

using namespace std;

class BinarySearchTree
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
        BinarySearchTree()
        {
            root=NULL;
            left_height=right_height=0;
        }
        
        BinaryTreeNode * find_place(BinaryTreeNode* current, int item)
        {
            if(current->data>=item)
            {
                if(current->left!=NULL)
                    current=current->left;
                else 
                    return current;
            }
            if(current->data<item)
            {
                if(current->right!=NULL)
                    current=current->right;
                else 
                    return current;
            }
            find_place(current,item);
        }
        
        void add(BinaryTreeNode * new_node, BinaryTreeNode* parent, bool is_left_child)
        {
            new_node->parent=parent;
            if(is_left_child) { parent->left = new_node; cout<<"left ";}
            else {parent->right = new_node; cout<<"right ";}
            new_node->right=new_node->left = NULL;
            cout<<"("<<parent->data<<", "<<new_node->data<<")\n";
        }
        
        BinaryTreeNode * find_item(BinaryTreeNode *current, int item)
        {
            if(current == NULL) 
                return NULL;
            if(current->data==item)
                return current;
            if(current->data>=item)
                find_item(current->left,item);
            else 
                find_item(current->right,item);
        }
        
        void insert_item(int item)
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

                pos = find_place(current,item);
                add(btn,pos,pos->data>=item);
            }
        }

    void find_element(int item)
    {
        BinaryTreeNode* node = find_item(root, item);
        if(node==NULL)
            cout<<item<<" is not in the BST\n";
        else
            if (node->parent != NULL)
                cout<<node->data<<" is on the BST with parent "<<node->parent->data<<".\n";
            else
                cout<<node->data<<" is at the root of the BST.\n";
    }
    
    void inorder(BinaryTreeNode *rt)
    {
        if(rt!=NULL)
        {
            inorder(rt->left);
            cout<<rt->data<<" ";
            inorder(rt->right);
        }
    }
    
    void sort_data()
    {
        cout<<"\n";
        inorder(root);
    }

    BinaryTreeNode * find_min_recursive(BinaryTreeNode * current)
    {
        if(current->left != NULL)
        {
            find_min_recursive(current->left);
        }
        else 
            return current;
    }

    void find_min()
    {
        BinaryTreeNode * min_node = find_min_recursive(root);
        cout<<"\nMinimum valued element "<< min_node->data;
    }
    
    BinaryTreeNode * find_max_recursive(BinaryTreeNode * current)
    {
        if(current->right != NULL)
            // Notes on returning a recursive call
            // In most languages, if you don't use the return value of a function you called (recursively or not), 
            // either that return value gets discarded or it is a diagnosable error. 
            // There are some languages where the return value of the last function call gets automatically 
            // re-used as the return value of the current function invocation, 
            // but they don't differentiate between normal and recursive function calls.
            return find_max_recursive(current->right);
        else 
            return current;
    }

    void find_max()
    {
        BinaryTreeNode * max_node = find_max_recursive(root);
        cout<<"\nMaximim valued element "<< max_node->data;
    }
    
    
    void delete_item(int item)
    {
        BinaryTreeNode* node = find_item(root, item);
        if(node!= NULL)
        {
            // case 1: 'node' has two children. Find the largest node 'lnode' (a leaf, by definition) in the right subtree of 'node'
            // Replace data of lnode with the data of node.
            // update parent pointer
            // delete lnode (which should be a leaf)
            if(node->right !=NULL && node->left!=NULL)
            {
                BinaryTreeNode *lnode = find_max_recursive(node->left);
                node->data = lnode->data;
                if(lnode->parent != NULL)
                {   if(lnode->parent->right==lnode)
                        lnode->parent->right = NULL;
                    else if(lnode->parent->left==lnode)
                        lnode->parent->left = NULL;
                }
                free(lnode);
                return;
            }
            // case 2: 'node' has one child child_node. 
            // Replace data of child_node with the data of node.
            // update pointers
            // delete child_node (which should be a leaf)
            if (node->left !=NULL || node->right != NULL)
            {
                BinaryTreeNode * child_node =  node->left !=NULL ? node->left : node->right;
                node->data = child_node->data;
                node->right = child_node->right;
                node->left = child_node->left;
                free(child_node);
                return; 
            }
            // case 3: 'node' has no child 
            // update parent pointers
            // delete child_node (which should be a leaf)
            if (node->left ==NULL && node->right == NULL)
            {
                if(node->parent!=NULL)
                {
                    if(node->parent->right==node)
                        node->parent->right = NULL;
                    else if(node->parent->left==node)
                        node->parent->left = NULL;
                }
                free(node);
                return; 
                return; 
            }
        }
    }
};





int main()
{
    BinarySearchTree bst;
    bst.insert_item(1);
    bst.insert_item(0);
    bst.insert_item(20);
    bst.insert_item(10);
    bst.insert_item(21);
    bst.insert_item(8);
    bst.insert_item(12);
    bst.insert_item(11);
    bst.insert_item(13);
    // bst.insert_item(8);
    // bst.insert_item(-1);
    // bst.insert_item(9);
    
    bst.find_element(11);
    bst.sort_data();
    bst.find_min();
    bst.find_max(); 
    bst.delete_item(1);
    bst.sort_data();
    return 0;
}

