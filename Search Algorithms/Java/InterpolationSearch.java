
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int length, ele;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        length = scanner.nextInt();

        int arr[]=new int[length];
        System.out.println("Enter elements: ");

        for(int i=0;i<length;i++){
            arr[i]=scanner.nextInt();
        }

        System.out.println("Enter element to find: ");
        ele = scanner.nextInt();

        int index = interpolationSearch(arr, ele);

        if (index != -1)
            System.out.println("Element found at index " + index);
        else
            System.out.println("Element not found.");
    }

    public static int interpolationSearch(int[] nums, int val) {

        int lo = 0, mid = 0, hi = nums.length - 1;

        while (nums[lo] <= val && nums[hi] >= val) {

            mid = lo + ((val - nums[lo]) * (hi - lo)) / (nums[hi] - nums[lo]);
            if (nums[mid] < val) {
                lo = mid + 1;

            } else if (nums[mid] > val) {
                hi = mid - 1;

            } else return mid;
        }

        if (nums[lo] == val) return lo;

        return -1;
    }

}
