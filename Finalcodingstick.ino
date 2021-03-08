#define trigPin1 13
#define echoPin1 12
#define trigPin2 3
#define echoPin2 4
#define trigPin3 6
#define echoPin3 7
#define motor 8
#define buzzer1 5
#define buzzer2 2

long duration,distance1;
long distance2;
long distance3;

void setup()
{ 
pinMode(trigPin1, OUTPUT);//OUTPUT PIN(TRIG)COMM WITH BOARD ,SENDS INFO FROM ECHOPIN TO ARDUINO PIN//
pinMode(echoPin1, INPUT);//INPUT PIN(SENDS AND RECIEVES SIG)//
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(motor, OUTPUT);
pinMode(buzzer1,OUTPUT);
pinMode(buzzer2,OUTPUT);
}

void loop()
{ 

digitalWrite(trigPin1, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin1, LOW);

duration = pulseIn(echoPin1, HIGH);//RETURNS TIME IN MICROSEC//
distance1 = (duration/2) * 0.0343;//SPEED OF SOUND


digitalWrite(trigPin2, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin2, LOW);

duration = pulseIn(echoPin2, HIGH);
distance2 = (duration/2) * 0.0343;


digitalWrite(trigPin3, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin3, LOW);

duration = pulseIn(echoPin3, HIGH);
distance3 = (duration/2) * 0.0343;

if (distance1 + distance2 + distance3 < 200) // Checking the distance, you can change the value
{ 
digitalWrite(buzzer1,HIGH);
} else if(distance1 + distance2 + distance3 < 100) 
{
digitalWrite(buzzer1,HIGH);
digitalWrite(buzzer2, HIGH); 
} else if(distance1 + distance2 + distance3 < 50)
{
digitalWrite(buzzer1,HIGH);
digitalWrite(buzzer2, HIGH); 
digitalWrite(motor, HIGH);
}
}
