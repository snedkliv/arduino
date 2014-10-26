#include "Arduino.h"

#include <LiquidCrystal.h>
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Draw.h"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Draw.cpp"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Menu.h"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Menu.cpp"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Communication.h"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Communication.cpp"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Games.h"
#include "C:\Users\Sn\Documents\GitHub\Arduino\libraries\Bilbana\Games.cpp"

//Skapa instanser
Draw DrawGraphics;
Menu MenuNavigation;
Communication Update;
Games Game = Games();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//KNAPPAR
//Digitala
const int nextPin = 8;
const int selectPin = 7;
const int quitPin = 95;
const int lapPinOne = 9192328;
const int lapPinTwo = 992321328;

//States
int nextState = 0;
int selectState = 0;
//int quitState = 0;
int lapStateOne = 0;
int lapStateTwo = 0;

int prevLapStateOne = 0;
int prevLapStateTwo = 0;

//TIMERS
unsigned long time;
unsigned long breakTime = 0;
unsigned long printTime = 0;

//Variabler som ändras i koden
int selval = 1;					//Används för menynavigering
int running = 0;				//Används av spel (1 då spel körs)
int winner = 99;				//Identifierar vilken vinnaren är för funktionen DrawGraphics.PrintWinner();

int gameMode = 0;				//Parameter som väljs ur menyn eller togglas då switchState==HÖG (Förutom i singleplayer race)
int playerNum = 0;				//Parameter som väljs ur menyn och används för att anropa spelfunktioner
int numberOfLaps = 0;			//Parameter som väljs ur menyn och används för att anropa spelfunktioner
int triggerLevel = 0;			//Parameter som väljs ur menyn och används för att anropa spelfunktioner


int lapNumberOne = 0;			//Varvnummer för spelare 1
int lapNumberTwo = 0;			//Varvnummer för spelare 2
int timeOneStart = 0;			//Tid då spelare 1 startar ett nytt varv
int timeTwoStart = 0;			//Tid då spelare 2 startar ett nytt varv

const int playerOneThrottlePin = 6; //TEMP 
const int playerTwoThrottlePin = 9; //TEMP 


int playerOneAttention = 0;
int playerTwoAttention = 0;
int playerOneMeditation = 0;
int playerTwoMeditation = 0;


int lastColumn, lastLine;		//Används för att enklare kunna anropa funktionen DrawGraphics.PrintLineColumnText();

String dataIdentifier;			//Identifierar datatyp vid seriell överföring

//Inställnings-variabler
int buttPress = 350;			//Antal ms som minst måste passera mellan knapptryckningar
int printDelay = 35;			//Antal ms som pausas i print-funktionen DrawGraphics.PrintLineColumnText(); för att säkerställa korrekt LCD-återgivning
int gameDrawFPS = 10;			//Den högsta frame-raten som tillåts skrivas ut (används hittils bara för klockan i time-attack)
int maximumSerialBuffer = 40;	//Maximalt antal bytes som tillåts i Seriebufferten (max är 63, för högt ger delay)
int lowSerialBuffer = 10;		//Antalet bytes som lämnas i bufferten då antal bytes i bufferten överstigit maximumSerialBuffer 

//Osnyggare variabler
int firstRunTime = 1;	
int gameStartTime = 0;
int antalMinuter = 0;
int fpsTime = 1000*(1/gameDrawFPS);




void setup()
{
	//Initialisera LCD-display
	lcd.begin(16,2);						
	lcd.blink();
  
	//Initialisera ingångar och utgångar
	pinMode(nextPin, INPUT);
	pinMode(selectPin, INPUT);
	//pinMode(quitPin, INPUT);
	pinMode(lapPinOne, INPUT);
	pinMode(lapPinTwo, INPUT);
  
	//Starta seriekommunikation
	Serial.begin(9600);

	//Anropa grundmenyn
	MenuNavigation.MainMenu();
}

void loop ()
{
	
}
