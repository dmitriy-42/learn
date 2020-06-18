#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Lab9_Project_for_tests/lockcontroller.h"
#include "../Lab9_Project_for_tests/mockilatch.h"
#include "../Lab9_Project_for_tests/mockikeypad.h"

#include "gmock.cpp"

using namespace testing;

/*
Тест 1
Исходные данные:
- Всё в порядке никаких проблем нет;
Действие:
- Вызывается метод wait() класса LockController;
Ожидается:
- Метод wait() класса IKeypad будет вызван один раз;

Тест 2
Исходные данные:
- Дверь закрыта.
Действие:
- Вызывается метод isDoorOpen() класса LockController;
Ожидается:
- Метод isDoorOpen() класса LockController вернёт false;
- Метод getDoorStatus() класса ILatch будет вызван один раз;

Тест 3
Исходные данные:
- Дверь отрыта.
Действие:
- Вызывается метод isDoorOpen() класса LockController;
Ожидается:
- Метод isDoorOpen() класса LockController вернёт true;
- Метод getDoorStatus() класса ILatch будет вызван один раз;

Тест 4
Исходные данные:
- если нужно, защёлка двери успешно открывается и закрывается. Никаких помех нет.
Действие:
- Вызывается метод unlockDoor() класса LockController;
Ожидается:
- Метод unlockDoor() класса LockController вернёт DoorStatus::OPEN;
- Метод open() класса ILatch будет вызван один раз;

Тест 5
Исходные данные:
- если нужно, защёлка двери успешно открывается и закрывается. Никаких помех нет.
Действие:
- Вызывается метод lockDoor() класса LockController;
Ожидается:
- Метод close() класса ILatch будет вызван один раз;
- Метод lockDoor() класса LockController вернёт DoorStatus::CLOSE;

Тест 6
Исходные данные:
- Объекты классов IKeypad и ILatch созданы, валидны и переданы в конструктор LockController;
- С оборудованием всё в порядке.
Действие:
- Вызывается метод hardWareCheck() класса LockController;
Ожидается:
- Метод hardWareCheck() класса LockController вернёт HardWareStatus::OK;
- Метод isActive() класса IKeypad будет вызван один раз;
- Метод isActive() класса ILatch будет вызван один раз;

Тест 7
Исходные данные:
- Объект класса ILatch создан, валиден и передан в конструктор LockController;
- С задвижкой (ILatch) всё в порядке.
- Вместо объекта класса IKeypad передан nullptr;
Действие:
- Вызывается метод hardWareCheck() класса LockController;
Ожидается:
- Метод hardWareCheck() класса LockController вернёт HardWareStatus::ERROR;
- Метод isActive() класса IKeypad будет вызван ноль или более раз;
- Метод isActive() класса ILatch будет вызван ноль или более раз;

Тест 8
Исходные данные:
- Объекты классов IKeypad и ILatch созданы, валидны и переданы в конструктор LockController;
- С клавиатурой (IKeypad) всё в порядке.
- Задвижка (ILatch) не активна.
Действие:
- Вызывается метод hardWareCheck() класса LockController;
Ожидается:
- Метод hardWareCheck() класса LockController вернёт HardWareStatus::ERROR;
- Метод isActive() класса IKeypad будет вызван ноль или более раз;
- Метод isActive() класса ILatch будет вызван ноль или более раз;

Тест 9
Исходные данные:
- LockController только создан, поэтому установлен дефолтный пароль("0000");
- Пользователь вводит правильный пароль (когда у него попросят).
Действие:
- Вызывается метод isCorrectPassword() класса LockController;
Ожидается:
- Метод isCorrectPassword() класса LockController вернёт true;
- Метод requestPassword() класса IKeypad будет вызван один раз;

Тест 10
Исходные данные:
- LockController только создан, поэтому установлен дефолтный пароль("0000");
- Пользователь вводит НЕ правильный пароль.
Действие:
- Вызывается метод isCorrectPassword() класса LockController;
Ожидается:
- Метод isCorrectPassword() класса LockController вернёт false;
- Метод requestPassword() класса IKeypad будет вызван один раз;

Тест 11
Исходные данные:
- LockController только создан, поэтому установлен дефолтный пароль("0000");
- Старый пароль вводится правильно;
Действие:
- Вызывается метод resetPassword() класса LockController;
Ожидается:
- будет запрошен старый пароль;
- будет установлен новый пароль, введённый пользователем (нельзя на прямую проверить, т.к. password не public и геттера нет);

Тест 12
Исходные данные:
- Пароль изменён на "9876";
- Пользователь правильно вводит пароль;
Действие:
- Вызывается метод resetPassword() класса LockController;
Ожидается:
В результате вызова метода resetPassword() класса LockController будет:
- будет запрошен старый пароль;
- будет установлен новый пароль, введённый пользователем (нельзя на прямую проверить, т.к. password не public и геттера нет);

*/







TEST(LockController, wait)
{
    GMockILatch latch;
    GMockIKeypad keypad;

    EXPECT_CALL(keypad,wait()).Times(1);

    LockController cont(&keypad, &latch);

    cont.wait();
    //cont.wait();
}

TEST(LockController, isDoorOpen_close)
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::CLOSE));
    //ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::OPEN));
    EXPECT_CALL(latch, getDoorStatus()).Times(1);

    EXPECT_FALSE(cont.isDoorOpen());
    //EXPECT_FALSE(cont.isDoorOpen());
}

TEST(LockController, isDoorOpen_open)
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    //ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::CLOSE));
    ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::OPEN));
    EXPECT_CALL(latch, getDoorStatus()).Times(1);

    EXPECT_TRUE(cont.isDoorOpen());
    //EXPECT_FALSE(cont.isDoorOpen());
}

TEST(LockController, isDoorOpen)
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::CLOSE));
    //ON_CALL(latch, getDoorStatus()).WillByDefault(Return(DoorStatus::OPEN));
    EXPECT_CALL(latch, getDoorStatus()).Times(1);

    EXPECT_FALSE(cont.isDoorOpen());
    //EXPECT_FALSE(cont.isDoorOpen());
}

TEST(LockController, unlockDoor)
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));

    EXPECT_CALL(latch, open()).Times(1);


    EXPECT_EQ(cont.unlockDoor(),DoorStatus::OPEN);
}

TEST(LockController, lockDoor) //test5
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    EXPECT_CALL(latch, close()).Times(1);


    EXPECT_EQ(cont.lockDoor(),DoorStatus::CLOSE);
}

TEST(LockController, hardWareCheck) //test6
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(&keypad, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    EXPECT_CALL(keypad, isActive()).Times(1);
    EXPECT_CALL(latch, isActive()).Times(1);

    EXPECT_EQ(cont.hardWareCheck(), HardWareStatus::OK);
}

TEST(LockController, keypad_nullptr) //test7
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    EXPECT_EQ(cont.hardWareCheck(), HardWareStatus::ERROR);
}

TEST(LockController, latch_not_active) //test8
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(false));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    EXPECT_EQ(cont.hardWareCheck(), HardWareStatus::ERROR);
}

TEST(LockController, isCorrectPassword_true) //test9
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    PasswordResponse res;
    res.status = PasswordResponse::Status::OK;
    res.password = "0000";
    ON_CALL(keypad, requestPassword()).WillByDefault(Return(res));

    EXPECT_CALL(keypad, requestPassword()).Times(1);

    EXPECT_EQ(cont.isCorrectPassword(), true);
}


TEST(LockController, isCorrectPassword_false) //test10
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    PasswordResponse res;
    res.status = PasswordResponse::Status::OK;
    res.password = "0451";
    ON_CALL(keypad, requestPassword()).WillByDefault(Return(res));


    EXPECT_CALL(keypad, requestPassword()).Times(1);

    EXPECT_EQ(cont.isCorrectPassword(), false);
}



TEST(LockController, resetPassword) //test11
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    PasswordResponse res;
    res.status = PasswordResponse::Status::OK;
    res.password = "0000";
    PasswordResponse res1;
    res.status = PasswordResponse::Status::OK;
    res.password = "0451";
    EXPECT_CALL(keypad, requestPassword()).Times(3).WillOnce(Return(res)).WillOnce(Return(res1)).WillOnce(Return(res1));

    cont.resetPassword();

    EXPECT_EQ(cont.isCorrectPassword(), true);
}


TEST(LockController, resetPassword2) //test12
{
    GMockILatch latch;
    GMockIKeypad keypad;
    LockController cont(nullptr, &latch);
    ON_CALL(latch, isActive()).WillByDefault(Return(true));
    ON_CALL(keypad, isActive()).WillByDefault(Return(true));
    ON_CALL(latch, open()).WillByDefault(Return(DoorStatus::OPEN));
    ON_CALL(latch, close()).WillByDefault(Return(DoorStatus::CLOSE));

    PasswordResponse res;
    res.status = PasswordResponse::Status::OK;
    res.password = "0000";
    PasswordResponse res1;
    res.status = PasswordResponse::Status::OK;
    res.password = "9876";
    PasswordResponse res2;
    res.status = PasswordResponse::Status::OK;
    res.password = "0451";
    EXPECT_CALL(keypad, requestPassword()).Times(5)
            .WillOnce(Return(res))
            .WillOnce(Return(res1)) //Изменение пароля на 9876
            .WillOnce(Return(res1))
            .WillOnce(Return(res2)) //Изменение пароля на 0451
            .WillOnce(Return(res2)) //Проверка
            ;

    cont.resetPassword();
    cont.resetPassword();

    EXPECT_EQ(cont.isCorrectPassword(), true);
}

#endif // TST_TESTDIVISIONBYZERO_H
