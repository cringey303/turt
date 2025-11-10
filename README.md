# turt - Tiny UNIX REPL Terminal

`turt` is a simple shell written in C.
<img width="700" height="560" alt="image" src="https://github.com/user-attachments/assets/93b85de9-2162-4406-8b54-d3818ba8f50b" />

## Features

- Parses and executes external commands (like `ls`, `ps`, `grep`).

- Handles built-in commands (`exit`, `cd`).

- Line editing, history (Up/Down arrows), and Tab-completion via GNU `readline`.

## Building from Source

### Dependencies

This project depends on the GNU `readline` library for all input handling.

### On Debian/Ubuntu (or WSL):
```
sudo apt update
sudo apt install libreadline-dev
```
### On macOS (using Homebrew):
```
brew install readline
```
(Note: You may need to modify the `Makefile` on macOS to point to Homebrew's `readline` path, as macOS uses a different library by default.)

### Compiling

Once all dependencies are installed, just run `make`:
```
make
```
### Running
```
./turt
```
### Cleaning up build files
```
make clean
```
