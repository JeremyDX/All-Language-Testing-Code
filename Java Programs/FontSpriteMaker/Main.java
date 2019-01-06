import java.io.*;
import javax.imageio.*;
import java.awt.image.*;
import java.awt.*;

public class Main
{
	public static void main(String[] args)
	{
		LoadFile("0_FONT.PNG", 0);

		LoadFile("1_FONT.PNG", 1);

		LoadFile("2_FONT.PNG", 2);

		LoadFile("3_FONT.PNG", 3);
	}

	private static void LoadFile(String s, int font_index)
	{
	    BufferedImage image = null;
	    try {
   		image = ImageIO.read(new File(s));
		int height = 0;
		for (int y = 1; y < image.getHeight(); y++)
		{
			Color rgba = new Color(image.getRGB(1, y), true);
			int color_value = rgba.getRGB() | rgba.getAlpha();
			if (-65281 == color_value)
			{
				height = y;
				break;
			}
		}
		int start = 0;
		int h = 1;
		int boxes = 0;
		int gridX = 0;
		int gridY = 0;
		int idx = 0;
		short[] positions = new short[256];
		byte[] widths = new byte[256];
		for (int x = 1; x < image.getWidth(); x++)
		{
			Color rgba = new Color(image.getRGB(x, h), true);
			int color_value = rgba.getRGB() | rgba.getAlpha();
			if (-65281 == color_value)
			{
				if (x - start == 1)
				{					
					if ((h + height) < image.getHeight())
					{
						start = 0;
						h += height;
						x = 1;
						gridX = 0;
						++gridY;
						continue;
					} else {
						break;
					}
				}
				positions[idx] = (short)(start + 1);
				widths[idx] = (byte)((x - 1) - (start));
				++gridX;
				++boxes;
				start = x;
				++idx;
				if (x + 1 == image.getWidth())
				{	
					if ((h + height) < image.getHeight())
					{
						start = 0;
						h += height;
						x = 1;
						gridX = 0;
						++gridY;
						continue;
					} else {
						break;
					}					
				}
			}
		}
		//stream.writeByte((byte)0x20);
		//stream.writeByte((byte)height);
		//stream.writeByte((byte)boxes);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < boxes; ++i)
		{
			int value = positions[i] + widths[i];
			if (i % 16 == 0 && i != 0)
			{
				sb.append('\n');
			}
			sb.append(value);
			sb.append(',');
			//stream.writeShort(positions[i]);
			//stream.writeByte(widths[i]);
		}
		sb.append("\n\nfonts[").append(font_index).append("].font_size = ");
		sb.append(height - 1).append(";").append("\n");

		sb.append("fonts[").append(font_index).append("].texture_width = ");
		sb.append(image.getWidth()).append(";").append("\n");

		sb.append("fonts[").append(font_index).append("].texture_height = ");
		sb.append(image.getHeight()).append(";").append("\n");
		
		System.out.println(sb.toString());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}