public class LinearSearch {
	public static void main(String[] args) {
		int[] arr = {1, 5, 2, 3, 4};
		linearSearch(arr, 2);
		linearSearch(arr, 7);
	}

	public static void linearSearch(int[] arr, int key) {
		for(int i = 0; i < arr.length; i++) 
			if(arr[i] == key){
				System.out.println("Found at position " + i);
				return;
			}
		System.out.println("Not found");
	}
}