import java.util.Arrays;

// Java program for implementation of insertion sort.
public class SelectionSort
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


    public static void SelectionSort(int[] a)
    {
        // Implementation of Selection Sort.
        for (int i = 0; i < a.length - 1; i++)
        {
            int min_index = i + 1;
            // Search for the minimum index.
            for (int j = i + 1; j < a.length; j++)
            {
                if (isLess(a[j], a[min_index]))
                    min_index = j;
            }
            // Swap the elements.
            exchange(a, i, min_index);
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
        SelectionSort(a);
        System.out.println("After Sorting: " + Arrays.toString(a));   
    }
}