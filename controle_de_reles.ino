

// =============================================================================================================
// --- Protótipo das Funções ---
void relayActive(int relay_number);   //função para ativação do respectivo relé


// =============================================================================================================
// --- Variáveis Globais ---
int number ;


// =============================================================================================================
// --- Configurações Iniciais ---
void setup()
{
  Serial.begin(9600); //inicializa serial

  //Configura saída para relés a serem controlados no 16 Relay Module
  pinMode(11,  OUTPUT);  //Code 9
  pinMode(10,  OUTPUT);  //Code 8
  pinMode(9,  OUTPUT);  //Code 7
  pinMode(8,  OUTPUT);  //Code 6
  pinMode(7,  OUTPUT);  //Code 5
  pinMode(6,  OUTPUT);  //Code 4
  pinMode(5, OUTPUT);  //Code 3
  pinMode(4, OUTPUT);  //Code 2
  
  //Inicializa todas em LOW
  digitalWrite(4,  HIGH);
  digitalWrite(5,  HIGH);
  digitalWrite(6,  HIGH);
  digitalWrite(7,  HIGH);
  digitalWrite(8,  HIGH);
  digitalWrite(9,  HIGH);
  digitalWrite(10,  HIGH);
  digitalWrite(11,  HIGH);

   
} //end setup


// =============================================================================================================
// --- Loop Infinito ---
void loop()
{
 
  if (Serial.available()) 
  {

    //read serial as ascii integer
    int ser_n = Serial.read();
    //Print the value in the serial monitor
    Serial.println(ser_n);

     if(ser_n >= 48 && ser_n <= 57){    
      //The ascii equivilent of numbers 0 - 9 are 48 - 57
      // so subtracting 46 from the ascii gives us 2 - 12 (the pins we want to use)
      int number = ser_n - 46;

      relayActive(number);
     }

  }

}

void relayActive(int relay_number)
{
  
  digitalWrite(relay_number, !digitalRead(relay_number));
  
}
