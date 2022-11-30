#include"MORSE.h"

int pin = 13;

void dot(){
  digitalWrite(pin,HIGH);
  millis();
  Serial.println(".");
  }

void dash (){
  digitalWrite(pin,LOW);
  3*millis();
  Serial.println("-");
}

void erreur() {
  digitalWrite(pin,HIGH);
  millis();
  Serial.println("");
}



// On définit le constructeur meme s'il n y a rien dedans.
unsigned long ChronoTemp =0;
unsigned long DureeTemp = 1000; // en ms

Morse::Morse(){
}

// first : on traduit les lettres individuellement en clignotement.
// ma classe ne contion que la fonction void morse chargée de traduire les lettres en clignotement.
 // En morse 3*t representera la durée longue et t la courte.pinMode(pin,OUTPUT); // on définit le pin 13 en OUTPUT.

void Morse::morse(char ch){
   if(ch=='a')
  {
    dot();
    dash();
  }
  else if(ch=='b')
  {
    dash();
    dot();
    dot();
    dot();
  }
  else if(ch=='c')
  {
    dash();
    dot();
    dash();
    dot();
  
  }
  else if(ch=='d')
  {
    dash();
    dot();
    dot();
 
  }
  else if(ch=='e')
  {
    dot();
  }
  else if(ch=='f')
  {
    dot();
    dot();
    dash();
    dot();
  }
  else if(ch=='g')
  {
    dash();
    dash();
    dot();
  }
  else if(ch=='h')
  {
    dot();
    dot();
    dot();
    dot();
  }
  else if(ch=='i')
  {
    dot();
    dot();
  }
  else if(ch=='j')
  {
    dot();
    dash();
    dash();
    dash();
  }
  else if(ch=='k')
  {
    dash();
    dot();
    dash();
  }
  else if(ch=='l')
  {
    dot();
    dash();
    dot();
    dot();
  }
  else if(ch=='m')
  {
    dash();
    dash();
  }
  else if(ch=='n')
  {
    dash();
    dot();
  }
  else if(ch=='o')
  {
    dash();
    dash();
    dash();
  }
  else if(ch=='p')
  {
    dot();
    dash();
    dash();
    dot();
  }
  else if(ch=='q')
  {
  dash();
  dash();
  dot();
  dash();
  }
  else if(ch=='r')
  {
   dot();
   dash();
   dot();
  }
  else if(ch=='s')
  {
    dot();
    dot();
    dot();  
  }
  else if(ch=='t')
  {
    dash();
  }
  else if(ch=='u')
  {
   dot();
   dot();
   dash();
  }
  else if(ch=='v')
  {
   dot();
   dot();
   dot();
   dash();
  }
  else if(ch=='w')
  {
   dot();
   dash();
   dash();
  }
  else if(ch=='x')
  {
    dash();
    dot();
    dot();
    dash();
  }
  else if(ch=='y')
  {
   dash();
   dot();
   dash();
   dash();
  }
  else if(ch=='z')
  {
  dash();
  dash();
  dot();
  dot();
  }
  else if (ch=='0')
  {
    dash();
    dash();
    dash();
    dash();
    dash();
  }
  else if (ch=='1')
  {
    dot();
    dash();
    dash();
    dash();
    dash();
  }
  else if (ch=='2')
  {
    dot();
    dot();
    dash();
    dash();
    dash();
  }
  else if (ch=='3')
  {
    dot();
    dot();
    dot();
    dash();
    dash();
  }
  else if (ch=='4')
  {
    dot();
    dot();
    dot();
    dot();
    dash();
  }
  else if (ch=='5')
  {
    dot();
    dot();
    dot();
    dot();
    dot();
  }
  else if (ch=='6')
  {
    dash();
    dot();
    dot();
    dot();
    dot();
  }
  else if (ch=='7')
  {
    dash();
    dash();
    dot();
    dot();
    dot();
  }
  else if (ch=='8')
  {
    dash();
    dash();
    dash();
    dot();
    dot();
  }
  else if (ch=='9')
  {
    dash();
    dash();
    dash();
    dash();
    dot();
  }
  else
  {
    erreur();
  }
}

Morse lm;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);  // Baudrate.
    pinMode(pin,OUTPUT); // on définit le pin 13 en OUTPUT.
    int temps=millis();
    int temps_1=500;
          while (millis()<temps - temps_1) {
          return 0;
          }
  }

void loop() {
     // put your main code here, to run repeatedly:
     
    String message = "hello"; // test de la convertion du mot hello en morse.
            
            if (message.length () > 0){   //lire le dernier charachtère stocké. 
                  Serial.println(message);
                  char emplacement;
                     for (int i=0; i< message.length() ; i++){
                         emplacement = message.charAt(i); // accéder à l'emplacement d'un string.
                         Serial.println(emplacement);
                          lm.morse(emplacement);
                         
                        }
                }
}
