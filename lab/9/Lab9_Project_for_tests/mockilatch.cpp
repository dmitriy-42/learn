#include "mockilatch.h"

bool MockILatch::isActive()
{
    testIsActive++;
    return act < 2000;
}

DoorStatus MockILatch::open()
{
    testOpen++;
    if (stat == DoorStatus::CLOSE and isActive())
    {
        act++;
        stat = DoorStatus::OPEN;
    }
    return stat;
}


DoorStatus MockILatch::close()
{
    testClose++;
    if (stat == DoorStatus::OPEN and isActive())
    {
        act++;
        stat = DoorStatus::CLOSE;
    }
    return stat;
}

DoorStatus MockILatch::getDoorStatus()
{
    testGetDoorStatus++;
    return stat;
}

int MockILatch::getTestOpen()
{
    return testOpen;
}

int MockILatch::getTestClose()
{
    return testClose;
}

int MockILatch::getTestIsActive()
{
    return testIsActive;
}

int MockILatch::getTestGetDoorStatus()
{
    return testGetDoorStatus;
}
