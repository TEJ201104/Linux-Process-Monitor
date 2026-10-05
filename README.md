# Linux Process Monitor

A simple Linux process monitoring program written in C.

## Features

- Lists running processes
- Displays Process ID (PID)
- Displays process name
- Displays process state
- Displays Parent Process ID (PPID)
- Reads process information from the Linux `/proc` filesystem

## Requirements

- Linux operating system
- GCC compiler

## Compilation

```bash
gcc LinuxProcessMonitor.c -o LinuxProcessMonitor
