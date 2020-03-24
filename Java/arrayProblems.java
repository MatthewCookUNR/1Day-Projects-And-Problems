import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Iterator;

class arrayFunctions {
	public static void main(String []args) {
    	int [] testArray = {1, 4, 2, 5, 9, 2, 9, 4};
    	System.out.println(findDuplicate(testArray));
    	removeDuplicate(testArray);
    	
    }
	
	public static int findDuplicate(int[] array)
	{
		HashMap<Integer, Integer> map = new HashMap<>();
		for(int i = 0; i < array.length; i++)
		{
			if(map.containsKey(array[i])) {
				return array[i];
			}
			else {
				map.put(array[i], 1);
			}
		}
		return -1;
	}
	
	public static void removeDuplicate(int[] array)
	{
		LinkedHashMap<Integer, Integer> map = new LinkedHashMap<>();
		for(int i = 0; i < array.length; i++)
		{
			if(!map.containsKey(array[i])) 
			{
				map.put(array[i], 1);
			}
		}
		
		array = new int [map.size()];
		int index = 0;
		
		Iterator it = map.entrySet().iterator();
		while(it.hasNext())
		{
			Map.Entry pair = (Map.Entry) it.next();
			array[index] = (int) pair.getKey();
			index++;
			it.remove();
		}
		
    	for(int i = 0; i < array.length; i++)
    	{
    		System.out.print(array[i] + " ");
    	}
    	System.out.println("");
		
	}
}