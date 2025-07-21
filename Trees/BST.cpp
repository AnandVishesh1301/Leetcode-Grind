// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    //Node* data;
    Node* left;
    Node* right;
};

Node* createNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;

}

Node*  Insert(Node** rootPtr , int data) {  // We need to modify the root passed via main, so instead of passing it locally by value, we 
    // are passing it by reference(pointer to the rootNode
    if (*rootPtr == nullptr) { // Tree is Empty
        *rootPtr = createNewNode(data); 
    }
    else if (data <= (*rootPtr)->data) {
        (*rootPtr)->left = Insert(&(*rootPtr)-> left, data);
    }

    else {
        (*rootPtr)->right = Insert(&(*rootPtr)->right, data);
    }
    return *rootPtr;

}

bool Search(Node* root, int data){
    if (!root) {
        return false;
    }
    else if (root->data == data) {
        return true;
    }
    else if (data <= root->data) {
       return Search((root)->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

int FindMin(Node* curr) {
    if (!curr) {
        cout << "Tree is Empty";
        return -1;
    }
    else if (curr -> left == nullptr) { // Base Case
        return curr->data;

    }
    // Search in left subtree
    return FindMin(curr->left);
}

int FindMax(Node* curr) {
    if (!curr) {
        cout << "Tree is Empty";
        return -1;
    }
    else if (curr->right == nullptr) { // Base Case
        return curr->data;

    }
    // Search in right subtree
    return FindMax(curr->right);
}

int FindHeight(Node* curr) {
    if (!curr) {
        return -1;
    }

    int leftHeight = FindHeight(curr->left);
    int rightHeight = FindHeight(curr->right);

    return max(leftHeight , rightHeight) + 1;
}


// BFS (Using a Queue)
// Time Complexity: O(n)
// Space Complexity: O(1) - best, O(n/2) ~ O(n) - avg/worst
void BFS(Node* root) {
    if(!root) return;
    queue<Node*> q;
    q.push(root);

    // While there is atleast oine discovered node, or te queue is not emopty
    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->data << " ";
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
        q.pop(); // Remove the element at the front as we already pushed both its l and r children

    }

}

// DFS
// Time Complexity: O(n)
// Space Complexity: Will depend on the size of the implicit call stack due to recursion, as the size of the call stack depends on the depth of the tree
// so leat at root, and most at leaf
// best/avg: O(log n)
// worst: O(n)

void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (!root) return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}

void postOrder(Node* root) {
    if (!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";

}


int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\n======= Binary Search Tree Menu =======\n";
        cout << "1. Insert a number\n";
        cout << "2. Search a number\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
        cout << "5. Find Height\n";
        cout << "6. BFS Traversal (level order)\n";
        cout << "7. DFS Traversal (pre/in/post)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data;
            cout << "Enter number to insert: ";
            cin >> data;
            Insert(&root, data);
            cout << data << " inserted.\n";
            break;
        }
        case 2: {
            int key;
            cout << "Enter number to search: ";
            cin >> key;
            cout << "Key " << key << (Search(root, key) ? " is" : " is NOT")
                << " present.\n";
            break;
        }
        case 3: {
            int v = FindMin(root);
            if (v != -1) cout << "Minimum value: " << v << '\n';
            break;
        }
        case 4: {
            int v = FindMax(root);
            if (v != -1) cout << "Maximum value: " << v << '\n';
            break;
        }
        case 5: {
            int h = FindHeight(root);
            if (h != -1) cout << "Height of BST: " << h << '\n';
            else cout << "Tree is empty.\n";
            break;
        }
        case 6: {                     
            if (!root) { cout << "Tree is empty.\n"; break; }
            cout << "BFS traversal: ";
            BFS(root);
            cout << '\n';
            break;
        }
        case 7: {                     
            if (!root) { cout << "Tree is empty.\n"; break; }

            int dfsChoice;
            cout << "\n--- DFS Traversal Order ---\n";
            cout << "1. Pre order\n";
            cout << "2. In order\n";
            cout << "3. Post order\n";
            cout << "Enter your choice: ";
            cin >> dfsChoice;

            switch (dfsChoice) {
            case 1:
                cout << "Pre order: ";
                preOrder(root);
                cout << '\n';
                break;
            case 2:
                cout << "In order: ";
                inOrder(root);
                cout << '\n';
                break;
            case 3:
                cout << "Post order: ";
                postOrder(root);
                cout << '\n';
                break;
            default:
                cout << "Invalid DFS choice.\n";
            }
            break;
        }
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}