package sorting;

/**
 * insertionSorting
 */
public class insertionSorting {

    public static void main(String[] args) {
        int[] a={9,8,7,6,5,4,3,2,1};
        for (int i = 0; i < a.length-1; i++) {
            for (int j = i; j >=0; j--) {
                if (a[j+1]<a[j]) {
                    int temp=a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;

                    
                }
                
            }
            
        }
        for (int item : a) {
            System.out.print(item+" ");
        }
        
    }
}
