#ifndef HARestAPI_h
#define HARestAPI_h

#include <Arduino.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>

class HARestAPI
{
  public:
	/* Ask user to supply appropiate WiFiClient or WiFiClientSecure 
	HARestAPI(void);
	void useSSL(void);
	*/
	HARestAPI(WiFiClient &client);
	HARestAPI(WiFiClientSecure &client);
	void setHAServer(String);
	void setHAServer(String, uint16_t);
	void setHAServer(String, uint16_t, String);
	void setHAPassword(String);
	void setFingerPrint(String);
    void setRGB(uint8_t, uint8_t, uint8_t);
	void setDebugMode(bool);
	void setComponent(String);
	void setURL(String);
	bool sendCustomHAData(String, String);
	bool sendHA(void);
	bool sendHAURL(String);
	bool sendHAComponent(String);
	bool sendHAComponent(String, String);
	bool sendHARGBLight(void);
	bool sendHARGBLight(uint8_t, uint8_t, uint8_t);
	bool sendHARGBLight(String);
	bool sendHARGBLight(String, uint8_t, uint8_t, uint8_t);
	bool sendHALight(bool);
	bool sendHASwitch(bool);
	bool sendHALight(bool, String);
	bool sendHASwitch(bool, String);
	bool sendHAAutomation(bool);
	bool sendHAAutomation(bool, String);
	String sendGetHA(String, String);

  private:
    WiFiClient *wclient;
	WiFiClientSecure *wsclient;
	
	/* Ask user to supply appropiate WiFiClient or WiFiClientSecure 
	WiFiClient dwclient;
	WiFiClientSecure dwsclient;
	*/
	
	bool sendPostHA(String);
	bool sendPostHA(String, String);
	
    String 
	  _serverip,
	  _password,
	  _url = "/api/services/homeassistant/toggle",
	  _component,
	  _fingerprint;
	  
	uint8_t 
	  _red = 255,
	  _green = 255,
	  _blue = 255;
	  
	uint16_t
	  _port;
	
	bool
	  _passwordset = false,
	  _rgbset = false,
	  _debug = true,
	  _ssl = false;
};

#endif