public class BinarySearch {
	public static void main(String args[]) {
		int a[] = {1, 5, 3, 4, 2};

		System.out.println("Searching for 3:");
		int i = binary_search(a, 3);
		System.out.println(i < 0 ? "Not found" : "Found at index" + i);

		System.out.println("Searching for 99:");
		binary_search(a, 99);
		System.out.println(i < 0 ? "Not found" : "Found at index" + i);
	}

	static void binary_search(int a[], k) {
		int min = 0, max = a.length;

		while (min < max) {
			int mid = (min + max) / 2;

			if (a[mid] < k) min = mid + 1;
			else if (a[mid] > k) min = mid - 1;
			else return mid;
		}
		return -1;
	}
}
