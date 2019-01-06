public class StringSplitByNumber
{

    public static void main (String[] args) throws java.lang.Exception
    {
      	char[] array = "1testes1233iambeginnerplshelp123a".toCharArray();
        StringBuilder sb = new StringBuilder();

        int slice = 0;
	for (int n = 0; n < array.length; n++) 
	{
            while (n < array.length - 1) 
	    {
		if (!isNumber(array[n]) && isNumber(array[n+1]))
			break;
		
		sb.append(array, n, 1);
		++n;
            }
            sb.append(array, n, 1);
	    sb.append('\n');
        }

	System.out.println(sb.toString());
    }

    private static boolean isNumber (char c) {
        return ((int)c >=48) && ((int)c <= 57);
    }
}