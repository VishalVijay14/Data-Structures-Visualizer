import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Data Structures and Algorithms Visualizer");
        System.out.println("Select an option:");
        System.out.println("1. Linked List Visualization");
        System.out.println("2. Binary Tree Visualization");
        System.out.println("3. Sorting Algorithms Visualization");
        System.out.print("Enter choice: ");
        
        int choice = scanner.nextInt();
        switch (choice) {
            case 1:
                LinkedListVisualizer.visualize();
                break;
            case 2:
                BinaryTreeVisualizer.visualize();
                break;
            case 3:
                SortingVisualizer.visualize();
                break;
            default:
                System.out.println("Invalid choice. Exiting.");
                break;
        }

        scanner.close();
    }
}