/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2020 Dmitriy
 * 
 */

#include "head.h"
#include <iostream>

int main()
{
  Game game;
  game = initGame('x');
  while (not updateGame(&game))
  {
    updateDisplay(game);
    if (game.isUserTurn) userTurn(&game);
    else botTurn(&game);
  }
  updateDisplay(game);
  if (game.status == USER_WIN) std::cout << "Вы победили";
  else if (game.status == BOT_WIN) std::cout << "Бот победил";
  else std::cout << "Ничья";
  std::cout << "\n";
  return 0;
}

