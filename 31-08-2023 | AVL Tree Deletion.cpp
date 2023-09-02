/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* leftRotate(Node* root) {
    Node* newMid = root->right;
    Node* temp = newMid->left;

    newMid->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

Node* rightRotate(Node* root) {
    Node* newMid = root->left;
    Node* temp = newMid->right;

    newMid->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

Node* inorderSucc(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

Node* deleteAVL(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (val < root->data) {
        root->left = deleteAVL(root->left, val);
    } else if (val > root->data) {
        root->right = deleteAVL(root->right, val);
    } else {
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }

        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);

        root->data = temp->data;

        root->right = deleteAVL(root->right, temp->data);
    }

    if (root == NULL) {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalanceFactor(root);

    if (balance <= 1 && balance >= -1) {
        return root;
    }

    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

Node* deleteNode(Node* root, int data) {
    return deleteAVL(root, data);
}
