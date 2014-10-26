//Inkludera externa instanser
extern LiquidCrystal lcd;

//Inkludera externa variabler
extern int lastColumn;
extern int lastLine;
extern int selval;

extern unsigned long time;
extern unsigned long printTime;

extern int printDelay;
extern int fpsTime;

extern int playerNum;
extern int firstRunTime;

extern int playerOneAttention;
extern int playerOneMeditation;
extern int playerTwoAttention;
extern int playerTwoMeditation;
extern int lapNumberOne;
extern int lapNumberTwo;

extern int winner;
extern int gameMode;
extern int gameStartTime;
extern int antalMinuter;



Draw::Draw()
{
	
}

//PRINT FUNCTION
void Draw::PrintLineColumnText(int line, int column, char* stringToPrint)
{
	lcd.setCursor(column,line);
	delay (printDelay);
	char *tmp = stringToPrint;
	lcd.print(tmp);
	delay (printDelay);
	while( *tmp != 0 )
	{
		tmp ++;
		column ++;
	}
	column = column + 1;
	lcd.setCursor(column,line);
	lastColumn = column;
	lastLine = line;
}



//ALL MENU FUNCTIONS
void Draw::DrawMainMenu()
{
	lcd.clear();
	lcd.setCursor(0,0);
	delay (printDelay);
	lcd.print ("Race");
	delay (printDelay);
	
	lcd.setCursor(5,0);
	delay (printDelay);
	lcd.print("Deathmatch");
	delay (printDelay);
	
	lcd.setCursor(0,1);
	lcd.print ("Time attack");
	delay (printDelay);
	
	lcd.setCursor(0,0);
	delay (printDelay);

	selval = 1;
}

void Draw::DrawRaceMenu()
{
	lcd.clear();
	lcd.setCursor(0,0);
	delay (printDelay);
	lcd.print("Players");
	delay (printDelay);
	lcd.setCursor(10,0);
	delay (printDelay);
	lcd.print("Laps");
	delay (printDelay);
	lcd.setCursor(0,1);
	delay (printDelay);
	lcd.print("1P   2P");
	delay (printDelay);
	lcd.setCursor(10,1);
	delay (printDelay);
	lcd.print("1");
	lcd.setCursor(0,1);
}

void Draw::DrawDeathmatchMenu()
{
	lcd.clear();
	PrintLineColumnText(0,0,"Mode");
	PrintLineColumnText(lastLine,lastColumn+1,"Trigger");

	PrintLineColumnText(1,0,"A");
	PrintLineColumnText(lastLine,lastColumn+1,"M");
	PrintLineColumnText(lastLine,lastColumn+1,"50");
	lcd.setCursor(0,1);
}

void Draw::DrawTimeattackMenu()
{
	lcd.clear();
	lcd.setCursor(0,0);
	delay (printDelay);
	lcd.print("Players");
	delay (printDelay);
	lcd.setCursor(10,0);
	delay (printDelay);
	lcd.print("Laps");
	delay (printDelay);
	lcd.setCursor(0,1);
	delay (printDelay);
	lcd.print("1P   2P");
	delay (printDelay);
	lcd.setCursor(10,1);
	delay (printDelay);
	lcd.print("1");
	lcd.setCursor(0,1);

	selval = 1;
}

void Draw::DrawQuitMenu()
{
	lcd.clear();
	lcd.setCursor(0,0);
	delay (printDelay);
	lcd.print ("Good bye!");
	delay (printDelay);
	lcd.setCursor(0,1);
	delay (printDelay*100);
	lcd.print ("little fucker");

	selval = 1;
}


//ALL GAME FUNCTIONS
void Draw::DrawRaceGame() //HÄR MÅSTE STYLING OCH KORRIGERING AV KOTINUERLIG UPPDATERING GÖRAS
{
	if (printTime < time)
	{
		printTime = time + fpsTime;
		
		if (playerNum == 1)
		{
			if (firstRunTime == 1)
			{
				lcd.noBlink();
				lcd.clear();
				
				PrintLineColumnText(0,0,"A-lap");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(lapNumberOne);
				PrintLineColumnText(lastLine,lastColumn+2,"M-lap");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(lapNumberTwo);

				PrintLineColumnText(1,0,"A");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(playerOneAttention);
				PrintLineColumnText(lastLine,lastColumn+6,"M");
				delay(printDelay);
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(playerOneMeditation);
				
				firstRunTime = 0;
			}
			
			if (playerOneAttention < 10)
			{
				PrintLineColumnText(1,3,"  ");
			}
			else if (playerOneAttention < 100)
			{
				PrintLineColumnText(1,4,"  ");
			}
			lcd.setCursor(2,1);
			delay(printDelay);
			lcd.print(playerOneAttention);	//TEMPORÄR
			
			if (playerOneMeditation < 10)
			{
				PrintLineColumnText(1,11,"  ");
			}
			else if (playerOneMeditation < 100)
			{
				PrintLineColumnText(1,12,"  ");
			}
			lcd.setCursor(10,1);
			delay(printDelay);
			lcd.print(playerOneMeditation);	//TEMPORÄR
			
		}
		else if (playerNum == 2)
		{
			if (firstRunTime == 1)
			{
				lcd.noBlink();
				lcd.clear();
				
				PrintLineColumnText(0,0,"P1lap");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(lapNumberOne);
				PrintLineColumnText(lastLine,lastColumn+2,"P2lap");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(lapNumberTwo);

				PrintLineColumnText(1,0,"A");
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(playerOneAttention);
				PrintLineColumnText(lastLine,lastColumn+6,"A");
				delay(printDelay);
				lcd.setCursor(lastColumn,lastLine);
				delay(printDelay);
				lcd.print(playerOneMeditation);
				
				firstRunTime = 0;
			}
		}
	}
}

void Draw::DrawDeathMatchGame()
{
	lcd.clear();
	PrintLineColumnText(0,0,"P1 Wins");
	lcd.setCursor(lastColumn,lastLine);
	delay(printDelay);
	lcd.print(lapNumberOne);
	PrintLineColumnText(1,0,"P2 Wins");
	lcd.setCursor(lastColumn,lastLine);
	delay(printDelay);
	lcd.print(lapNumberTwo);
	
	PrintLineColumnText(0,11,"Mode");
	if (gameMode == ATTENTION_GAME)
	{
		PrintLineColumnText(1,11,"A");
	}
	else if (gameMode == MEDITATION_GAME)
	{
		PrintLineColumnText(1,11,"M");
	}
}

void Draw::DrawTimeAttackGame() //hur skall den se ut för 1 resp 2 spelare? PROBLEM är inte gjord för spel längre än 10min för närvarande
{
	if (firstRunTime == 1)//Rita ut all grund-HUD
	{
		lcd.clear();
		
		gameStartTime = time/1000;
		firstRunTime = 0;
		
		PrintLineColumnText(0,0,"Att");
		PrintLineColumnText(lastLine,lastColumn,"Time");
		PrintLineColumnText(lastLine,lastColumn+1,"Med");
	}
	
	if (printTime < time)
	{
		printTime = time + fpsTime;
		int gameTime;
		
		
		//Print left column data
		if (playerOneAttention < 10)
		{
			PrintLineColumnText(1,1,"  ");
		}
		else if (playerOneAttention < 100)
		{
			PrintLineColumnText(1,2,"  ");
		}
		lcd.setCursor(0,1);
		delay(printDelay);
		lcd.print(playerOneAttention);	//TEMPORÄR
		
		
		//Print center column data
		if (antalMinuter == 0)
		{
			gameTime = (time/1000 - gameStartTime);
		}
		else
		{
			gameTime = ((time/1000 - gameStartTime) - antalMinuter*60);
		}
		
		if (gameTime < 60 && antalMinuter == 0)
		{
			lcd.setCursor(4,1);
			lcd.print(gameTime);
		}
		else if (gameTime == 60 && antalMinuter < 10)
		{
			antalMinuter++;
			gameTime = gameTime - 60;
			
			lcd.setCursor(4,1);
			lcd.print(antalMinuter);
			lcd.print("m");
			lcd.setCursor(6,1);
			lcd.print("  ");
		}
		else if (gameTime == 60 && antalMinuter >= 10)
		{
			antalMinuter++;
			gameTime = gameTime - 60;
			
			lcd.setCursor(4,1);
			lcd.print(antalMinuter);
			lcd.setCursor(6,1);
			lcd.print("m");
			lcd.setCursor(7,1);
			lcd.print("  ");
			lcd.setCursor(7,1);
			lcd.print(gameTime);
		}
		else if (antalMinuter > 0 && antalMinuter < 10)
		{
			lcd.setCursor(6,1);
			lcd.print(gameTime);
		}
		else if (antalMinuter >= 10)
		{
			lcd.setCursor(6,1);
			lcd.print("m");
			lcd.setCursor(7,1);
			lcd.print(gameTime);
		}
		
		
		
		//Print right column data
		
		if (playerOneMeditation < 10)
		{
			PrintLineColumnText(1,11,"  ");
		}
		else if (playerOneMeditation < 100)
		{
			PrintLineColumnText(1,12,"  ");
		}
		lcd.setCursor(10,1);
		delay(printDelay);
		lcd.print(playerOneMeditation);	//TEMPORÄR
		

	}
}

void Draw::PrintWinner()
{
	char *w;
	if (playerNum == 1)
	{
		lcd.clear();
		lcd.setCursor(0,0);
		delay (printDelay);
		lcd.print("Winner is");
		delay (printDelay);
		lcd.setCursor(0,1);
		if (winner == 1)
		{
			lcd.print("Attention");
		}
		if (winner == 2)
		{
			lcd.print("Meditation");
		}
	}
	if (playerNum == 2)
	{
		lcd.clear();
		lcd.setCursor(0,0);
		delay (printDelay);
		lcd.print("Winner is P");
		delay (printDelay);
		lcd.print(winner);
	}

}
