# My Hunter

Reproduce the functioning of the famous "Duck Hunt" game.    
On my game copy of the Duck Hunt, you shoot on dinosaurs until you miss 3 times.    
You can add more and more dinosaurs with the settings. The bar can up to 5 dinosaurs in addition to ones already moving.    
(You can repeat this function as many as you want).    

## Requirements

| Requirements | Must | Should | Could | Status |
| --- | --- | --- | --- | --- |
| The window must be closed using events. | ✅ | | | |
| The program must manage the input from the mouse click. | ✅ | | | |
| The program must contain animated sprites rendered thanks to sprite sheets. | ✅ | | | |
| The program must contain moving (rotating, translating, or scaling) elements. | ✅ | | | |
| The program must accept the “-h” option, then display a short description of the program, and the available user inputs. |✅| | | |
| Animations and movements in your program should not depend on the speed of your computer. | | ✅ | | |
| Animations and movements in your program should be timed by sfClock elements. | | ✅ | | |
| Your window should stick between 800x600 pixels and 1920x1080 pixels. | | ✅ | | |
| Your window should have a limited frame rate such that it can be compute without lagging. | | ✅ | | |
| The program could have several different levels. | | | ✅ | |
| The program could display the score of the player. | | | ✅ | |
| The program could store the highest score made. | | | ✅ | |
| The program could display a small target under the mouse cursor. | | | ✅ | |

## Next Features ?
| Features | State |
| --- | --- |
| Resize options | |
| More settings | |
| Game Over different when best score is beaten | |
| Apocalypse mode | |
| A real Game Desing identity | |

## How to use ?
to run    
```bash
make && ./my_hunter
```
to get help
```bash
make && ./my_hunter -h

