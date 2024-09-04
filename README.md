So_Long Game

So_Long is a simple tile-based game where the player must collect all the collectibles and reach the exit while navigating through obstacles. Developed using the MiniLibX library for graphics and handling user inputs, this game is a classic example of a 2D puzzle platformer.
Features

    Player Movement: Move the player up, down, left, or right.
    Collectibles: Gather all the collectible items to win the game.
    Exit: Reach the exit after collecting all collectibles to complete the level.
    Graphics: Simple 2D graphics using MiniLibX.

Getting Started
Prerequisites

    MiniLibX: Ensure you have MiniLibX installed. You can find instructions on MiniLibX GitHub.
    Compiler: Ensure you have gcc or any other C compiler installed.
    Make: Make sure you have make installed to build the project.

Installation

    Clone the repository:

    bash

git clone https://github.com/tjsweetblack/so_long.git
cd so_long

Build the project:

bash

make

Run the game:

bash

    ./so_long maps/your_map.ber

Map Format

The game maps are defined in .ber files. The map should follow these rules:

    '1': Wall
    '0': Empty Space
    'C': Collectible
    'E': Exit
    'P': Player Start Position

Example map:

    1111111111111
    1C1100E0000C1
    1000011111001
    1P00110000001
    1111111111111

How It Works
Game Logic

    Initialization:
        The game initializes the window and loads images using MiniLibX.
        The map is loaded and parsed to determine the size and contents.

    Movement:
        The player can move using the arrow keys.
        Each movement updates the player's position and the game state.

    Collision Detection:
        The game checks for collisions with walls and boundaries.
        Collectibles are collected, and their count is tracked.

    End of Game:
        The game ends when all collectibles are collected and the player reaches the exit.

Flood Fill Algorithm

To ensure the map is playable:

    Flood Fill: Used to check if all collectibles are reachable and if the exit is accessible. The algorithm starts from the player's position and marks reachable areas.
    Map Validation: Verifies if the player can access all collectibles and reach the exit.

Error Handling

    Invalid Map: Prints errors if the map contains invalid elements or the player cannot complete the level.
    Memory Management: Ensures no memory leaks by properly freeing allocated memory.

Contributing

    Fork the repository.
    Create a new branch for your feature or bug fix.
    Make your changes and test them.
    Submit a pull request.

License

This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgements

    MiniLibX for the graphics library.
    42 Network for their resources and community support.

Feel free to modify or expand on this template based on additional features or specific requirements of your game.
