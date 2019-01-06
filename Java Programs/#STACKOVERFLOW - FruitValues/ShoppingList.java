import java.util.Scanner;

public class ShoppingList
{
	private static long LOWEST_ITEM_COST = Long.MAX_VALUE;
	private static long HIGHEST_ITEM_COST = -1;

	private static long TOTAL_COST = 0;
	private static int TOTAL_ITEMS = 0;

	private static String LOWEST_ITEM_NAME;
	private static String HIGHEST_ITEM_NAME;

	public static void main(String[] args)
	{
		System.out.print("\nSyntax: FOODNAME PRICE, I.e. Apples $8.50");
		while (true)
		{
			Scanner sc = new Scanner(System.in);
			
			System.out.print("\nEnter a food: ");
			
			String split[] = sc.nextLine().split(" ");

			if (split.length > 2)
			{
				
			}

			if (split.length == 2)
			{
				String name = split[0];	

				int length = split[1].length();
				int decimal_position = -1;
				for (int j = length; --j >= 0; )
				{
					if (split[1].charAt(j) == '.')
					{
						decimal_position = j;
						break;
					}
				}

				if (decimal_position != -1)
					length = decimal_position;

				long dollars = 0;
				long change = 0;
				int place = 100;

				for (int c = length; --c >= 0; )
				{
					int value = (int)split[1].charAt(c) - 48;

					if (value < 0 || value > 10)
						continue;

					if (place == 1000000000) //1 Billion is too large to process stop here!
					{
						System.out.print("\nPrice Amount exceeds $999,999,999.99 limitation! You entered: " + split[1]);
						continue;
					}

					value *= place;
					place *= 10;
					dollars += value;
				}

				place = 10;

				if (decimal_position != -1 && (split[1].length() - 3 >= decimal_position))
				{
					for (int c = decimal_position; c < split[1].length(); ++c)
					{
						int value = (int)split[1].charAt(c) - 48;

						if (value < 0 || value > 10)
							continue;

						value *= place;
						place -= 9;
						change += value;

						if (place < 0)
							break;
					}		
				}
		
				System.out.print("\nItem: " + name + " was added to the shopping cart. Cost: $" + (dollars / 100) + '.' + ((change < 10) ? (change + '0') : (change)));
		
				dollars += change;

				if (dollars < LOWEST_ITEM_COST)
				{
					LOWEST_ITEM_COST = dollars;
					LOWEST_ITEM_NAME = name;
				}

				if (dollars > HIGHEST_ITEM_COST)
				{
					HIGHEST_ITEM_COST = dollars;
					HIGHEST_ITEM_NAME = name;
				}		
				
				TOTAL_ITEMS++;
				TOTAL_COST += dollars;
			} else {
				if (split.length == 1 && split[0].toLowerCase().contains("done"))
				{
					break;
				}
				System.out.print("\nSyntax: FOODNAME PRICE, E.g. IceCream 8.50");
				System.out.print("\nTo Finish The Shopping List Simply type: DONE");
				continue;
			}
		}

		if (TOTAL_ITEMS == 0)
		{
			System.out.print("\nNothing Was Added To Your Shopping List Today..");
			return;
		}

		long dollars = HIGHEST_ITEM_COST / 100;
		long change = HIGHEST_ITEM_COST - (dollars * 100);

		System.out.print("\nHighest Cost Item: " + HIGHEST_ITEM_NAME + " , Costed: " + dollars + '.' + change + ((change < 10) ? '0' : ""));


		dollars = LOWEST_ITEM_COST / 100;
		change = LOWEST_ITEM_COST - (dollars * 100);

		System.out.print("\nLowest Cost Item: " + LOWEST_ITEM_NAME + " , Costed: " + dollars + '.' + change + ((change < 10) ? '0' : ""));
	
		dollars = TOTAL_COST / 100;
		change = TOTAL_COST - (dollars * 100);

		System.out.print("\nTotal Items Bought: " + TOTAL_ITEMS + " , With a total cost of $" + dollars + '.' + change + ((change < 10) ? '0' : ""));
	}
}