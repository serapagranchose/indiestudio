/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

#include "Game.hpp"

void print_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tport\tis the server ip address on which the server socket listens.\n");
    printf("\tport\tis the port number on which the server socket listens.\n");
}

int input_checker(int ac, char **av)
{
    if (ac == 2) {
        if (!strcmp(av[1], "-h")) {
            print_usage();
            return(1);
        } else if (!strcmp(av[1],"-d"))
            return(2);
    }

    if (ac != 3)
        return(84);

    return(0);
}

int main(int ac, char **av)
{
    Game bomberman;

    if (input_checker(ac, av) == 1)
        return (0);
    else if (input_checker(ac, av) == 2)
        bomberman.setDebug(true);
    bomberman.game_loop();
    return (0);
}
