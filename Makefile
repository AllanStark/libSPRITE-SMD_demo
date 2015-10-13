SPRITEDIR:=/usr/local
SPRITEINCDIR:=$(SPRITEDIR)/include/SPRITE
SPRITELIBDIR:=$(SPRITEDIR)/lib/SPRITE

LUA_INCLUDE:=/usr/local/include
LUA_LIB:=lua

SRC:=tasks/Logger.cpp \
     tasks/SMD.cpp \
     tasks/Ap.cpp

TEST_SRC:=

TGT:=sprite_main
TGT_TYPE:=application

SP:=./
CFLAGS=-I./ -I$(SPRITEINCDIR) -I$(LUA_INCLUDE) -DXPRINT_LOCATION #-DPRINT_DEBUG

include $(SP)rules.mk

LDFLAGS+=-L$(SPRITELIBDIR) -lSPRITE_SCALE -lSPRITE_SRTX -lSPRITE_math \
         -lSPRITE_units -lpthread -l$(LUA_LIB) -lrt -ldl

$(TGT): $(TGT).o $(OBJS)
	$(CPP) -o $@ $^ $(LDFLAGS)

EXTRA_CLEAN+=$(TGT).o $(TGT).d

release:
	@echo "Enter version number: "; \
	read VERSION; \
	git branch release-$$VERSION; \
	git push origin release-$$VERSION; \
	RELEASENAME=libSPRITE-SMD_demo-$$VERSION; \
	git archive --prefix=$$RELEASENAME/ master | bzip2 > ../$$RELEASENAME.tar.bz2

tasks/Ap.o: CPPFLAGS+=-DPRINT_DEBUG
#tasks/SMD.o: CPPFLAGS+=-DPRINT_DEBUG
