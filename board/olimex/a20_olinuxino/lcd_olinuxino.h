/*
 * Copyright (C) 2018 Olimex Ltd.
 *   Author: Stefan Mavrodiev <stefan@olimex.com>
 *
 * SPDX-License-Identifier: (GPL-2.0+ OR MIT)
 */

#ifndef __LCD_OLINUXINO_H
#define __LCD_OLINUXINO_H

#define LCD_OLINUXINO_EEPROM_BUS	I2C_2
#define LCD_OLINUXINO_EEPROM_ADDRESS	0x50
#define LCD_OLINUXINO_HEADER_MAGIC      0x4F4CB727
#define LCD_OLINUXINO_DATA_LEN          256

#define MEDIA_BUS_FMT_RGB666_1X18               0x1009
#define MEDIA_BUS_FMT_RGB888_1X24               0x100a


struct lcd_olinuxino_mode {
	u32 pixelclock;
	u32 hactive;
	u32 hfp;
	u32 hbp;
	u32 hpw;
	u32 vactive;
	u32 vfp;
	u32 vbp;
	u32 vpw;
	u32 refresh;
	u32 flags;
};

struct lcd_olinuxino_info {
	char name[32];
	u32 width_mm;
	u32 height_mm;
	u32 bpc;
	u32 bus_format;
	u32 bus_flag;
} __attribute__((__packed__));

struct lcd_olinuxino_board {
	struct lcd_olinuxino_info info;
	struct lcd_olinuxino_mode mode;
};

struct lcd_olinuxino_eeprom {
	u32 header;
	u32 id;
	char revision[4];
	u32 serial;
	struct lcd_olinuxino_info info;
	u32 num_modes;
	u8 reserved[180];
	u32 checksum;
} __attribute__((__packed__));

extern struct lcd_olinuxino_eeprom lcd_olinuxino_eeprom;
extern struct lcd_olinuxino_board lcd_olinuxino_boards[];

bool lcd_olinuxino_is_present(void);

char * lcd_olinuxino_video_mode(void);
uint8_t lcd_olinuxino_dclk_phase(void);
char * lcd_olinuxino_compatible(void);

#endif /* __LCD_OLINUXINO_H */
