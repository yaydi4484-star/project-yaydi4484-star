#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 1. Initialize l-Écran LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 2. Pins du Module TTP229
const int SCL_PIN = 12; 
const int SDO_PIN = 11; 

// 3. Pin du Buzzer Passif
const int BUZZER_PIN = 3;

// 4. Pins des LEDs colorés
const int LED_ORANGE_RED  = 4; // LED Rouge  -> Orange
const int LED_BANANE_YELLOW= 5; // LED Jaune  -> Banane
const int LED_POMME_GREEN   = 6; // LED Vert -> Pomme
const int LED_PATATE_BLUE   = 7; // LED Bleu  -> Patate
const int LED_CITRON_WHITE  = 8; // LED Blanc -> Citron

// 5. Les Fréquences (DO, RE, MI, FA, SOL)
const int NOTE_DO  = 261; 
const int NOTE_RE  = 294; 
const int NOTE_MI  = 329; 
const int NOTE_FA  = 349; 
const int NOTE_SOL = 392; 

void setup() {
  // Initialisation du LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  BIO-RESONANCE ");
  lcd.setCursor(0, 1);
  lcd.print("   SYNTHESIZER  ");
  delay(2000);
  lcd.clear();

  // Configuration TTP229
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDO_PIN, INPUT);
  digitalWrite(SCL_PIN, HIGH);

  // Configuration Buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  // Configuration des LEDs
  pinMode(LED_ORANGE_RED, OUTPUT);
  pinMode(LED_BANANE_YELLOW, OUTPUT);
  pinMode(LED_POMME_GREEN, OUTPUT);
  pinMode(LED_PATATE_BLUE, OUTPUT);
  pinMode(LED_CITRON_WHITE, OUTPUT);
}

void loop() {
  int touchedPin = readTTP229();

  // Reset de tous les LEDs et Buzzer
  digitalWrite(LED_ORANGE_RED, LOW);
  digitalWrite(LED_BANANE_YELLOW, LOW);
  digitalWrite(LED_POMME_GREEN, LOW);
  digitalWrite(LED_PATATE_BLUE, LOW);
  digitalWrite(LED_CITRON_WHITE, LOW);
  noTone(BUZZER_PIN);

  if (touchedPin != 0) {
    lcd.setCursor(0, 0);
    lcd.print("TOUCH DETECTED! ");
    
    switch (touchedPin) {
      case 1: // Touche 1 -> Orange
        lcd.setCursor(0, 1);
        lcd.print("DO  - ORANGE    ");
        digitalWrite(LED_ORANGE_RED, HIGH);
        tone(BUZZER_PIN, NOTE_DO);
        break;
        
      case 2: // Touche 2 -> Banane
        lcd.setCursor(0, 1);
        lcd.print("RE  - BANANE    ");
        digitalWrite(LED_BANANE_YELLOW, HIGH);
        tone(BUZZER_PIN, NOTE_RE);
        break;
        
      case 3: // Touche 3 -> Pomme
        lcd.setCursor(0, 1);
        lcd.print("MI  - POMME     ");
        digitalWrite(LED_POMME_GREEN, HIGH);
        tone(BUZZER_PIN, NOTE_MI);
        break;
        
      case 4: // Touche 4 -> Patate
        lcd.setCursor(0, 1);
        lcd.print("FA  - PATATE    ");
        digitalWrite(LED_PATATE_BLUE, HIGH);
        tone(BUZZER_PIN, NOTE_FA);
        break;
        
      case 5: // Touche 5 -> Citron
        lcd.setCursor(0, 1);
        lcd.print("SOL - CITRON    ");
        digitalWrite(LED_CITRON_WHITE, HIGH);
        tone(BUZZER_PIN, NOTE_SOL);
        break;
        
      default:
        break;
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print("READY TO PLAY... ");
    lcd.setCursor(0, 1);
    lcd.print("TOUCH ANY FRUIT ");
  }
  
  delay(100); 
}

// Fonction de lecture du TTP229
int readTTP229() {
  int touched = 0;
  for (int i = 1; i <= 16; i++) {
    digitalWrite(SCL_PIN, LOW);
    delayMicroseconds(2); 
    if (digitalRead(SDO_PIN) == LOW) {
      touched = i; 
    }
    digitalWrite(SCL_PIN, HIGH);
    delayMicroseconds(2);
  }
  return touched;
}
