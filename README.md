# so_long

### 🎮 make 2D game
This project is a small 2D game with minilibx. And learn about textures, sprites and tiles.

## Technologies Used
![C](https://img.shields.io/badge/_-C-555555.svg?style=for-the-badge)
![MAKEFILE](https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge)
<img src="https://iili.io/JRxYjDl.png" alt="MLX" width="43" height="28">

## Screenshot
<img width="374" alt="pic" src="https://github.com/niamu01/so_long/assets/74657997/ac8b9539-b11d-44c5-b6f8-16c307388211">

https://github.com/niamu01/so_long/assets/74657997/5946cc75-9cef-4ab3-be35-297c6f02a879

## Subject
### Mandatory
- Various error handling
  - You must check whether the map is playable. You can use an algorithm for this check.
  - Read the map file. Each map must contain essential game elements.
- Utilization of external libraries
  - Must be able to manage windows and render images and textures using an mlxlib, a custom 42 library based on OpenGL.
- Gameplay
   - Develop a game allowing movement via WASD, and escape through the exit after collecting all the given collectors.
- Display the count of spaces moved on the terminal after each movement.
	
### Bonus
- Enemy patrols that cause the player to be defeated if they come into contact with them.
- There is sprite animation.
- Move count is displayed directly on screen instead of shell output


## Getting Started
```shell
git clone https://github.com/niamu01/so_long
cd so_long
make [all, re, clean, fclean, bonus]
```
- `make all`: Compiles mandatory files and creates the libftprintf.a file.
- `make re`: Performs an incremental build.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the library file.
- `make bonus`: Builds, including bonus functions in the library.ap

`*` you can only build this game on *Intel Macs* <br>
`*` After completing the assignment, I created a new version called [so_long.ver2](https://github.com/niamu01/so_long_2) that runs on different architectures (M1, Intel). <br>

## How To Use
```shell
./so_long /path/to/map_file.ber
```
