import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Permutation{
    public static void main(String[] args){
        int[] arr = {1,2,3};
        System.out.println(permute(arr).toString());
    }

    public static List<List<Integer>> permute(int[] arr){
        List<List<Integer>> list = new ArrayList<>();
        int[] index = new int[arr.length];
        int n = index.length;
        int fact = 1;

        for(int i=0; i<n; i++){
            index[i] = 0;
            fact*=i+1;
        }

        for(int i=0; i<fact; i++){
            list.add(new ArrayList<>());
        }

        int listIndex = fact-1;
        list.set(listIndex, toList(arr));
        listIndex--;

        int i = 0;
        while(i < n){
            if(index[i] < i){
                int j = i%2 == 0 ? 0: index[i];

                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                list.set(listIndex, toList(arr));
                listIndex--;
                index[i]++;
                i = 0;
            }else{
                index[i] = 0;
                i++;
            }
        }
        return list;
    }

    public static List<Integer> toList(int[] arr){
        List<Integer> list = new ArrayList<>();
        for(int i=arr.length-1; i>=0; i--){
            list.add(arr[i]);
        }
        return list;
    }
}