public static int[] BubbleSort(int[] arr)
{
    int l = arr.Length;
    int temp = arr[0];
    for (int i = 0; i < l; i++)
    {
        for (int j = i+1; j < l; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;        
}
