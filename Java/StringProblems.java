import java.util.Scanner;

public class StringProblems
{

    public static void main(String []args)
    {
    	Scanner reader = new Scanner(System.in);
       	System.out.println("Please enter a string: ");
       	String input = reader.nextLine();
       	System.out.println(palindrome(input));
       	System.out.println(reverseString(input));
       
   		String testString = "Mateo Cocina";
   		System.out.println(removeCharFunct(testString, 'o'));
    }
    
    private static boolean palindrome(String input)
    {
    	char [] charArray = input.toCharArray();
    	for(int i = 0; i < charArray.length/2; i++)
    	{
    		if(charArray[i] != charArray[charArray.length - i - 1])
    		{
    			return false;
    		}
    	}
    	return true;
    }
    
    private static String reverseString(String input)
    {
    	char [] charArray = input.toCharArray();
    	char temp;
    	for(int i = 0; i < charArray.length/2; i++)
    	{
    		temp = charArray[i];
    		charArray[i] = charArray[charArray.length - i - 1];
    		charArray[charArray.length - i - 1] = temp;


    	}
    	String result = new String(charArray);
    	return result;
    }
    
    public static String removeCharFunct (String myString, char myChar)
    {
    	int index = myString.indexOf(myChar);
    	if(index == -1) {
    		return myString;
    	}
    	
    	return removeCharFunct(myString.substring(0, index) + myString.substring(index+1, myString.length()), myChar);
    }

}

