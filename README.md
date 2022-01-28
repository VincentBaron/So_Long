# So_Long
![Alt text](./eximg.jpg?raw=true "Optional Title")
## Project Overview

This project was a first introduction to graphic programming using the mlx library. The goal of the project was to code a 2D game with a map.ber file to parse and render it in 2D (see file format below):

```
1111111111111111111111111
1000000000110000000000001
1011000001110000C00000001
1001000000000000000000001
1111111110110000011100001
1000000000110000011101111
1111011111111101110000001
1111011111111101110101001
1100000011010101110000001
10000C0P000E00001100P0001
10000P0000000000110101001
1100000111010101111101111
1111111111111111111111111
1111111111111111111111111
```

It needed a player (P), Collectibles (C) and an Exit (E).

The goal of the game is that the Player can collect all collectibles which will update the score and be able to access the exit and hence finish the game only when all collectibles have been collected.

## What I learned

1. Graphic programming using the mlx library.
2. Memory management to avoid leaks (valgrind, fsanitize, etc.)
3. Optimizing code my code to keep the game as smooth as possible.
4. Creating .xpm textures and implementing them in the game.
5. Error managment (Wrong textures path, wrong map file, etc.).
