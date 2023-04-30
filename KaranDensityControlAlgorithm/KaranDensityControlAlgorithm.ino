int greenTime[3] = {0, 0, 0}; // initialize green time for each lane to zero
int lastGreenTime[3] = {0, 0, 0}; // initialize last green time for each lane to zero
unsigned long currentTime; // variable to store current time
unsigned long interval = 5000; // interval for each traffic light cycle (5 seconds)

void loop() {
  // Read sensor values and calculate vehicle density for each lane
  int density1 = analogRead(sensorPin11)+analogRead(sensorPin12);   1  0
  int density2 = analogRead(sensorPin21)+analogRead(sensorRead22);  1  1
  int density3 = analogRead(sensorPin31)+analogRead(sensorRead32);  0  0

  // Calculate the total vehicle density of all three lanes
  int totalDensity = density1 + density2 + density3;

  // Calculate the fair share of green time for each lane
  float fairShare1 = (float)density1 / totalDensity * interval;
  float fairShare2 = (float)density2 / totalDensity * interval;
  float fairShare3 = (float)density3 / totalDensity * interval;

  // Calculate the time elapsed since the last green light for each lane
  currentTime = millis();
  float elapsed1 = (currentTime - lastGreenTime[0]) / 1000.0;
  float elapsed2 = (currentTime - lastGreenTime[1]) / 1000.0;
  float elapsed3 = (currentTime - lastGreenTime[2]) / 1000.0;

  // Check if any lane has been waiting for longer than its fair share of green time
  if (elapsed1 > fairShare1 && elapsed1 >= elapsed2 && elapsed1 >= elapsed3) {
    // Lane 1 has been waiting the longest, give it green light
    digitalWrite(redPin2, HIGH);
    digitalWrite(redPin3, HIGH);
    digitalWrite(yellowPin1, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(greenPin1, HIGH);
    digitalWrite(yellowPin2, HIGH);
    digitalWrite(yellowPin3, HIGH);
    greenTime[0] = elapsed1; // set green time for lane 1 to the time elapsed since last green light
    lastGreenTime[0] = currentTime; // update last green time for lane 1 to current time
  } else if (elapsed2 > fairShare2 && elapsed2 >= elapsed1 && elapsed2 >= elapsed3) {
    // Lane 2 has been waiting the longest, give it green light
    digitalWrite(redPin1, HIGH);
    digitalWrite(redPin3, HIGH);
    digitalWrite(yellowPin2, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(greenPin2, HIGH);
    digitalWrite(yellowPin1, HIGH);
    digitalWrite(yellowPin3, HIGH);
    greenTime[1] = elapsed2; // set green time for lane 2 to the time elapsed since last green light
    lastGreenTime[1] = currentTime; // update last green time for lane 2 to current time
  } else if (elapsed3 > fairShare3 && elapsed3 >= elapsed1 && elapsed3 >= elapsed2) {
    // Lane 3 has been waiting the longest, give it green light
    digitalWrite(redPin1, HIGH);
    digitalWrite(redPin2, HIGH);
   digitalWrite(yellowPin3, LOW);
digitalWrite(redPin3, LOW);
digitalWrite(greenPin3, HIGH);
digitalWrite(yellowPin1, HIGH);
digitalWrite(yellowPin2, HIGH);
greenTime[2] = elapsed3; // set green time for lane 3 to the time elapsed since last green light
lastGreenTime[2] = currentTime; // update last green time for lane 3 to current time
} else {
// No lane has been waiting longer than its fair share of green time, run the default case
digitalWrite(redPin2, HIGH);
digitalWrite(redPin3, HIGH);
digitalWrite(yellowPin1, LOW);
digitalWrite(redPin1, LOW);
digitalWrite(greenPin1, HIGH);
digitalWrite(yellowPin2, HIGH);
digitalWrite(yellowPin3, HIGH);
greenTime[0] = elapsed1; // set green time for lane 1 to the time elapsed since last green light
lastGreenTime[0] = currentTime; // update last green time for lane 1 to current time
}

// Add any remaining green time to the fair share of each lane
fairShare1 += interval - greenTime[0];
fairShare2 += interval - greenTime[1];
fairShare3 += interval - greenTime[2];

// Delay for the duration of the green light for the current lane
delay(greenTime[0]);

// Turn off the green light and turn on the yellow light for the current lane
digitalWrite(greenPin1, LOW);
digitalWrite(yellowPin1, HIGH);

// Delay for the duration of the yellow light for the current lane
delay(yellowTime);

// Turn off the yellow light and turn on the red light for the current lane
digitalWrite(yellowPin1, LOW);
digitalWrite(redPin1, HIGH);

// Delay for the duration of the red light for the current lane
delay(redTime);

// Repeat the same process for the other two lanes
// ...
}

// Delay for the duration of the green light for the current lane
delay(greenTime[1]);

// Turn off the green light and turn on the yellow light for the current lane
digitalWrite(greenPin2, LOW);
digitalWrite(yellowPin2, HIGH);

// Delay for the duration of the yellow light for the current lane
delay(yellowTime);

// Turn off the yellow light and turn on the red light for the current lane
digitalWrite(yellowPin2, LOW);
digitalWrite(redPin2, HIGH);

// Delay for the duration of the red light for the current lane
delay(redTime);

// Repeat the same process for the third lane
// Delay for the duration of the green light for the current lane
delay(greenTime[2]);

// Turn off the green light and turn on the yellow light for the current lane
digitalWrite(greenPin3, LOW);
digitalWrite(yellowPin3, HIGH);

// Delay for the duration of the yellow light for the current lane
delay(yellowTime);

// Turn off the yellow light and turn on the red light for the current lane
digitalWrite(yellowPin3, LOW);
digitalWrite(redPin3, HIGH);

// Delay for the duration of the red light for the current lane
delay(redTime);