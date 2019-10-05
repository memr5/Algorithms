import java.util.Arrays;

// Java program for implementation of insertion sort.
public class InsertionSort
{
    private static boolean isLess(int a, int b)
    {
        // function returns true if the first argument is less than the second element.
        return a < b;
    }


    private static void exchange(int[] a, int i, int j)
    {
        // Function to swap two array elements.
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }


    public static void InsertionSort(int[] a)
    {
        // Implementation of Insertion Sort.
        for (int i = 1; i < a.length; i++)
        {
            int j = i;
            while (j > 0 && isLess(a[j], a[j - 1]))
            {
                exchange(a, j, j - 1);
                j--;
            }
        }
    }

    public static void main(String[] args)
    {
        // Driver function to test the sorting algorithm.
        int[] a = new int[10];
        
        // Fill the array by generating some random numbers.
        for (int i = 0; i < 10; i++)
            a[i] = (int) (Math.random() * 20);

        System.out.println("Before Sorting: " + Arrays.toString(a));       
        InsertionSort(a);
        System.out.println("After Sorting: " + Arrays.toString(a));   
    }
}