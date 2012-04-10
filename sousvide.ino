/* YourDuino Electronic Brick Test
Temperature Sensor DS18B20
- Connect cable to Arduino Digital I/O Pin 2
terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <serLCD.h>
/*-----( Declare Constants )-----*/
#define ONE_WIRE_BUS 2 /*-(Connect to Pin 2 )-*/
#define POT_PIN    A0

/*-----( Declare objects )-----*/
/* Set up a oneWire instance to communicate with any OneWire device*/
OneWire ourWire(ONE_WIRE_BUS);

/* Tell Dallas Temperature Library to use oneWire Library */
DallasTemperature sensors(&ourWire);

/*-----( Declare Variables )-----*/
double pot_value;
double targetTemp;
serLCD lcd(3);

void setup() /*----( SETUP: RUNS ONCE )----*/
{
/*-(start serial port to see results )-*/
delay(1000);
lcd.begin(9600);
delay(1000);
pinMode(4,OUTPUT);
/*-( Start up the DallasTemperature library )-*/
sensors.begin();
}/*--(end setup )---*/


void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{
//lcd.clear();
lcd.setCursor(1,1);
sensors.requestTemperatures(); // Send the command to get temperatures
lcd.print("Current: ");
double currentTemp = sensors.getTempFByIndex(0);
lcd.print(currentTemp);
pot_value = analogRead(POT_PIN);
lcd.setCursor(2,1);
lcd.print("Target: ");
lcd.setCursor(2,10);
lcd.print("    ");
lcd.setCursor(2,10);
lcd.print(((pot_value/1023)*100)+100);
double targetTemp = ((pot_value/1023)*100)+100;
lcd.print(targetTemp);
if(
}/* --(end main loop )-- */

/* ( THE END ) */
