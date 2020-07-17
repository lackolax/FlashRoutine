#ifndef FLASHROUTINE_H
#define FLASHROUTINE_H

class FlashRoutine
{
public:
    FlashRoutine(byte pin);
    void SetRoutine(int itemsInRoutine,int *routine);
	void SetOn();
	void SetOff();
    void Run();

private:
    byte lastIndex;
    unsigned long lastFlash;
    int routineSize;
    bool isStart;
    byte _pin;
	int *currentRoutine;
	bool manualOverride;
	bool manualState;
};

#endif