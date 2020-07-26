#include <Arduino.h>
#include "FlashRoutine.h"

FlashRoutine::FlashRoutine(byte pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
    lastIndex = 0;
    lastFlash = 0;
}

void FlashRoutine::SetBrightness(byte brightness)
{
    _brightness = brightness;
}

void FlashRoutine::SetRoutine(int itemsInRoutine, int *routine)
{
    currentRoutine = routine;
    routineSize = itemsInRoutine;
    lastIndex = 0;
    lastFlash = 0;
    isStart = true;
    manualOverride = false;
}

void FlashRoutine::SetOn()
{
    manualOverride = true;
    manualState = true;
}

void FlashRoutine::SetOff()
{
    manualOverride = true;
    manualState = false;
}

void FlashRoutine::SetState(bool on)
{
    analogWrite(_pin, on ? map(_brightness, 0, 100, 0, 255) : 0);
}

void FlashRoutine::Run()
{
    if (manualOverride)
    {
        SetState(manualState);
        return;
    }
    unsigned long currentMillis = millis();
    if (isStart)
    {
        lastFlash = currentMillis;
        lastIndex = 0;
        SetState(0);
        isStart = false;
        return;
    }

    unsigned int interval = currentRoutine[lastIndex];

    if ((currentMillis - lastFlash) > interval)
    {
        lastFlash = currentMillis;

        SetState(lastIndex % 2 == 0 ? 1 : 0);

        if (lastIndex == (routineSize - 1))
        {
            lastIndex = 0;
        }
        else
        {
            lastIndex = lastIndex + 1;
        }
    }
}
