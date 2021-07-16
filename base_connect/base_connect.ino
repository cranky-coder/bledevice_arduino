#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
 
byte switchPin = 2;
boolean switch_State = LOW;
boolean oldswitch_State = LOW;
 char c=' ';
void setup() 
{
    Serial.begin(9600);
    Serial.print("Sketch:   ");   Serial.println(__FILE__);
    Serial.print("Uploaded: ");   Serial.println(__DATE__);
    Serial.println(" ");
 
    BTserial.begin(9600);  
    Serial.println("BTserial started at 9600");
    Serial.println(" ");
 
    pinMode(switchPin, INPUT); 
 
    // connect to the remote Bluetooth module 
    BTserial.print("AT+IMME1" );
    delay(4000);    
    BTserial.print("AT+ROLE1" );
    delay(4000);
    BTserial.print("AT+CONN0" );
    delay(4000);
    BTserial.print("DeviceType;" );
    delay(4000);
}
 
void loop()
{
   if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
    }
}
