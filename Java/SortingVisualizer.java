import java.util.Arrays;

class SortingVisualizer {
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            System.out.println("Step " + (i + 1) + ": " + Arrays.toString(arr));
        }
    }

    public static void visualize() {
        int[] arr = {5, 3, 8, 6, 2};
        System.out.println("Sorting Array: " + Arrays.toString(arr));
        bubbleSort(arr);
    }
}
