#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BRIGHTNESS_FILE "/sys/class/backlight/acpi_video0/brightness"
#define MAX_BRIGHTNESS_FILE "/sys/class/backlight/acpi_video0/max_brightness"

void error(const char *msg) {
    fprintf(stderr, msg);
    exit(1);
}

int read_int(const char *path) {
    FILE *f;
    char buffer[256];

    f = fopen(path, "r");
    if(f) {
        if(fgets(buffer, 256, f)) {
            fclose(f);
            return atoi(buffer);
        } else {
            fclose(f);
            error("Error reading\n");
        }
    } else {
        error("Error opening for reading\n");
    }
}

void write_int(const char *path, int value) {
    FILE *f;

    f = fopen(path, "w");
    if(f) {
        if(fprintf(f, "%i", value)) {
            fclose(f);
            return;
        } else {
            fclose(f);
            error("Error writing\n");
        }
    } else {
        error("Error writing\n");
    }
}

int get_brightness() {
    return read_int(BRIGHTNESS_FILE);
}

int get_max_brightness() {
    return read_int(MAX_BRIGHTNESS_FILE);
}

void set_brightness(int brightness) {
    write_int(BRIGHTNESS_FILE, brightness);
}

void inc_brightness() {
    int brightness, max_brightness;

    brightness = get_brightness();
    max_brightness = get_max_brightness();

    if(brightness < max_brightness) {
        set_brightness(brightness + 1);
    }
}

void dec_brightness() {
    int brightness;

    brightness = get_brightness();

    if(brightness > 0) {
        set_brightness(brightness - 1);
    }
}

void zero_brightness() {
    set_brightness(0);
}

void print_brightness() {
    int brightness;
    brightness = get_brightness();
    printf("%i\n", brightness);
}

void print_usage(int argc, char **argv) {
    fprintf(stderr, "Usage: %s [up|down|print]\n", argv[0]);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        print_usage(argc, argv);
        return 1;
    }

    if(strcmp(argv[1], "up") == 0)
        inc_brightness();
    else if(strcmp(argv[1], "down") == 0)
        dec_brightness();
    else if(strcmp(argv[1], "off") == 0)
        zero_brightness();
    else if(strcmp(argv[1], "print") == 0)
        print_brightness();

    return 0;
}
