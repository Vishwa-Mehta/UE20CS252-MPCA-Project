#include <Servo.h>
#include <Keypad.h> //correct: 8,A, *,6
Servo myservo;// interchange 5 and 9, 2 and C , 7 and 0, 1 and D , B and 3, # and 4
char* password = "888"; // change the password here, just pick any 3 numbers
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
//byte rowPins[ROWS] = { 8, 0, 6, 5 };
//byte colPins[COLS] = { 9, '#', 'B', 'C' };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12;
int GreenpinUnlock = 13;
void setup()
{
  pinMode(13,OUTPUT);
myservo.attach(11);
LockedPosition(true);
}
void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
}
if (key == password[position])
{
position ++;
}
if (position == 3)
{
LockedPosition(false);
}
    delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
//digitalWrite(RedpinLock, HIGH); //OG VERSION
//digitalWrite(GreenpinUnlock, LOW);
digitalWrite(RedpinLock, LOW);
digitalWrite(GreenpinUnlock, HIGH);
myservo.write(11);
}
//else
//{
//digitalWrite(RedpinLock, HIGH); //OG VERSION LOW
//digitalWrite(GreenpinUnlock, LOW); //OG VERSION HIGH
//myservo.write(90);
//}
else{
digitalWrite(RedpinLock, LOW); //OG VERSION LOW
digitalWrite(GreenpinUnlock, LOW); //OG VERSION HIGH
myservo.write(90);
}
}
