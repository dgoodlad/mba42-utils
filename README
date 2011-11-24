Simple utilities for linux running on my Macbook Air 4,2. For now, just
brightness utilities to be installed set-uid-root to be able to modify
root-owned sysfs files.

These may or may not be applicable to many other laptops. It's highly likely
that the MBA 4,1 will work out-of-the-box with these. Other machines may
require editing of some of the preprocessor `#define` lines.

## Usage

`lcd_brightness [up|down|print]`

Manage the LCD screen's backlight brightness.

Using the `up` or `down` commands will bump the brightness by 1 in either
direction (acpi backlight driver has a range of 0-15).

`kbd_brightness [up|down|print]`

Manage the keyboard's backlight LED brightness.

Using the `up` or `down` commands will bump the brightness in powers of 2. The
sysfs interface to the leds has a range of 0-255, but appears to have
exponentially decreasing effect as the value increases.

## LICENSE

See LICENSE file
