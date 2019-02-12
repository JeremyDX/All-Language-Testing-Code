public class Main
{
	public static void main(String[] args)
	{
		int value = 129;

		int ZERO = (int)' ';
	
		System.out.println("Zero: " + ZERO);

		System.out.println(new String(DecimalToBinary(value, 4)));
		System.out.println(new String(DecimalToBinary(value, 8)));
		System.out.println(new String(DecimalToBinary(value, 12)));
		System.out.println(new String(DecimalToBinary(value, 16)));
		System.out.println(new String(DecimalToBinary(value, 20)));
		System.out.println(new String(DecimalToBinary(value, 24)));
		System.out.println(new String(DecimalToBinary(value, 28)));
		System.out.println(new String(DecimalToBinary(value, 32)));
	}

	public static char[] DecimalToBinary(int value, int bitsize)
	{
		char[] binary = new char[(bitsize + 7) >> 3 << 3];
		int begin = binary.length - bitsize;
		int bit_value = 1;
		for (int n = binary.length; --n >= begin; )
		{
			if ((value & bit_value) == bit_value)
				binary[n] = 49;
			else
				binary[n] = 48;
			bit_value <<= 1;
		}
		///for (int n = begin; --n >= 0; )
		///	binary[n] = 48;
		return binary;
	}
}
