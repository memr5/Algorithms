public class BubbleSort {
    public static void main(String[] args) {
        //My array of values
        int[] arr = new int[]{9, 8, 13, 2, 5, 22, 1315, 13, 4};
        System.out.println("Array before sorting: ");
        printArray(arr);

        //Getting the length of the array
        int n = arr.length;

        //Since an array starts from 0 I have taken n-1 as the highest index number of the whole array
        //For the 1st iteration checking starts from the 1st element.......

        /*
        * Step 1 : Index 0 and Index 1 gets selected. If Index 0 > Index 1 swapping happens.
        * Step 2 : Index 1 and Index 2 gets selected. If  Index 1 > Index2 swapping happens.
        * So after each iteration is completed you see the largest value among all of them in the right most conner
        *
        * In the inner for loop j < n-i . The reason is after the 1st iteration is completed automatically the right side gets the highest value.
        * No need to check it again.
        *
        * */
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // swap arr[j+1] and arr[i]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            System.out.println("Array after " + (i + 1) + " iterations");
            printArray(arr);
        }
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
}
