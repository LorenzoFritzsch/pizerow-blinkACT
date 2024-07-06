# Raspberry Pi Zero W Bare-Metal Blinking ACT led

This repository contains an embedded, bare-metal C program designed to make blink the ACT led on a Raspberry Pi Zero W.\
The program directly interacts with the hardware registers to control the ACT led, demonstrating low-level hardware manipulation without an OS.

## Notes

The Make configuration compiles and flashes the program onto a SD card located at `/Volumes/SDCARD/` and mounted at `/dev/disk10` in MacOS.\
Update `Makefile` according to your environment.

## Prerequisites

- `arm-none-eabi` cross-compiler installed.
- A FAT32 SD card correctly configured in `Makefile`.

## Usage

Running `$ make` will:

1. Compile (and link) the C program and output the `kernel.img` image file.
2. Flash `kernel.img`, `bootcode.bin` and `start.elf` onto the SD card.
3. Unmount and eject the SD card.
