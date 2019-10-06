public class JumpSearch{
    public static void main(String args[]){
        int arr[] = {3,5,7,2,6,1,8,4,9};
        int x = 8;

        int contain = jumpSearch(x, arr);
        System.out.println("Contain in index: "+contain);
    }

    public static int jumpSearch(int x, int arr[]){
        int step = (int) Math.floor(Math.sqrt(arr.length));

        int prev = 0;
        while(arr[Math.min(step, arr.length)-1] < x){
            prev = step;
            step += (int) Math.floor(Math.sqrt(arr.length));

            if(prev >= arr.length) return -1;
        }

        while(arr[prev] < x){
            prev++;
            if(prev == Math.min(step, arr.length)) return -1;
        }

        if(arr[prev] == x) return prev;
        return -1;
    }
}