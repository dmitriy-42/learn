#include "../Lab9_Project_for_tests/IKeypad.h"
#include "../Lab9_Project_for_tests/ILatch.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GMockIKeypad : public IKeypad {
public:
    MOCK_METHOD(bool, isActive, ());
    MOCK_METHOD(void, wait, ());
    MOCK_METHOD(PasswordResponse, requestPassword, ());
};

class GMockILatch : public ILatch {
public:
    MOCK_METHOD(bool, isActive, ());
    MOCK_METHOD(DoorStatus, open, ());
    MOCK_METHOD(DoorStatus, close, ());
    MOCK_METHOD(DoorStatus, getDoorStatus, ());
};
