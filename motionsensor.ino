//Variables
int pirPin = 7;
int pirStatus = 0;
String Motion = "0";
void setup()
{
    Serial.begin(9600);
    pinMode(pirPin, INPUT); 
}

void loop()
{
    pirStatus = digitalRead(pirPin); 
    if(pirStatus == HIGH){
        Motion = "1";
        //Publish data so that we can see when there is movement.
        Particle.publish("Motion DETECTED", Motion, PRIVATE);
    }
    Motion = "0";
    Particle.publish("Motion NOT DETECTED", Motion, PRIVATE);
    delay(1000); //Delay 1 sec.
}