# 🧱Wall visualizer

## 📦Installation
**Note:** This project runs on Linux or macOS. <br>
If you’re on Windows, use either:
- *Windows Subsystem for Linux* (WSL)
- or a *Linux virtual machine*.

<br>

#### 1. Install dependencies
Make sure you have a C++ compiler and make installed

**Linux**
```bash
sudo apt update
sudo apt install g++ make
```
**macOS**
```bash
brew install gcc make
```
<br>

#### 2. Build the project
From the root of thr project:
```bash
make
```


#### 3. Run the program
```bash
./bricks
```
<br>

#### Cleaning up
To remove all object files and the executable
```bash
make fclean
```

<br>

#### For Testing
You can adjust the wall size inside `header/header.hpp`:
```cpp
const int WALL_WIDTH  = 2300;
const int WALL_HEIGHT = 2000;
```
After making changes, recompile with:
```bash
make re
```
<br>

---

***Can you figure out why a brick is slightly more than two times longer than it is deep?***

- full brick: 210mm length
- half-brick: 100mm length
- head Joint: 10mm

```
full_brick_len = half_brick_len + head_joint + half_brick_len
210mm = 100mm + 10mm + 100mm
```
