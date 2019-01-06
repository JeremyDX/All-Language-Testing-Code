import java.io.*;
import javax.imageio.*;
import java.awt.image.*;
import java.awt.*;

public class Main
{
	public static void main(String[] args)
	{
		BufferedImage img = null;
		try {
   			img = ImageIO.read(new File("U_FXD_1_FONT.PNG"));
			File out = new File("saved.png");
			ImageIO.write(AddBackTransparency(img), "png", out);
		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(img.toString());
	}

	public static BufferedImage AddBackTransparency(BufferedImage image)
	{
	        Graphics2D g2d = image.createGraphics();
		for (int y = 1; y < image.getHeight(); y++)
		{
			for (int x = 1; x < image.getWidth(); x++)
			{
				Color rgba = new Color(image.getRGB(x, y), true);
				int color_value = rgba.getRGB() | rgba.getAlpha();

				int alpha = (color_value >> 24) & 0xFF;
				int red = (color_value >> 16) & 0xFF;
				int green = (color_value >> 8) & 0xFF;
				int blue = (color_value >> 0) & 0xFF;

				int large = (int)((alpha + red + green + blue) * 0.25f);
				int trans_color = (large << 0) | (large << 8) | (large << 16) | (large << 24);

				image.setRGB(x, y, trans_color);
				g2d.drawImage(image, 0, 0, null);
				g2d.dispose();
			}
		}
		return image;
	}

	public static BufferedImage PadImage(BufferedImage img, int w, int h) 
	{
    		BufferedImage newImage = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
		Graphics2D g2d = newImage.createGraphics();
		Color color = new Color(255, 0, 255, 255);		
		g2d.setColor(color); //Set to the Purple Transparency Color.
		g2d.fillRect(img.getWidth(), 0, w - img.getWidth(), h);
		g2d.fillRect(0, img.getHeight(), w, h - img.getHeight());
    		g2d.drawImage(img, 0, 0, null);
	
    		g2d.dispose();

    		return newImage;
	}  
}