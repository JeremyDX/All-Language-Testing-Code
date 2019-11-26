package com;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		try {
			Game game = new Game();
			game.getInsets();
			game.createLoadingScreen();
			game.downloadGamePack(30);
			game.start();
		} catch (Exception e) { e.printStackTrace(); }
	}
}