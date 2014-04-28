/*
** main.cpp for MainWindow in /home/apollo/rendu/LostSoul/client
**
** Made by Antonin Ribeaud
** Login   <ribeau_a@epitech.net>
**
** Started on  Sun Apr  27 22:19:58 2014 Antonin Ribeaud
** Last update Sun Apr  27 22:19:58 2014 Antonin Ribeaud
*/

#include "MainWindow.hpp"

int		main(int argc, char **argv)
{
  QApplication	app(argc, argv);
  MainWindow	MainWindow;
  
  MainWindow.show();
  return (app.exec());
}
