

#include <iostream>

using namespace std;

class AVLTree
{
    public:
    
        struct BinaryTreeNode
        {
            int data;
            BinaryTreeNode * left;
            BinaryTreeNode * right;
            int height; 
        };
        BinaryTreeNode * root;
        AVLTree()
        {
            root=NULL;
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
        
        int get_balance_factor(BinaryTreeNode *node)
        {
            return height(node->left) - height(node->right);    
        }
        
        int height(BinaryTreeNode* node)
        {
            if(node==NULL)
                return 0;
            else 
                return node->height;
        }
        
        inline int max(int x, int y)
        {
            return x>y?x:y;
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
    
    BinaryTreeNode * new_node(int item)
    {
            BinaryTreeNode * node = new BinaryTreeNode();
            node->data = item;
            node->right = NULL;
            node->left = NULL;
            node->height = 1;
            return node;
    }
        
    BinaryTreeNode * left_rotate(BinaryTreeNode *X)
    {
            /** Data: X,Y, Z (Z is the new data to inserted with Z>Y>X)
                     X                                                   Y
                      \                                                 /\
                      Y    -------------------------->                 X  Z 
                     / \                                                \
                    T  Z                                                T
              
             */
            BinaryTreeNode * Y = X->right;
            BinaryTreeNode * left_tree_Y = Y->left; 
            
            //rotate 
            X->right = left_tree_Y;
            Y->left = X;
            
            X->height = 1+max(height(X->left), height(X->right));
            Y->height = 1+max(height(Y->left), height(Y->right));
            return Y;
    }
        
    BinaryTreeNode * right_rotate(BinaryTreeNode *Z)
    {
            /*
                    Data: Z,Y, X (X is the New item to be inserted, with Z > Y >X)
                    Z                                           Y 
                   /                                           /\
                  Y     -------------------------->           X Z 
                 /\                                            / 
                X T                                           T
            */
            BinaryTreeNode * Y = Z->left;
            BinaryTreeNode * right_tree_Y = Y->right;
            
            Z->left = right_tree_Y;
            Y->right = Z;
            
            Z->height = 1+max(height(Z->left), height(Z->right));
            Y->height = 1+max(height(Y->left), height(Y->right));
            return Y;
    }
        
    BinaryTreeNode * right_left_rotate(BinaryTreeNode *node)
    {
            node->right = right_rotate(node->right);
            return left_rotate(node);
            //return NULL;
    }
        
    BinaryTreeNode * left_right_rotate(BinaryTreeNode *node)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
        
    BinaryTreeNode * insert_item(BinaryTreeNode* node, int item)
    {
            if(node == NULL)
                return new_node(item);
            else if(item < node->data)
                node->left = insert_item(node->left,item);
            else if(item > node->data)
                node->right = insert_item(node->right, item);
            else
                return node;
                
            node->height = 1+max(height(node->left), height(node->right));
            
            int bf = get_balance_factor(node);
            cout<<node->data<<" ("<<bf<<")\n";            
            if(bf>1 && item < node->left->data) // Left - Left insertion for 'node'
                return right_rotate(node);                
            if(bf<-1 && item > node->right->data) // Right Right insertion for node 
                return left_rotate(node);
            if(bf>1 && item > node->left->data) // Left Right insertion for node
                return left_right_rotate(node);
            if(bf<-1 && item < node->right->data ) // Right Left insertion for node
                return right_left_rotate(node);
                
            return node;
    }


};

int main()
{
    AVLTree avlt;
    avlt.root=avlt.insert_item(avlt.root, -1);
    avlt.root=avlt.insert_item(avlt.root, 0);
    cout<<"\n Root Data:"<<avlt.root->data<<"\n";

    avlt.root=avlt.insert_item(avlt.root, 1);
    // avlt.root=avlt.insert_item(avlt.root, 10);
    // avlt.root=avlt.insert_item(avlt.root, 21);
    //avlt.root=avlt.insert_item(avlt.root, 8);


    avlt.inorder(avlt.root);
    cout<<"\n Root Data:"<<avlt.root->data;
    // avlt.insert_item(0);
    // avlt.insert_item(20);
    // avlt.insert_item(10);
    // avlt.insert_item(21);
    // avlt.insert_item(8);
    // avlt.insert_item(12);
    // avlt.insert_item(11);
    // avlt.insert_item(13);
    // // avlt.insert_item(8);
    // // avlt.insert_item(-1);
    // // avlt.insert_item(9);
    
    // avlt.find_element(11);
    // avlt.sort_data();
    // avlt.find_min();
    // avlt.find_max(); 
    // avlt.delete_item(1);
    // avlt.sort_data();
    return 0;
}

