##Shell sort
**It is an in-place comparison sort.**
***This algorithm is based on sorting pairs of elements far apart from each other, by progressively reducing the gap between elements to be compared. Starting with far apart elements, algorithm  moves some out-of-place elements into position faster than a simple nearest neighbor exchange.***
###Time complexity
**The running time of Shellsort is heavily dependent on the gap sequence it uses.**
-Worst case performance O(nlog2 2n)
-Best case performance O(n log n)
-Average case performance depends on gap sequence

##Python Code implementation of Shell sort

>def shellSort(arr):
> # start with large gap and then reduce it to smaller one
>n=len(arr)
>gap=n/2

> # perform gapped insertion sort for this gap size.
> # The first gapped elements are already in Gap
> # Order keep adding till the end of array
> # is gap sorted

> while gap>0:
> for j in range(gap,n):
> # add a[j] to the elements that have been gap sorted 
> # then,save a[j] in temp and make a hole at position j
> temp=arr[j]

> # shift earlier gap-sorted elements up until the correct location for a[j] is found 

> k=j
> while  k >= gap and arr[k-gap] >temp: 
>arr[k] = arr[k-gap] 
> k -= gap 
  
> # put temp (the original a[j]) in its correct location 
> arr[k] = temp 
>gap /= 2

> #main program
> arr = [ 12, 34, 54, 2, 3] 
  
>n = len(arr) 
>print ("Array before sorting:") 
>for i in range(n): 
    >print(arr[i]), 
  
>shellSort(arr) 
  
>print ("\nArray after sorting:") 
>for i in range(n): 
>print(arr[i])

##thanks for reading!



