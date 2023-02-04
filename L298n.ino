
#define i_pot_pin A0
#define i_enable_button_pin 5
#define q_motor_enable_pin 9
#define q_right_pwm_pin 10
#define q_left_pwm_pin 11

uint16_t pot_value = 0;
uint8_t right_pwm_value = 0, left_pwm_value = 0;
bool i_motor_enable_state = LOW;
bool q_motor_enable_state = LOW;

void setup() {
  Serial.begin(9600);
  q_motor_enable_state = LOW;
}

void loop() {

  i_motor_enable_state = digitalRead(i_enable_button_pin);

  pot_value = analogRead(i_pot_pin);

  Serial.print("Pot Value: ");
  Serial.print(pot_value);

  if (i_motor_enable_state == HIGH) {

    Serial.println("    Motor Enable State is True");
    q_motor_enable_state = HIGH;

    if (pot_value >= 512) {
      right_pwm_value = map(pot_value, 512, 1023, 0, 255);
    }

    if (pot_value <= 511) {
      left_pwm_value = map(pot_value, 511, 0, 0, 255);
    }

  }

  else {
    Serial.println("    Motor Enable State is False");
    q_motor_enable_state = LOW;
    right_pwm_value = 0;
    left_pwm_value = 0;
  }

  digitalWrite(q_motor_enable_pin, q_motor_enable_state);
  analogWrite(q_right_pwm_pin, right_pwm_value);
  analogWrite(q_left_pwm_pin, left_pwm_value);
}
