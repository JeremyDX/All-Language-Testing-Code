public class Main
{
	public static void main(String[] args)
	{
		int IMAGE_WIDTH = 400;
		int IMAGE_HEIGHT = 640;
		
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 200, 640);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 400, 320);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 200, 320);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 400, 640);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 500, 640);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 400, 740);
		ResizeImage(IMAGE_WIDTH, IMAGE_HEIGHT, 500, 740);
	}

	private static void ResizeImage(int w, int h, int res_w, int res_h)
	{
		StringBuilder sb = new StringBuilder();	

		float width = (float)resize_w / original_w;
		float height = (float)resize_h / original_h;

		if (width < height)
		{
			height = width * original_h;
			width *= original_w;
		}
		else {
			width = height * original_w;
			height *= original_h;
		}
		
		sb.append("\nWidth: ").append((int)width);
		sb.append("\nHeight: ").append((int)height);
		sb.append('\n');
		System.out.println(sb.toString());
	}
}