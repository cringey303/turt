# turt - Tiny UNIX REPL Terminal

`turt` is a simple shell written in C.

<img width="550" height="480" alt="turt" src="https://github.com/user-attachments/assets/d4e1fe73-87da-4dbb-aa54-c4c0a2e4d72f" />

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
