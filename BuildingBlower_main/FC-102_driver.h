#pragma once

class FC_102
{
private:
    int startPin;
    int directionPin;
    int pwmPin;

    int pwmChannel;
    int freq;
    int resolution;
    int maxDutyCycle;

public:
    bool motorState = false;
    bool motorDirection = false;
    FC_102(int startPin, int directionPin, int pwmPin, int pwmChannel = 0, int freq = 5000, int resolution = 8)
        : startPin(startPin), directionPin(directionPin), pwmPin(pwmPin), pwmChannel(pwmChannel), freq(freq), resolution(resolution)
    {
        maxDutyCycle = (1 << resolution) - 1; // Calculate max duty cycle based on resolution
    }

    // Initialization
    void begin()
    {
        pinMode(startPin, OUTPUT);
        pinMode(directionPin, OUTPUT);

        ledcSetup(pwmChannel, freq, resolution);
        ledcAttachPin(pwmPin, pwmChannel);
    }

    // Start or stop the motor
    void startMotor(bool start)
    {
        digitalWrite(startPin, start ? HIGH : LOW);
    }
    bool start()
    {
        if (!motorState)
        {
            motorState = true;
            digitalWrite(startPin, motorState);
            return true;
        }
        return false;
    }
    bool stop()
    {
        if (motorState)
        {
            motorState = false;
            digitalWrite(startPin, motorState);
            return true;
        }
        return false;
    }
    
    bool forward()
    {
        if (!motorDirection)
        {
            motorDirection = true;
            digitalWrite(directionPin, motorDirection);
            return true;
        }
        return false;
    }
    bool backward()
    {
        if (motorDirection)
        {
            motorDirection = false;
            digitalWrite(directionPin, motorDirection);
            return true;
        }
        return false;
    }

    void setSpeed(int percent)
    {
        // Clamp percent value between 0 and 100
        percent = max(0, min(percent, 100));

        // Map percent to a PWM duty cycle
        int dutyCycle = map(percent, 0, 100, 0, maxDutyCycle);

        // Set the PWM duty cycle on the specified channel
        ledcWrite(pwmChannel, dutyCycle);
    }
};