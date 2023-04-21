#include <Servo.h>
#include <Keypad.h>
Servo ServoMotor;
char* password = "888";
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
{'D','C','B','A'},
{'#','9','6','3'},
{'0','8','5','2'},
{'*','7','4','1'}
};
byte rowPins[ROWS] = { 8, 7, 6, 9 }; //correct
byte colPins[COLS] = { 5, 4, 3, 2 };//correct

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12;
int GreenpinUnlock = 13;

void setup()
{
  ServoMotor.attach(11);
  LockedPosition(true);

  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Turn builtin LED off
  digitalWrite(LED_BUILTIN, LOW);

}

//void loop()
//{
//  if(digitalRead(8) == HIGH) {
//    digitalWrite(LED_BUILTIN, HIGH);
//    LockedPosition(false);
//  } 
//  else {
//    digitalWrite(LED_BUILTIN, LOW);
//    LockedPosition(true);
//  }
//  
//char key = keypad.getKey();
//if (key == '*' || key == '#')
//{
//position = 0;
//LockedPosition(true);
//}
//if (key == password[position])
//{
//position ++;
//}
//if (position == 3)
//{
//LockedPosition(false);
//}
//    delay(100);
//}

void loop(){
  char key = keypad.getKey();
if (key == '*' || key == '#' || digitalRead(8) == LOW)
{
position = 0;
LockedPosition(true);
    digitalWrite(LED_BUILTIN, LOW);
    LockedPosition(true);
}
 if (key == password[position])
{
position ++;
}

if (position == 3 || digitalRead(8) == HIGH)
{
  digitalWrite(LED_BUILTIN, HIGH);
LockedPosition(false);
}
  }
void LockedPosition(int locked)
{
if (locked)
{

ServoMotor.write(11);
delay(2000);
}
else
{
ServoMotor.write(90);
delay(2000);
}
}
