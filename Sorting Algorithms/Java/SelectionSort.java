public class SelectionSort {
    public static void main(String[] args) {
        //My array of values
        int[] arr = new int[]{9, 8, 13, 2, 5, 22, 1315, 13, 4};
        System.out.println("Array before sorting: ");
        printArray(arr);

        selectionSortMethod(arr);
        System.out.println("Array after sorting: ");
        printArray(arr);
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print("Index " + i + " =");
            System.out.print(arr[i] + "\t");
        }
        System.out.println("\n");

    }


    public static void selectionSortMethod(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int min = array[i];
            int minId = i;
            for (int j = i+1; j < array.length; j++) {
                if (array[j] < min) {
                    min = array[j];
                    minId = j;
                }
            }
            // swapping
            int temp = array[i];
            array[i] = min;
            array[minId] = temp;
        }
    }
}