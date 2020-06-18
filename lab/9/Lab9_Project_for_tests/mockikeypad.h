#ifndef MOCKIKEYPAD_H
#define MOCKIKEYPAD_H
#include "IKeypad.h"

class MockIKeypad: public IKeypad
{
public:
    MockIKeypad() = default;
    bool isActive() override;
    void wait() override;
    PasswordResponse requestPassword() override;
protected:
    int act = 0;

    int testIsActive = 0;
    int testWait = 0;
};

#endif // MOCKIKEYPAD_H
