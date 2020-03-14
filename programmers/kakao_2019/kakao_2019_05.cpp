#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node{
    int value;
    int x;
    int y;
    Node* left = NULL;
    Node* right = NULL;
}Node;

vector<pair<int, Node*>> vecCollection;
Node* rootOfBinaryTree;

void insertNode(Node* node)
{
    Node* currentNode = rootOfBinaryTree;
    
    while(true)
    {
        if(currentNode->x > node->x)
        {
            if(currentNode->left != NULL)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode->left = node;
                return;
            }
        }
        else
        {
            if(currentNode->right != NULL)
            {
                currentNode = currentNode->right;
            }
            else
            {
                currentNode->right = node;
                return;
            }
        }
    }
}

void makePreOrder(vector<int> &preorder, Node* root)
{
    preorder.push_back(root->value);
    if(root->left != NULL) makePreOrder(preorder, root->left);
    if(root->right != NULL) makePreOrder(preorder, root->right);
}

void makePostOrder(vector<int> &postorder, Node* root)
{
    if(root->left != NULL) makePostOrder(postorder, root->left);
    if(root->right != NULL) makePostOrder(postorder, root->right);
    postorder.push_back(root->value);
}

void makeTree()
{
    rootOfBinaryTree = vecCollection[0].second;
    
    for(int i = 1; i < vecCollection.size(); i++)
    {
        insertNode(vecCollection[i].second);
    }
}

void getAnswer(vector<vector<int>> &answer)
{
    vector<int> preorder, postorder;
    
    makePreOrder(preorder, rootOfBinaryTree);
    makePostOrder(postorder, rootOfBinaryTree);
    
    answer.push_back(preorder);
    answer.push_back(postorder);
    
    for(int i = 0; i < vecCollection.size(); i++)
    {
        delete vecCollection[i].second;
        vecCollection[i].second = NULL;
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        Node* temp = new Node;
        temp->value = i + 1;
        temp->x = nodeinfo[i][0];
        temp->y = nodeinfo[i][1];
        vecCollection.push_back(make_pair(temp->y, temp));
    }
    
    sort(vecCollection.begin(), vecCollection.end(), greater<pair<int, Node*>>());
    
    makeTree();
    
    vector<vector<int>> answer;
    
    getAnswer(answer);
    
    return answer;
}
