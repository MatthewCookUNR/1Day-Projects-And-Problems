import java.util.HashMap; 

public class TwoSum
{

    public static void main(String []args)
    {
       int [] result = twoSum(12, new int[] {4, 7, 3, 5, 6});
       for(int i = 0; i < result.length; i++)
       {
           System.out.println(result[i]); 
       }
    }
    
    //Goal of function is to find the index of two numbers in
    //the array that add up to the given sum. The result is
    //returned as a array of size 2 with both indices within it.
    private static int[] twoSum(int sum, int[] array)
    {

     //Map is used as a "reverse array" where the value
     //becomes the key and the key becomes the value
   	 HashMap<Integer, Integer> map = new HashMap();

   	 for(int i = 0; i < array.length; i++)
   	 {   
   		 if(map.containsKey(sum - array[i])) 
         {
   			 return new int[] {i, map.get(sum-array[i])};
   		 }
   		 else 
         {
   			 map.put(array[i], i);
   		 }
   	 }
   	 return new int[] {};
    }
}

