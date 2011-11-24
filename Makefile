all: lcd_brightness kbd_brightness

lcd_brightness:
	gcc -o lcd_brightness lcd_brightness.c

kbd_brightness:
	gcc -o kbd_brightness kbd_brightness.c

install: lcd_brightness kbd_brightness
	install -o root -m 4755 lcd_brightness /usr/local/bin/lcd_brightness
	install -o root -m 4755 kbd_brightness /usr/local/bin/kbd_brightness

clean:
	rm -f lcd_brightness kbd_brightness
