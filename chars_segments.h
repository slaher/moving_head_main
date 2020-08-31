
#include <avr/pgmspace.h>
#include <inttypes.h>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7

prog_uint8_t display_segment_normal_enum[19] PROGMEM = {
(1<<H)|(1<<G), //0
(1<<H)|(1<<A)|(1<<D)|(1<<E)|(1<<F)|(1<<G), //1
(1<<H)|(1<<C)|(1<<F), //2
(1<<H)|(1<<E)|(1<<F), //3
(1<<H)|(1<<A)|(1<<E)|(1<<D), //4
(1<<H)|(1<<B)|(1<<E), //5
(1<<H)|(1<<B), //6
(1<<H)|(1<<D)|(1<<E)|(1<<F)|(1<<G), //7
(1<<H)|(0<<A)|(0<<B)|(0<<C)|(0<<D)|(0<<E)|(0<<F)|(0<<G), //8
(1<<H)|(1<<E), //9
(1<<H)|(1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G), //10 - ca³kowite wygaszenie wyœwietlacza
(1<<H)|(1<<D), //0A
(1<<H)|(1<<A)|(1<<F),  //0d
(1<<H)|(1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<F),  //r
(1<<H)|(1<<C)|(1<<D), //P
(1<<H)|(1<<A)|(1<<B)|(1<<D)|(1<<F), //n
(1<<H)|(1<<E)|(1<<A), //Y
(1<<H)|(1<<B)|(1<<C), //E
(1<<H)|(1<<A)|(1<<B)|(1<<C),  //t
};





prog_uint8_t display_segment_inverted_enum[19] PROGMEM = {
(1<<H)|(1<<G), //0
(1<<H)|(1<<A)|(1<<D)|(1<<C)|(1<<B)|(1<<G), //1
(1<<H)|(1<<C)|(1<<F), //2
(1<<H)|(1<<C)|(1<<B), //3
(1<<H)|(1<<A)|(1<<B)|(1<<D), //4
(1<<H)|(1<<B)|(1<<E), //5
(1<<H)|(1<<E), //6
(1<<H)|(1<<C)|(1<<B)|(1<<A)|(1<<G), //7
(1<<H)|(0<<A)|(0<<B)|(0<<C)|(0<<D)|(0<<E)|(0<<F)|(0<<G), //8
(1<<H)|(1<<B), //9
(1<<H)|(1<<A)|(1<<B)|(1<<C)|(1<<D)|(1<<E)|(1<<F)|(1<<G), //10 - ca³kowite wygaszenie wyœwietlacza
(1<<H)|(1<<A), //A
(1<<H)|(1<<D)|(1<<C),  //d
(1<<H)|(1<<A)|(1<<E)|(1<<C)|(1<<D)|(1<<F),  //r
(1<<H)|(1<<F)|(1<<A), //P
(1<<H)|(1<<A)|(1<<C)|(1<<D)|(1<<E), //n
(1<<H)|(1<<B)|(1<<D), //Y
(1<<H)|(1<<E)|(1<<F), //E
(1<<H)|(1<<D)|(1<<E)|(1<<F), //t
};


uint8_t display_segment_normal(uint8_t display_char)
{
	return pgm_read_byte(&display_segment_normal_enum[display_char]);
}
uint8_t display_segment_inverted(uint8_t display_char)
{
	return pgm_read_byte(&display_segment_inverted_enum[display_char]);
}