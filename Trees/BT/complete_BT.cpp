

#include <iostream>
#include <queue>

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

        queue<BinaryTreeNode*> queue_btn;
        
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

        /** 
         **** This function finds the place for a new node by using a queue, from which nodes with both children are removed iteratively. Example is as follows: *****

                    Tree                Queue
                    -----               -----
                        1           :   | 1 |
        -----------------------------------------------------------                
                    1                   | 1 | 2 |
                   /
                  2
        ------------------------------------------------------------
                    1                   | 1 | 2 | 3 |
                   /\
                  2  3
        ------------------------------------------------------------
                    1                    | 2 | 3 | 4 |
                   /\
                  2  3
                 /
                4
        ------------------------------------------------------------
        
                    1                    | 2 | 3 | 4 | 5 |
                   /\
                  2  3
                 /\
                4  5

        ------------------------------------------------------------
        
                    1                    | 3 | 4 | 5 | 6 |
                   / \
                  2    3
                 /\   /     
                4  5  6
        **/

            BinaryTreeNode *top;
            do
            {
                top=queue_btn.front();
                if (top->right!=NULL && top->left!=NULL) // keep popping from the queue until get the (oldest) node, which has at least one child location empty.
                    queue_btn.pop();
                else
                    break;
            } while (true);
            return top;
        }
        
        void add(BinaryTreeNode * new_node, BinaryTreeNode* parent, bool is_left_child)
        {
            new_node->parent;
            if(is_left_child) { parent->left = new_node; cout<<"left ";}
            else {parent->right = new_node; cout<<"right ";}
            new_node->right=new_node->left = NULL;
            cout<<"("<<parent->data<<", "<<new_node->data<<")\n";
            
            queue_btn.push(new_node);
        }
    
};



void BinaryTree::insert_item(int item)
{
    BinaryTreeNode *btn = new BinaryTreeNode; 
    btn->data=item;
    if(root==NULL)
    {
        root=btn;
        cout<<"Root \n";
        btn->left=NULL;
        btn->right=NULL;
        btn->parent = NULL;
        
        queue_btn.push(btn);
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

