using System;

namespace Rextester
{
    public class Program
    {
        public static void Main(string[] args)
        {
            
            Console.WriteLine("Enter size of array:");
            String sizeString = Console.ReadLine();
            int size = int.Parse(sizeString);
            int[] array = new int[size];
			
			Console.WriteLine("Enter elements");
			for(int i = 0; i < size; i++){
				String elementString = Console.ReadLine();
				int element = int.Parse(elementString);
				array[i] = element;
			}
			
			Console.WriteLine("Enter item to search:");
			String itemString = Console.ReadLine();
			int item = int.Parse(itemString);
         
			search(array, item);
			
        }
		
		public static void search(int[] array, int element){
			int i = 0;
			while((i < array.Length)&&(array[i] != element)){
				i+=1;
			}
			if(i > array.Length-1){
				Console.WriteLine("Element not found");
			}
			else{
			Console.WriteLine("Element found. Index : [ " + i + " ]");
			}
			
		}
    }
}