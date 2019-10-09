import java.util.*;
// Greedy O(nlogn) approach for LIS
public class LongestIncreasingSubsequence{
  public static int lengthOfLIS(int[] nums) {
        if(nums.length==0)
            return 0;
        int[] end=new int[nums.length];
        int size=0;
        end[size]=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]>end[size]){
                end[++size]=nums[i];
            }
            else{
                int index=bs(end,0,size,nums[i]);
                end[index]=nums[i];
            }
        }
        return size+1;
    }

    public static int  bs(int[] a,int low,int high,int el){
        if(low>high)
            return low;
        int mid=(low+high)/2;
        if(a[mid]==el)
            return mid;
        else if(el<a[mid]){
            return bs(a,low,mid-1,el);
        }
        else
            return bs(a,mid+1,high,el);
    }


    public static void main(String[] args){
      //driver code
      Scanner hk= new Scanner(System.in);
      int n=hk.nextInt();
      int[] a= new int[n];
      for(int i=0;i<n;i++){
        a[i]=hk.nextInt();
      }
      System.out.println(lengthOfLIS(a));
    }


}
