public class MergeSort{

    public static void main(String[] args){
        int[] arr = new int[]{9,8,13,2,5,22,1315,13,4};
	System.out.println("Array before sorting: ");
	for(int i = 0; i < arr.length; i++){
	  System.out.print(arr[i] + " ");
	}
	System.out.println("");
	mergeSort(arr);
	System.out.println("Array after sorting: ");
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i]+" ");
        }
	System.out.println("");

    }

    // Feed initial array into a helper function that calls real MergeSort (through Overloading)
    public static void mergeSort(int[] arr){
        mergeSort(arr, new int[arr.length], 0, arr.length-1);
    }

    public static void mergeSort(int[] arr, int[] temp, int start, int end){
        // Once each element is isolated, return to start actually sorting
        if(start >= end){
            return;
        }

        // Calculate Middle Index
        int middle = (start+end) / 2;

        // Make a recursive call to use mergeSort on the first half of array
        mergeSort(arr, temp, start, middle);

        // Make a recursive call to use mergeSort on the second half of array
        mergeSort(arr, temp, middle+1, end);

        // Call mergeHalves to merge the two together
        mergeHalves(arr, temp, start, end);
    }

    // Helper method that does the heavy lifting of sorting halves
    public static void mergeHalves(int[] arr, int[] temp, int leftStart, int rightEnd){

        // Calculate the end of the first array, and the start of the second array
        int leftEnd = (rightEnd + leftStart)/2;
        int rightStart = leftEnd+1;

        // Calculate the overall size of the merged subarray
        int size = rightEnd-leftStart + 1;

        // Initialize pointers for each index
        int left = leftStart;
        int right = rightStart;
        int index = leftStart;

        // While the pointers for right and left subarrays haven't hit their end,
        // Compare the values 
        while(left <= leftEnd && right <= rightEnd){

            // If the left index is smaller than the right index, set the temp index to that value and increment left
            // Otherwise, do the same with right. After both, increment index.
            if(arr[left] <= arr[right]){
                temp[index] = arr[left];
                left++;
            } else {
                temp[index] = arr[right];
                right++;
            }
            index++;
        } 

        // Java library function for copying parts of an array into another
        // Out of the two following calls, ONLY ONE will take effect since
        // one the pointers should have reached it's end
        System.arraycopy(arr, left, temp, index, leftEnd-left+1);
        System.arraycopy(arr, right, temp, index, rightEnd-right+1);

        // Copy the values from the temp array into the original. 
        System.arraycopy(temp, leftStart, arr, leftStart, size);
    }
}
