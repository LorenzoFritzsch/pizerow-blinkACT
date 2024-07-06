all: clean compile flash

compile:
	arm-none-eabi-as -o build/start.o start.s
	arm-none-eabi-gcc -c -o build/main.o main.c -I ./include
	arm-none-eabi-gcc -T linker.ld -o build/kernel.elf build/start.o build/main.o -ffreestanding -O2 -nostdlib -lgcc
	arm-none-eabi-objcopy build/kernel.elf -O binary build/kernel.img

clean:
	rm build/*

flash:
	cp flashUtils/* /Volumes/SDCARD/
	cp build/kernel.img /Volumes/SDCARD/
	diskutil unmountDisk /dev/disk10
	diskutil eject /dev/disk10
