#ifndef FLASHROUTINE_H
#define FLASHROUTINE_H

class FlashRoutine
{
public:
    FlashRoutine(byte pin);
    void SetRoutine(int itemsInRoutine, int *routine);
    void SetBrightness(byte brightness);
    void SetState(bool on);
    void SetOn();
    void SetOff();
    void Run();

private:
    byte lastIndex;
    byte _brightness;
    unsigned long lastFlash;
    int routineSize;
    bool isStart;
    byte _pin;
    int *currentRoutine;
    bool manualOverride;
    bool manualState;
};

#endif