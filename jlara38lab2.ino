
/*
  1. Name: Jose Lara - 664072746

  2. Lab: Lab 2 - The LCD 

  3. The code is meant to simulate a racing game using the LCD screen and accomodates 2 players.

  4. 
    LCD RS pin to digital pin 12 (This controls the place we are writing data to for the LCD screen,
    which tells the LCD what to display.)

    LCD Enable Pin to digital pin 11 (This enables the writing to registers)

    LCD D4 pin to digital pin 5 (These are the states of the pins that get written into memory these are inputs)

    LCD D5 pin to digital pin 4 (These are the states of the pins that get written into memory these are inputs)

    LCD D6 pin to digital pin 3 (These are the states of the pins that get written into memory these are inputs)

    LCD D7 pin to digital pin 2 (These are the states of the pins that get written into memory these are inputs)

    LCD R/W pin to GND  (These are the read and write pins depending on the mode for the LCD screen)

    LCD VSS(GND) pin to GND 
    LCD VCC pin to 5V (feed power)
    LCD A pin to 5V (feed power)
    LCD K pin to GND 

    Pin 7 - is for my button which is an input device.

    pin 10 - is for my button which is an input device.

    
  5. References: 
    https://docs.arduino.cc/learn/electronics/lcd-displays
    https://docs.arduino.cc/built-in-examples/digital/StateChangeDetection
    https://www.arduino.cc/reference/en/libraries/liquidcrystal/

  6. In-Person Demonstration, Michael - 2/4/23, 9:46AM 
*/
#include <LiquidCrystal.h>

// These set up the pin that are gonna be used by the buttons and LCD screen.
// There are also some variables that will be used to make sure the race works properly.

int rs = 12;
int en = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

const int buttonPinOne = 10;
const int buttonPinTwo = 7;

int buttonNewOne;
int buttonOldOne = 1;

int buttonNewTwo;
int buttonOldTwo = 1;

int raceStart = 0;
int raceEnd = 0;

int racerOnePos = 0;
int racerTwoPos = 0;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

// This sets up the lcd screen and the beginning message

void setup() {
  pinMode(buttonPinOne, INPUT);
  pinMode(buttonPinTwo, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(String("Player One (1)"));
  lcd.setCursor(0,1);
  lcd.print(String("Player Two (2)"));

  Serial.begin(9600);
}

void loop() {

  // Reads input on buttons
  buttonNewOne = digitalRead(buttonPinOne);
  buttonNewTwo = digitalRead(buttonPinTwo);

  lcd.setCursor(0, 0);

  // This nested if else statements check if p1 or p2 start the race 
  // and if so it clears the screen and then displays both players in the race.
  if(buttonNewOne == 1 && buttonOldOne == 0 && raceStart == 0 && raceEnd == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String("1"));
    lcd.setCursor(0,1);
    lcd.print(String("2"));
    raceStart = 1;
  } else if (buttonNewTwo == 1 && buttonOldOne == 0 && raceStart == 0 && raceEnd == 0) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String("1"));
    lcd.setCursor(0,1);
    lcd.print(String("2"));
    raceStart = 1;
  }

  // This nested if statement just goes out of its way to make the movement and check the lap that both racers are in. 
  // The movement in question is in regards to p1 but takes into account the positions of p1 and p2.
  if(buttonNewOne == 1 && buttonOldOne == 0 && raceStart == 1 && raceEnd == 0) {
    lcd.clear();
    lcd.setCursor(racerOnePos, 0);
    lcd.print(String("1"));
    lcd.setCursor(racerTwoPos, 1);
    lcd.print(String("2"));
  

    if(racerOnePos >= 16 && racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16, 1);
      lcd.print(String("2"));
    } else if (racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16 , 1);
      lcd.print(String("2"));
    } else if (racerOnePos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos, 1);
      lcd.print(String("2"));
    }
    else if(racerOnePos == racerTwoPos && racerOnePos >= 16 && racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16, 1);
      lcd.print(String("2"));
    }
    racerOnePos++;
  }


// This nested if statement just goes out of its way to make the movement and check the lap that both racers are in. 
// The movement in question is in regards to p2 but takes into account the positions of p1 and p2.
if(buttonNewTwo == 1 && buttonOldTwo == 0 && raceStart == 1 && raceEnd == 0) {
    lcd.clear();
    lcd.setCursor(racerOnePos, 0);
    lcd.print(String("1"));
    lcd.setCursor(racerTwoPos, 1);
    lcd.print(String("2"));
    
    if(racerOnePos >= 16 && racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16, 1);
      lcd.print(String("2"));
    //racerTwoPos++;
    } else if (racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16 , 1);
      lcd.print(String("2"));
    } else if (racerOnePos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16, 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos, 1);
      lcd.print(String(2));
    }
    else if(racerOnePos == racerTwoPos && racerOnePos >= 16 && racerTwoPos >= 16) {
      lcd.clear();
      lcd.setCursor(15, 0);
      lcd.print(String("#"));
      lcd.setCursor(15, 1);
      lcd.print(String("#"));
      lcd.setCursor(racerOnePos - 16 , 0);
      lcd.print(String("1"));
      lcd.setCursor(racerTwoPos - 16 , 1);
      lcd.print(String("2"));
    }
    racerTwoPos++;
  }

  // This if else statement just checks if player one or player two wins
  if(racerOnePos == 31) {
    lcd.clear();
    raceEnd = 1;
    lcd.print("Player One wins!");
  } else if(racerTwoPos == 31) {
    lcd.clear();
    raceEnd = 1;
    lcd.print("Player Two wins!");
  }
  
  // This if statement sends us back to intro screen and resets the race after the player win screen. Allows us to replay again.
  if(raceEnd == 1) {
    delay(1000);

    lcd.clear();

    delay(500);
    
    lcd.setCursor(0,0);
    lcd.print(String("Player One (1)"));
    lcd.setCursor(0,1);
    lcd.print(String("Player Two (2)"));
    
    raceStart = 0;
    raceEnd = 0;
    racerOnePos = 0;
    racerTwoPos = 0;
  }

  buttonOldOne = buttonNewOne;
  buttonOldTwo = buttonNewTwo;    
  //delay(200);

}