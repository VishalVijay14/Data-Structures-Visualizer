class BinaryTreeVisualizer {
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            this.left = this.right = null;
        }
    }

    private Node root;

    public BinaryTreeVisualizer() {
        root = null;
    }

    public void insert(int data) {
        root = insertRec(root, data);
    }

    private Node insertRec(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data < root.data)
            root.left = insertRec(root.left, data);
        else if (data > root.data)
            root.right = insertRec(root.right, data);
        return root;
    }

    public void inorder() {
        inorderRec(root);
        System.out.println();
    }

    private void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }

    public static void visualize() {
        BinaryTreeVisualizer tree = new BinaryTreeVisualizer();
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        System.out.println("Binary Tree (In-order traversal):");
        tree.inorder();
    }
}
