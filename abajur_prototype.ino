#define ANALOG_LDR_PIN 0
#define DIGITAL_PIR_PIN 2
#define DIGITAL_BUTTON_PIN 4
int ldr = 0;
int pir = LOW;
int btn = LOW;
int is_on = 0;
int count = 0;
 
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(DIGITAL_PIR_PIN, INPUT);
  pinMode(DIGITAL_BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  btn = digitalRead(DIGITAL_BUTTON_PIN);

  if (btn == HIGH)
  {
    if (is_on == 0)
    {
      is_on = 1;
      verifyPIRAndLDR();
    } else {
      is_on = 0;
      verifyPIRAndLDR();
    }
  }

  if (is_on == 1) {
    count++;
  }
  
  if (count >= 100)
  {
    verifyPIRAndLDR();
  }

  Serial.println(ldr);
  Serial.println(pir);
  Serial.println(btn);
  Serial.println(count);
}

void verifyPIRAndLDR()
{
  count = 0;
  ldr = analogRead(ANALOG_LDR_PIN);
  pir = digitalRead(DIGITAL_PIR_PIN);
  if (is_on == 1 and ldr >= 800 and pir == HIGH) 
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

