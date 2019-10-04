public class QuickSort {
    public static void main(String[] args) {
        //My array of values
        int[] arr = new int[]{9, 8, 13, 2, 5, 22, 1315, 13, 4};
        System.out.println("Array before sorting: ");
        printArray(arr);

        quickSortMethod(arr,0,arr.length-1);
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

    static int partition(int[] array, int begin, int end) {
        int pivot = end;

        int counter = begin;
        for (int i = begin; i < end; i++) {
            if (array[i] < array[pivot]) {
                int temp = array[counter];
                array[counter] = array[i];
                array[i] = temp;
                counter++;
            }
        }
        int temp = array[pivot];
        array[pivot] = array[counter];
        array[counter] = temp;

        return counter;
    }

    public static void quickSortMethod(int[] array, int begin, int end) {
        if (end <= begin) return;
        int pivot = partition(array, begin, end);
        quickSort(array, begin, pivot-1);
        quickSort(array, pivot+1, end);
    }
}