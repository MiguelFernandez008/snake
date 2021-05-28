#include <gb/gb.h>
#include <stdio.h>
#include "includes/globals.c"
#include "assets/apple.c"
#include "assets/snake.c"


void init_game()
{
    game_started = 1; // starts the game
}

void pause_game()
{    
}

void check_movement()
{
    switch (joypad())
    {
    case J_RIGHT:
        if (game_started != 0)
        {
            scroll_sprite(1, snake_h_speed, 0);
            scroll_sprite(2, snake_h_speed, 0);
            scroll_sprite(3, snake_h_speed, 0);
        }
        break;
    case J_LEFT:
        if (game_started != 0)
        {
            scroll_sprite(1, (-1*snake_h_speed), 0);
            scroll_sprite(2, (-1*snake_h_speed), 0);
            scroll_sprite(3, (-1*snake_h_speed), 0);
        }
        break;
    case J_UP:
        if (game_started != 0)
        {
        }
        break;
    case J_DOWN:
        if (game_started != 0)
        {
        }
        break;
    case J_START:
        game_started == 0 ? init_game() : pause_game();
        break;
    default:
        break;
    }
}

void init()
{
    SPRITES_8x8;
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
    set_sprite_data(32, 1, Apple); //sets sprite data in memory
    set_sprite_data(33, 3, snake);
    set_sprite_tile(0, 32); // apple - assign an sprite index to a memory position
    set_sprite_tile(1, 33); // head - assign an sprite index to a memory position
    set_sprite_tile(2, 34); // tail - assign an sprite index to a memory position
    set_sprite_tile(3, 35); // head - assign an sprite index to a memory position
	move_sprite(0, 75, 75);
	move_sprite(1, 20, 20);
	move_sprite(2, 12, 20);
	move_sprite(3, 28, 20);
}

void main()
{
    // Initialization
    init();
    
    // Game loop
    while (1)
    {
        // Joypad
        check_movement();
        delay(loop_delay);
    }    
}