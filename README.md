# ESP32-Based-Touch-Sensor-Control-for-Spotify-via-BLE-Keyboard
### 1 Introduction
This project demonstrates how to use an ESP32 microcontroller with BLE HID functionality and touch sensors to control
the Spotify application. The system includes five touch sensors configured to trigger specific key combinations when
touched. The key combinations emulate media control actions such as:

- **Next Song:** Ctrl + Right Arrow
- **Previous Song:** Ctrl + Left Arrow
- **Play/Pause:** Spacebar
- **Volume Up:** Media Volume Up
- **Volume Down:** Media Volume Down
  
This integration allows seamless control of Spotify via Bluetooth.

### 2 Project Objectives
The primary goals of this project are:
- To implement touch-based input for media control actions.
- To utilize the ESP32’s BLE Keyboard feature for seamless Bluetooth communication.
- To enhance the user experience by eliminating the need for conventional input devices.
### 3 Hardware Requirements
The project utilizes the following components:
- **ESP32 Microcontroller:** Acts as the central processing and BLE HID device.
- **Touch Sensors:** Five touch-sensitive inputs mapped to specific actions.
- **Power Source:** USB or battery supply for the ESP32.

### 4 Software and Libraries
The project employs:
- **Arduino IDE:** For writing and uploading the code.
- **BleKeyboard Library:** Enables BLE HID functionality for simulating keypresses.
  
The BleKeyboard library allows the ESP32 to act as a Bluetooth keyboard, sending keypress signals to connected
devices.

### 5 Implementation Details
#### 5.1 Pin Configuration
Each touch sensor is connected to a specific GPIO pin on the ESP32. Below is the pin mapping:

Sensor Action GPIO Pin Key Combination
Next Song 4 Ctrl + Right Arrow
Previous Song 34 Ctrl + Left Arrow
Play/ Pause 33 Spacebar
Volume Down 35 Media Volume
Down
Volume Up 26 Media Volume Up

#### 5.2 Code Implementation
The Arduino code includes configurations for the touch sensors, BLE HID initialization, and debounce mechanisms to
prevent multiple triggers. Below are snippets demonstrating key functionality:
- Skipping to the Next Song
```
if (touchValueA == TOUCH_THRESHOLD && (millis() - lastTouchTimeA > DEBOUNCE_DELAY)) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_RIGHT_ARROW);
    bleKeyboard.releaseAll();
    Serial.println("Ctrl + Sağ Ok basıldı.");
    lastTouchTimeA = millis();
}
```
- Going Back to the Previous Song
```
if (touchValueB == TOUCH_THRESHOLD && (millis() - lastTouchTimeB > DEBOUNCE_DELAY)) {
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ARROW);
    bleKeyboard.releaseAll();
    Serial.println("Ctrl + Sol Ok basıldı.");
    lastTouchTimeB = millis();
}
```
- Pausing/Resuming the Song
```
if (touchValueC == TOUCH_THRESHOLD && (millis() - lastTouchTimeC > DEBOUNCE_DELAY)) {
    bleKeyboard.press(' ');
    bleKeyboard.releaseAll();
    Serial.println("Space tuşuna basıldı.");
    lastTouchTimeC = millis();
}
```
- Volume Down Control
```
if (touchValueD == TOUCH_THRESHOLD && (millis() - lastTouchTimeD > DEBOUNCE_DELAY)) {
    bleKeyboard.press(KEY_MEDIA_VOLUME_DOWN);
    bleKeyboard.releaseAll();
    Serial.println("Ses kısma (Volume Down) tuşuna basıldı.");
    lastTouchTimeD = millis();
}
```

- Volume Up Control
```
if (touchValueE == TOUCH_THRESHOLD && (millis() - lastTouchTimeE > DEBOUNCE_DELAY)) {
    bleKeyboard.press(KEY_MEDIA_VOLUME_UP);
    bleKeyboard.releaseAll();
    Serial.println("Ses açma (Volume Up) tuşuna basıldı.");
    lastTouchTimeE = millis();
}
```
5.3 BLE Connection
The ESP32 establishes a BLE HID connection with the target device (e.g., PC or smartphone). If the connection is not
established, the system waits and retries, as shown in the following snippet:

```
if (bleKeyboard.isConnected()) {
// Command execution
} else {
Serial.println("Waiting for Bluetooth keyboard connection...");
delay(1000);
}
```
### 6 Results and Observations
- The system successfully controlled Spotify functions, including next/previous track, volume adjustments, and
play/pause.
- The BLE connection remained stable during operation, and the touch sensors exhibited reliable sensitivity and
responsiveness.

### 7 Challenges and Solutions
1. Debouncing Touch Sensors:
   - Issue: Multiple triggers for a single touch.
   - Solution: Implemented a debounce mechanism using the millis() function to ensure sufficient delay
between consecutive inputs.
2. BLE Pairing Issues:
   - Issue: Device pairing delays.
   - Solution: Ensured proper device configuration and reduced retry delays.


### 8 Conclusion
This project showcases the seamless integration of ESP32’s BLE capabilities with touch sensors to control media
playback on Spotify. It enhances user convenience by allowing intuitive touch-based controls. The system can be extended
further to include additional functionalities or integrate with other applications.

### 9 Future Improvements
1. Enhance the touch sensor’s sensitivity to accommodate different environments.
2. Incorporate a low-power mode for extended battery life.
3. Expand functionality to support additional media controls or applications.

### 10 References
- ESP32 Documentation
- BleKeyboard Library GitHub
