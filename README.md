# so_long

### 🎮 make 2D game
This project is a small 2D game with minilibx. And learn about textures, sprites and tiles.

## Technologies Used
![C](https://img.shields.io/badge/_-C-555555.svg?style=for-the-badge)
![MAKEFILE](https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge)
<img src="https://iili.io/JRxYjDl.png" alt="MLX" width="43" height="28">

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

`*` you can only build this game on *Intel Macs*
`*` 과제 이후 다른 아키텍쳐 (linux, m1, intel) 에서 돌아가는 [so_long.ver2](https://github.com/niamu01/so_long.ver2) 를 제작하였음

## How To Use
```shell
./so_long /path/to/map_file.ber
```