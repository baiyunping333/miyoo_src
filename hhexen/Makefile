# HHexen Makefile
# $Revision: 566 $
#
# svga			build Software (SVGALib) version
# sdl			build Software (SDL) version
# opengl		build OpenGL (SDL) version
# clean:		remove all intermediate files
#
# It is ESSENTIAL that you run make clean between different
# types of builds or different types of targets.
#

# Basic stuff
SHELL = /bin/sh


top_srcdir = .
srcdir = .
prefix = /usr/local
exec_prefix = ${prefix}
bindir = $(exec_prefix)/bin
infodir = $(prefix)/info
libdir = $(prefix)/lib
mandir = $(prefix)/man/man1
includedir = $(prefix)/include

CC = arm-linux-gcc
DEFS = -DHAVE_CONFIG_H
CFLAGS =  -Wall -O2 -ffast-math -fomit-frame-pointer -fno-strength-reduce
CPPFLAGS = 
LDFLAGS = 
LIBS = -lm 
BASELIBS = -lm 
THREAD_LIBS = -lpthread
X11_INC = 
X11_LIB = 
GL_LIBS = -lGL -lGLU
SVGALIBS = 
SDL_LIBS = -lSDL -lpthread
SDL_CFLAGS = -I/opt/miyoo/arm-miyoo-linux-uclibcgnueabi/sysroot/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
GLHEXEN = false
SVGAHEXEN = false
SHARED_DATAPATH = 
SND_MODULE= sdl

# Directories

TOPSRCDIR = .
TOPOBJDIR = .
SRCDIR    = .

MODULE    = none

CPPFLAGS += -I. -I$(SRCDIR)/include
ifneq ($(SVGAHEXEN),true)
ifneq ($(X11_INC),)
CPPFLAGS += -I$(X11_INC)
endif
CPPFLAGS += $(SDL_CFLAGS)
endif

ifneq ($(X11_LIB),)
GL_LIBS := -L$(X11_LIB) $(GL_LIBS)
endif

# Objects to build

OBJ_SYS  = unix/i_linux.o
OBJ_SVGA = svgalib/i_svgalib.o
OBJ_SWSDL = sdl/i_sdl.o
OBJ_GLSDL = sdl/i_sdlgl.o
OBJ_OSS = unix/oss.o unix/i_soundpi.o
OBJ_SDLAUDIO = sdl/i_sndsdl.o
OBJ_SDLMIXER = base/mmus2mid.o sdl/i_sdlmixer.o
OBJ_CDA = unix/i_cdmus.o

ifeq ($(SND_MODULE),oss)
OBJ_SND:= $(OBJ_OSS)
BASELIBS:=$(BASELIBS) $(THREAD_LIBS)
endif
ifeq ($(SND_MODULE),sdl)
OBJ_SND:= $(OBJ_SDLAUDIO)
endif
ifeq ($(SND_MODULE),sdlmixer)
OBJ_SND:= $(OBJ_SDLMIXER)
endif

OBJ_OPENGL = \
	opengl/ogl_clip.o \
	opengl/ogl_draw.o \
	opengl/ogl_rend.o \
	opengl/ogl_rl.o \
	opengl/ogl_scr.o \
	opengl/ogl_sky.o \
	opengl/ogl_tex.o \
	opengl/ogl_main.o \
	opengl/m_bams.o

OBJ_BASE = \
	base/am_map.o \
	base/a_action.o \
	base/ct_chat.o \
	base/d_net.o \
	base/f_finale.o \
	base/g_game.o \
	base/h2_main.o \
	base/h_hubmsg.o \
	base/info.o \
	base/in_lude.o \
	base/mn_menu.o \
	base/m_misc.o \
	base/p_acs.o \
	base/p_anim.o \
	base/p_ceilng.o \
	base/p_doors.o \
	base/p_enemy.o \
	base/p_floor.o \
	base/p_inter.o \
	base/p_lights.o \
	base/p_map.o \
	base/p_maputl.o \
	base/p_mobj.o \
	base/p_plats.o \
	base/p_pspr.o \
	base/p_setup.o \
	base/p_sight.o \
	base/p_spec.o \
	base/p_switch.o \
	base/p_telept.o \
	base/p_tick.o \
	base/p_things.o \
	base/p_user.o \
	base/po_man.o \
	base/r_bsp.o \
	base/r_data.o \
	base/r_draw.o \
	base/r_main.o \
	base/r_plane.o \
	base/r_segs.o \
	base/r_things.o \
	base/sb_bar.o \
	base/sc_man.o \
	base/s_sound.o \
	base/sn_sonix.o \
	base/st_start.o \
	base/sv_save.o \
	base/tables.o \
	base/v_video.o \
	base/w_wad.o \
	base/z_zone.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<


ifeq ($(SVGAHEXEN),true)
svga: $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_SVGA) $(OBJ_BASE)
	$(CC) $(LDFLAGS) $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_SVGA) $(OBJ_BASE) -o hhexen-svga $(BASELIBS) $(SVGALIBS)
else

ifeq ($(GLHEXEN),true)
opengl: $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_GLSDL) $(OBJ_OPENGL) $(OBJ_BASE)
	$(CC) $(LDFLAGS) $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_GLSDL) $(OBJ_OPENGL) $(OBJ_BASE) -o hhexen-gl $(BASELIBS) $(GL_LIBS) $(SDL_LIBS)
else
sdl: $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_SWSDL) $(OBJ_BASE)
	$(CC) $(LDFLAGS) $(OBJ_SYS) $(OBJ_SND) $(OBJ_CDA) $(OBJ_SWSDL) $(OBJ_BASE) -o hhexen-sdl $(BASELIBS) $(SDL_LIBS)
endif

endif

clean:
	$(RM) base/*.o opengl/*.o dos/*.o unix/*.o sdl/*.o svgalib/*.o

