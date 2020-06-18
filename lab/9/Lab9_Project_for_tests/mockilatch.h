#ifndef MOCKILATCH_H
#define MOCKILATCH_H
#include "ILatch.h"

class MockILatch: public ILatch
{
public:
    MockILatch() = default;
    bool isActive() override;
    DoorStatus open() override;
    DoorStatus close() override;
    DoorStatus getDoorStatus() override;
    int getTestOpen();
    int getTestClose();
    int getTestGetDoorStatus();
    int getTestIsActive();
protected:
    DoorStatus stat = DoorStatus::OPEN;
    int act = 0;
    int testOpen = 0;
    int testClose = 0;
    int testGetDoorStatus = 0;
    int testIsActive = 0;
};

#endif // MOCKILATCH_H
