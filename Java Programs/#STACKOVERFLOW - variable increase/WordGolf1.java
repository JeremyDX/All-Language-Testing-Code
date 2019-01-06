import java.util.*;

public class WordGolf1 
{

	private static int SCORE = 0;

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
	  	while (true)
           	{
			System.out.print("\n\nEnter word: ");

			ParseSentence(sc.nextLine());

			if (SCORE == 100)
			{
				System.out.print("\nYou Won! Would you like to play again: Y/N?");
				if ((sc.nextLine().charAt(0) | 32) == 'y')
				{
					SCORE = 0;
					System.out.print("\nResetting Game...");
				} else {
					break;
				}
			}
			else
			{	
				if (SCORE > 100)
				{
					int overshot = SCORE - 100;
					SCORE = SCORE % 100;
					System.out.print("\nYou Overshot By " + overshot + " Points. You now have " + SCORE + " points.");
				} else {
					System.out.print("\nYou currently have " + SCORE + " points you need " + (100 - SCORE) + " more.");
				}
			}
		}
	}

	private static int ParseSentence(String input)
	{
		String[] split = input.split(" ");
		for (Strng s : input)
			SCORE += ParseWord(s);
	}

	private static int ParseWord(String word)
	{
	 	int value = 1;
		for (int i = 0; i < word.length(); ++i)
		{
			int c = (int)word.charAt(i) | 32;
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			{
				value *= 2;
			} else {
				value += 1;
			}
		}
		return value;
	}
}