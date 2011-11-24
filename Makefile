all: lcd_brightness

lcd_brightness:
	gcc -o lcd_brightness lcd_brightness.c

install: lcd_brightness
	install -o root -m 4755 lcd_brightness /usr/local/bin/lcd_brightness

clean:
	rm -f lcd_brightness
