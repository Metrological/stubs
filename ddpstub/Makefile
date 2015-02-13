TARGET = ddpstub
OUTPUT = ../artifacts

SOURCE += DDPlusDecPlugin.cpp

INC = -I$(STAGING_DIR)/usr/include
CFLAGS = -Wall -fPIC
LIBDIR = -L$(OUTPUT)/$(TYPE) -L$(STAGING_DIR)/usr/lib
LIB = 
LDFLAGS = 

DEBUG_INC = $(INC)
DEBUG_CFLAGS = $(CFLAGS) -g -D__DEBUG__
DEBUG_LIBDIR = $(LIBDIR)
DEBUG_LIB = $(LIB)
DEBUG_LDFLAGS = $(LDFLAGS)

RELEASE_INC = $(INC)
RELEASE_CFLAGS = $(CFLAGS) -O2 
RELEASE_LIBDIR = $(LIBDIR)
RELEASE_LIB = $(LIB)
RELEASE_LDFLAGS = $(LDFLAGS) -s

ifeq ($(TYPE), Debug)
    ACTUAL_INC = $(DEBUG_INC)
    ACTUAL_CFLAGS = $(DEBUG_CFLAGS)
    ACTUAL_LIBDIR = $(DEBUG_LIBDIR)
    ACTUAL_LIB = $(DEBUG_LIB)
    ACTUAL_LDFLAGS = $(DEBUG_LDFLAGS)
else
    TYPE = Release
    ACTUAL_INC = $(RELEASE_INC)
    ACTUAL_CFLAGS = $(RELEASE_CFLAGS)
    ACTUAL_LIBDIR = $(RELEASE_LIBDIR)
    ACTUAL_LIB = $(RELEASE_LIB)
    ACTUAL_LDFLAGS = $(RELEASE_LDFLAGS)
endif

OBJECTS=$(join $(addsuffix obj/$(TYPE)/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o)))

all: install

install: target staging

target: $(OUTPUT)/$(TYPE)/lib$(TARGET).a
	cp $(OUTPUT)/$(TYPE)/lib$(TARGET).a $(TARGET_DIR)/usr/lib
	ln -s $(TARGET_DIR)/usr/lib/lib$(TARGET).a libdcv_sub.a

staging: $(OUTPUT)/$(TYPE)/lib$(TARGET).a
	cp *.h $(STAGING_DIR)/usr/include/
	cp $(OUTPUT)/$(TYPE)/lib$(TARGET).a $(STAGING_DIR)/usr/lib

build: $(OUTPUT)/$(TYPE)/lib$(TARGET).a

$(OUTPUT)/$(TYPE)/lib$(TARGET).a: $(OBJECTS)
	@mkdir -p $(OUTPUT)/$(TYPE)
	@mkdir -p ./obj/$(TYPE)
	$(AR) rcs $(OUTPUT)/$(TYPE)/lib$(TARGET).a $(OBJECTS)

obj/$(TYPE)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c -o $@ $<
	
clean: 
	rm -f ./obj/$(TYPE)/*
	rm -rf $(OUTPUT)/$(TYPE)/lib$(TARGET).a

.PHONY: all install build
