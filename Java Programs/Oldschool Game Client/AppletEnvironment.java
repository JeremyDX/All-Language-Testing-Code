package com;

import java.util.Map;
import java.util.HashMap;
import java.net.URL;
import java.applet.AppletStub;
import java.applet.AppletContext;

public class AppletEnvironment implements AppletStub
{
	private final Map<String, String> PARAMETERS = new HashMap<String, String>();
	private final URL URLBASE;

	public AppletEnvironment(final URL URLBASE)
	{
		this.URLBASE = URLBASE;
	}

	public boolean put(String key, String param)
	{
		if (PARAMETERS.containsKey(key))
			return false;
		PARAMETERS.put(key, param);
		return true;
	}

	@Override
	public String getParameter(String name) 
	{
		return PARAMETERS.get(name);
	}

	@Override
	public URL getCodeBase() 
	{
		return URLBASE;
	}

	@Override
	public URL getDocumentBase() 
	{
		return URLBASE;
	}

	@Override
	public boolean isActive() 
	{
		return true;
	}

	@Override
	public AppletContext getAppletContext()
	{
		return null;
    	}

	@Override
	public void appletResize(int width, int height) 
	{

	}
}