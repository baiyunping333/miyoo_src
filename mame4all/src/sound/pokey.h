/*****************************************************************************
 *
 *	POKEY chip emulator 4.3
 *	Copyright (c) 2000 by The MAME Team
 *
 *	Based on original info found in Ron Fries' Pokey emulator,
 *	with additions by Brad Oliver, Eric Smith and Juergen Buchmueller.
 *	paddle (a/d conversion) details from the Atari 400/800 Hardware Manual.
 *  Polynome algorithms according to info supplied by Perry McFarlane.
 *
 *	This code is subject to the MAME license, which besides other
 *	things means it is distributed as is, no warranties whatsoever.
 *	For more details read the readme.txt that comes with MAME.
 *
 *****************************************************************************/

#ifndef _POKEYSOUND_H
#define _POKEYSOUND_H

#include "osd_cpu.h"

/* CONSTANT DEFINITIONS */

/* POKEY WRITE LOGICALS */
#define AUDF1_C     0x00
#define AUDC1_C     0x01
#define AUDF2_C     0x02
#define AUDC2_C     0x03
#define AUDF3_C     0x04
#define AUDC3_C     0x05
#define AUDF4_C     0x06
#define AUDC4_C     0x07
#define AUDCTL_C    0x08
#define STIMER_C    0x09
#define SKREST_C    0x0A
#define POTGO_C     0x0B
#define SEROUT_C    0x0D
#define IRQEN_C     0x0E
#define SKCTL_C     0x0F

/* POKEY READ LOGICALS */
#define POT0_C      0x00
#define POT1_C      0x01
#define POT2_C      0x02
#define POT3_C      0x03
#define POT4_C      0x04
#define POT5_C      0x05
#define POT6_C      0x06
#define POT7_C      0x07
#define ALLPOT_C    0x08
#define KBCODE_C    0x09
#define RANDOM_C    0x0A
#define SERIN_C     0x0D
#define IRQST_C     0x0E
#define SKSTAT_C    0x0F

/* exact 1.79 MHz clock freq (of the Atari 800 that is) */
#define FREQ_17_EXACT   1789790

/*
 * We can now handle the exact frequency as well as any other,
 * because aliasing effects are suppressed for pure tones.
 */
#define FREQ_17_APPROX  FREQ_17_EXACT

#define MAXPOKEYS	4	/* max number of emulated chips */

/*****************************************************************************
 * pot0_r to pot7_r:
 *	Handlers for reading the pot values. Some Atari games use
 *	ALLPOT to return dipswitch settings and other things.
 * serin_r, serout_w, interrupt_cb:
 *	New function pointers for serial input/output and a interrupt callback.
 *****************************************************************************/

struct POKEYinterface
{
  int num;    /* total number of pokeys in the machine */
  int baseclock;
  int mixing_level[MAXPOKEYS];
  mem_read_handler pot0_r[MAXPOKEYS];
  mem_read_handler pot1_r[MAXPOKEYS];
  mem_read_handler pot2_r[MAXPOKEYS];
  mem_read_handler pot3_r[MAXPOKEYS];
  mem_read_handler pot4_r[MAXPOKEYS];
  mem_read_handler pot5_r[MAXPOKEYS];
  mem_read_handler pot6_r[MAXPOKEYS];
  mem_read_handler pot7_r[MAXPOKEYS];
  mem_read_handler allpot_r[MAXPOKEYS];
  mem_read_handler serin_r[MAXPOKEYS];
  mem_write_handler serout_w[MAXPOKEYS];
  void (*interrupt_cb[MAXPOKEYS])(int mask);
};


int pokey_sh_start (const struct MachineSound *msound);
void pokey_sh_stop (void);

READ_HANDLER( pokey1_r );
READ_HANDLER( pokey2_r );
READ_HANDLER( pokey3_r );
READ_HANDLER( pokey4_r );
READ_HANDLER( quad_pokey_r );

WRITE_HANDLER( pokey1_w );
WRITE_HANDLER( pokey2_w );
WRITE_HANDLER( pokey3_w );
WRITE_HANDLER( pokey4_w );
WRITE_HANDLER( quad_pokey_w );

void pokey1_serin_ready (int after);
void pokey2_serin_ready (int after);
void pokey3_serin_ready (int after);
void pokey4_serin_ready (int after);

void pokey1_break_w (int shift);
void pokey2_break_w (int shift);
void pokey3_break_w (int shift);
void pokey4_break_w (int shift);

void pokey1_kbcode_w (int kbcode, int make);
void pokey2_kbcode_w (int kbcode, int make);
void pokey3_kbcode_w (int kbcode, int make);
void pokey4_kbcode_w (int kbcode, int make);

#endif	/* POKEYSOUND_H */
