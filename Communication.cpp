//Inkludera externa variabler
extern const int nextPin;
extern const int selectPin;
extern const int playerOneThrottlePin;
extern const int playerTwoThrottlePin;

extern int maximumSerialBuffer;
extern int lowSerialBuffer;

extern unsigned long time;

Communication::Communication()
{
	
}

void Communication::UpdateMenuInputs()
{
	nextState = digitalRead(nextPin);
	selectState = digitalRead(selectPin);
	//quitState = digitalRead(quitPin);
	time = millis();
}

void Communication::UpdateGameInputs()
{
	nextState = digitalRead(nextPin);
	selectState = digitalRead(selectPin);
	//lapStateOne = digitalRead(lapPinOne);
	//lapStateTwo = digitalRead(lapPinTwo);
	//quitState = digitalRead(quitPin);
	time = millis();
	
	//BLUETOOTH IMPORT
	GetPlayerStates();
}

void Communication::GetPlayerStates() //TEMPORÄR FÖR BUGGTEST GÖR MYCKET BÄTTRE KOD.....KOM IHÅG GLOBAL STRÄNG
{

	if(Serial.available())
	{
		if (Serial.available() >= maximumSerialBuffer)
		{
			while (Serial.available() > lowSerialBuffer)
			{
				Serial.read();
			} 
		}
		
		char firstChar = Serial.read();
		
		if (firstChar == 'a')
		{
			playerOneAttention = Serial.parseInt();
		}
		else if (firstChar == 'm')
		{
			playerOneMeditation = Serial.parseInt();
		}
		else if (firstChar == 'b')
		{
			playerTwoAttention = Serial.parseInt();
		}
		else if (firstChar == 'n')
		{
			playerTwoMeditation = Serial.parseInt();
		}
	}
}

void Communication::UpdateGameOutputs()
{
	
	
	// 		if (gameMode == SINGLE_PLAYER)
	// 		{
	// 			playerOneAttentionThrottle = map(playerOneAttention, 0,100,0,255);
	// 			playerOneMeditationThrottle = map(playerOneMeditation, 0,100,0,255);
	//
	// 			analogWrite(playerOneThrottlePin,playerOneAttentionThrottle);
	// 			analogWrite(playerTwoThrottlePin,playerOneMeditationThrottle);
	// 		}
	
	// 		if (gameMode == ATTENTION_GAME)
	// 		{
	// 			int playerOneAttentionThrottle = map(playerOneAttention, 0,100,0,255);
	// 			int playerTwoAttentionThrottle = map(playerTwoAttention, 0,100,0,255);
	//
	// 			analogWrite(playerOneThrottlePin,playerOneAttentionThrottle);
	// 			analogWrite(playerTwoThrottlePin,playerTwoAttentionThrottle);
	// 		}
	// 		if (gameMode == MEDITATION_GAME)
	// 		{
	// 			int playerOneMeditationThrottle = map(playerOneMeditation, 0,100,0,255);
	// 			int playerTwoMeditationThrottle = map(playerTwoMeditation, 0,100,0,255);
	//
	// 			analogWrite(playerOneThrottlePin,playerOneMeditationThrottle);
	// 			analogWrite(playerTwoThrottlePin,playerTwoMeditationThrottle);
	// 		}
	
	int playerOneAttentionThrottle = map(playerOneAttention, 0,100,0,255);
	int playerOneMeditationThrottle = map(playerOneMeditation, 0,100,0,255);
	
	analogWrite(playerOneThrottlePin,playerOneAttentionThrottle);
	analogWrite(playerTwoThrottlePin,playerOneMeditationThrottle);

}
