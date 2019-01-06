public class Main
{
	static int TERRAIN_SIZE_X = 5;
	static int TERRAIN_SIZE_Y = 5;

	static int[][] REGION_BLOCK_IDS = new int[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];	

	public static void main(String[] args)
	{
		CreateRegionMatrix(2, 2);

		DrawRegionMatrix();
	}

	private static void CreateRegionMatrix(int xpos, int ypos)
	{
		int left  = xpos - 2;
		int right = xpos + 2;
		int top = ypos - 2;
		int bottom = ypos + 2;
		
		for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				REGION_BLOCK_IDS[x][y] = left + x + (top + (y * TERRAIN_SIZE_Y));
			}
		}
	}

	private static void DrawRegionMatrix()
	{
		StringBuilder sb = new StringBuilder();
		for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				sb.append(REGION_BLOCK_IDS[x][y]);
				if (x < 4 || y < 4)
					sb.append(",");
			}
			sb.append("\n");
		}

		System.out.println(sb.toString());
	}
}