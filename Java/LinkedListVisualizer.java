class LinkedListVisualizer {
    static class Node {
        int data;
        Node next;
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private Node head;

    public LinkedListVisualizer() {
        this.head = null;
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void delete() {
        if (head != null) {
            head = head.next;
        }
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void visualize() {
        LinkedListVisualizer list = new LinkedListVisualizer();
        list.insert(3);
        list.insert(5);
        list.insert(7);
        System.out.println("Linked List:");
        list.display();
    }
}