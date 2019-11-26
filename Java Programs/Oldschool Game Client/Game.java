package com;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileOutputStream;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import java.applet.Applet;

import java.awt.Font;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Insets;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Toolkit;

import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.net.URLConnection;

import java.nio.channels.Channels;
import java.nio.channels.FileChannel;
import java.nio.channels.ReadableByteChannel;


public class Game
{
	private Applet applet;
	private AppletEnvironment stub;

	private Insets insets;
	private JFrame mainFrame;

	private String directory;

	public Game()
	{
		String sub = System.getProperty("user.home");
		File dir = new File(sub.concat("/jagexcache/oldschool/"));
		if (!dir.exists())
			dir.mkdirs();
		directory = dir.getPath();
	}

	public void getInsets()
	{	
		mainFrame = new JFrame();
		mainFrame.setDefaultCloseOperation(3);
		mainFrame.getContentPane().setPreferredSize(new Dimension(0, 0));
		mainFrame.pack();
		insets = mainFrame.getInsets();
	}

	public void createLoadingScreen()
	{
		int width = insets.left + insets.right + 765;
		int height = insets.top + insets.bottom + 528;
		
		Dimension dimension = Toolkit.getDefaultToolkit().getScreenSize();
		
		mainFrame.setSize(width, height);
		mainFrame.setResizable(false);
		mainFrame.getContentPane().setLayout(null);
		mainFrame.getContentPane().setBackground(Color.BLACK);

		mainFrame.setResizable(true);
		mainFrame.setVisible(true);
	}

	public void downloadGamePack(int world) throws Exception
	{

		stub = grabParameters(world);
		
		File file = new File(directory.concat("/gamepack.jar"));

		StringBuilder sb = new StringBuilder();
		sb.append("http://oldschool").append(world).append(".runescape.com/").append(stub.getParameter("archive"));

		URL website = new URL(sb.toString());
		URLConnection connection = website.openConnection();

		if (!file.exists() || (connection.getContentLength() != file.length()) || file.length() == 0L)
		{
			final Graphics2D g = (Graphics2D) mainFrame.getContentPane().getGraphics();

			g.setColor(new Color(140, 17, 17));
			g.drawRect(231, 259, 304, 32);
			g.setColor(Color.BLACK);
			g.drawRect(232, 260, 302, 30);

			Font font = new Font("SansSerif", Font.BOLD, 13);
			g.setFont(font);

			final ReadableByteChannel rbc = Channels.newChannel(website.openStream());
    			final FileOutputStream fos = new FileOutputStream(file.getPath());
			
			new Thread()
			{
				public void run()
				{
					try {
    						fos.getChannel().transferFrom(rbc, 0, 1 << 24);
					} catch (Exception e) { }
				}
			}.start();

			while (file.length() != connection.getContentLength())
			{
				int complete = (int)(100 * ((double)file.length() / (double)connection.getContentLength()));
				
				g.setColor(Color.BLACK);
				g.fillRect(233, 261, 300, 29);
				g.setColor(new Color(140, 17, 17));
				g.fillRect(233, 261, complete * 3, 29);
				g.setColor(Color.WHITE);
				g.drawString("Downloading Game Pack - " + complete + '%' + " Complete", complete < 10 ? 257 : 253, 280);
				
				Thread.sleep(100);
			}

			g.setColor(new Color(140, 17, 17));
			g.fillRect(233, 261, 301, 29);
			g.setColor(Color.WHITE);
			g.drawString("Downloading Game Pack - 100% Complete", 250, 280);
		}
	}

	public void start() throws Exception
	{
		URL url[] = { 
			new File(directory.concat("/gamepack.jar")).toURI().toURL() 
		};
        
		URLClassLoader classLoader = new URLClassLoader(url);
        	applet = (Applet)classLoader.loadClass("client").newInstance(); 
		applet.setBounds(0, 26, 765, 503);
        
        	applet.setBackground(Color.BLACK);
		applet.setStub(stub);

        	applet.init();
        	applet.start();

		loadMenu();
		mainFrame.getContentPane().add(applet);
	}

	public void loadMenu()
	{
		JLabel bkg = getLoadingLabel("http://www.runescape.com/img/rsp777/gamewin/navbar.gif");
		bkg.setBounds(0, 0, bkg.getIcon().getIconWidth(), bkg.getIcon().getIconHeight());

		JLabel jagex = getLoadingLabel("http://www.runescape.com/img/rsp777/jagex_logo_79x21.png");
		jagex.setBounds(2, 2, jagex.getIcon().getIconWidth(), jagex.getIcon().getIconHeight());

		mainFrame.getContentPane().add(jagex);
		mainFrame.getContentPane().add(bkg);

		mainFrame.getContentPane().getComponent(0).repaint();
		mainFrame.getContentPane().getComponent(1).repaint();
	}

	public JLabel getLoadingLabel(String url)
	{
		JLabel label = new JLabel();
		try 
		{
			ImageIcon icon = new ImageIcon(new URL(url));
			icon.setImageObserver(null);
			label.setIcon(icon);
		} 
		catch (MalformedURLException mfurle) 
		{ 
			
		}
		return label;
	}

	private static AppletEnvironment grabParameters(int world) throws Exception
	{
		StringBuilder ws = new StringBuilder();
		ws.append("http://oldschool").append(world).append(".runescape.com/");

        	URL url = new URL(ws.toString());
		AppletEnvironment stub = new AppletEnvironment(url);

        	BufferedReader bufferedreader = new BufferedReader(new InputStreamReader(url.openStream()));

		char[] c = "document.write('<param name=".toCharArray();
		char[] a = "document.write('archive=".toCharArray();

		String s;
		while ((s = bufferedreader.readLine()) != null)
		{	
			int compare = -1;
			if (s.length() > c.length && (compare = compare(s, c)) != -1)
			{
				StringBuilder sb = new StringBuilder();
				while (true)
				{
					char part = s.charAt(++compare);
					if (part == '"')
						break;
					sb.append(part);
				}
				if (sb.length() > 0) 
				{
					String key = sb.toString();
					sb.setLength(0);
					compare += 8;
					while (true)
					{
						char part = s.charAt(++compare);
						if (part == '"')
							break;
						sb.append(part);
					}
					if (sb.length() > 0)
					{
						stub.put(key, sb.toString());
						continue;
					}
				}
			}
			if (s.length() > c.length && (compare = compare(s, a)) != -1)
			{
				StringBuilder sb = new StringBuilder();
				int begin = compare;
				String pack = s.substring(compare, s.length() - 3).trim();
				stub.put("archive", pack);
			}
		}
		return stub;
	}

	public static int compare(String s, char[] c)
	{
		int whitespace = 0;
		while (s.charAt(whitespace) == ' ')
			++whitespace;
		for (int i = 0; i < c.length; ++i)
		{
			if (s.charAt(whitespace + i) != c[i])
				return -1; 
		}
		return c.length + whitespace;
	}
}