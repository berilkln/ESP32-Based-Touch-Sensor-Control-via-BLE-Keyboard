#include <BleKeyboard.h>

// Bluetooth HID keyboard object
BleKeyboard bleKeyboard("ESP32 Keyboard");

// Touch pin definitions (GPIO pins for analog sensors)
#define TOUCH_PIN_A 4  
#define TOUCH_PIN_B 34 
#define TOUCH_PIN_C 33 
#define TOUCH_PIN_D 35 
#define TOUCH_PIN_E 26 

// Touch sensor thresholds
#define TOUCH_THRESHOLD 4095 // Threshold value (highest value of touch sensors)
#define DEBOUNCE_DELAY 1000   // Delay time (ms)

unsigned long lastTouchTimeA = 0;
unsigned long lastTouchTimeB = 0;
unsigned long lastTouchTimeC = 0;
unsigned long lastTouchTimeD = 0;
unsigned long lastTouchTimeE = 0;

void setup() {
  Serial.begin(115200);

  // BLE keyboard initiation
  bleKeyboard.begin();
  Serial.println("BLE Keyboard started.");

  // Pin configuration for touch sensors
  pinMode(TOUCH_PIN_A, INPUT);
  pinMode(TOUCH_PIN_B, INPUT);
  pinMode(TOUCH_PIN_C, INPUT);
  pinMode(TOUCH_PIN_D, INPUT);
  pinMode(TOUCH_PIN_E, INPUT);
}

void loop() {
  // Bluetooth keyboard connection control
  if (bleKeyboard.isConnected()) {
    // Read values ​​from touch sensors
    int touchValueA = analogRead(TOUCH_PIN_A);
    int touchValueB = analogRead(TOUCH_PIN_B);
    int touchValueC = analogRead(TOUCH_PIN_C);
    int touchValueD = analogRead(TOUCH_PIN_D);
    int touchValueE = analogRead(TOUCH_PIN_E);

    // Print values ​​of touch sensors on serial monitor
    Serial.print("Dokunmatik A: ");
    Serial.println(touchValueA);
    Serial.print("Dokunmatik B: ");
    Serial.println(touchValueB);
    Serial.print("Dokunmatik C: ");
    Serial.println(touchValueC);
    Serial.print("Dokunmatik D: ");
    Serial.println(touchValueD);
    Serial.print("Dokunmatik E: ");
    Serial.println(touchValueE);

    // If sensor A is touched (touchValueA equals 4095)
    if (touchValueA == TOUCH_THRESHOLD && (millis() - lastTouchTimeA > DEBOUNCE_DELAY)) {
      // Press Ctrl + Right Arrow
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_RIGHT_ARROW);  
      bleKeyboard.releaseAll();
      Serial.println("Ctrl + Right Arrow was pressed.");
      lastTouchTimeA = millis(); // Update last touch time
    }

    // If sensor B is touched (touchValueB equals 4095)
    if (touchValueB == TOUCH_THRESHOLD && (millis() - lastTouchTimeB > DEBOUNCE_DELAY)) {
      // Press Ctrl + Left Arrow
      bleKeyboard.press(KEY_LEFT_CTRL);
      bleKeyboard.press(KEY_LEFT_ARROW); 
      bleKeyboard.releaseAll();
      Serial.println("Ctrl + Left Arrow was pressed.");
      lastTouchTimeB = millis(); // Update last touch time
    }

    // If sensor C is touched (touchValueC equals 4095)
    if (touchValueC == TOUCH_THRESHOLD && (millis() - lastTouchTimeC > DEBOUNCE_DELAY)) {
      // Press Spacebar
      bleKeyboard.press(' '); 
      bleKeyboard.releaseAll();
      Serial.println("The Space key was pressed.");
      lastTouchTimeC = millis(); // Update last touch time
    }

    // If sensor D is touched (touchValueD equals 4095)
    if (touchValueD == TOUCH_THRESHOLD && (millis() - lastTouchTimeD > DEBOUNCE_DELAY)) {
      // Press Volume Down 
      bleKeyboard.press(KEY_MEDIA_VOLUME_DOWN);
      bleKeyboard.releaseAll();
      Serial.println("The Volume Down button was pressed.");
      lastTouchTimeD = millis(); // Update last touch time
    }

    // If sensor E is touched (touchValueE equals 4095)
    if (touchValueE == TOUCH_THRESHOLD && (millis() - lastTouchTimeE > DEBOUNCE_DELAY)) {
      // Press Volume Up
      bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
      bleKeyboard.releaseAll();
      Serial.println("The Volume Up button was pressed.");
      lastTouchTimeE = millis(); // Update last touch time
    }

  } else {
    Serial.println("Waiting for Bluetooth keyboard connection...");
    delay(1000); // Delay while waiting for connection
  }

  delay(100); // Loop Delay
}
