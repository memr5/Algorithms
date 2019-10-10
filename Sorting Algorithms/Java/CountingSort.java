public class CountingSort {

    public static void main(String args[])
    {
        CountingSort countingSort = new CountingSort();
        //array of characters
        char elements[] = {'h', 'a', 'c', 'k', 't', 'o', 'b', 'e', 'r', 'f', 'e', 's', 't'
        };

        countingSort.sort(elements);

        System.out.print("Sorted character array is ");
        for (int i=0; i<elements.length; ++i)
            System.out.print(elements[i]);
    }

    void sort(char arr[])
    {   
        int i;
        int n = arr.length;

        // The result character array will have sorted arr elements
        char result[] = new char[n];

        // Create a count array to store count of inidividual
        // characters and initialize count array as 0
        int count[] = new int[256];
        for (i=0; i<256; ++i)
            count[i] = 0;

        // store count of each character
        for (i=0; i<n; ++i)
            ++count[arr[i]];

        // Change count[i] so that count[i] now contains actual
        // position of this character in output array
        for (i=1; i<=255; ++i)
            count[i] += count[i-1];

        // Store sorted elements in result array.
        // To make it stable we are operating in reverse order.
        for (i = n-1; i>=0; i--)
        {
            result[count[arr[i]]-1] = arr[i];
            --count[arr[i]];
        }

        // Copy the result array to arr
        for (i = 0; i<n; ++i)
            arr[i] = result[i];
    }

}
