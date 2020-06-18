#include "mockikeypad.h"

bool MockIKeypad::isActive()
{
    return act < 2000;
}

void MockIKeypad::wait()
{
    srand(time(NULL));
    while (rand()%100 != 5) {
    }
}

PasswordResponse MockIKeypad::requestPassword()
{
    act++;
    PasswordResponse res;
    srand(time(NULL));
    if (rand()%5 == 1 or !isActive())
        // Пользователь никогда не наберёт пароль на сломаной клавиатуре)
        res.status = PasswordResponse::Status::TIMEOUT;
    else
        res.status = PasswordResponse::Status::OK;
    res.password = "0451";
    return res;
}
