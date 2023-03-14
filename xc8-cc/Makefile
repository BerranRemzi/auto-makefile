PROJECT_NAME := $(notdir $(CURDIR))
CC        := "C:/Tools/Microchip/xc8/v2.40/bin/xc8-cc.exe"
DFP_DIR	  := "C:/Tools/Microchip/MPLABX/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8"
CPU       := 10F322
SRCDIR    := src
BUILDDIR  := build/default/production/src
BINDIR    := dist/default/production

TARGET    := $(BINDIR)/$(PROJECT_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f \( -name *.c* -o -name *.s \))
HEDEARS   := $(shell find $(SRCDIR) -type f -name *.h*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .p1,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
INC       := $(patsubst %,-I"%",$(subst /., ,$(wildcard $(SRCDIR)/*/.)))

COMMON_FLAGS := -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits
GFLAGS	  := -std=c90 -gdwarf-3 -mstack=compiled:auto:auto
FLAGS     := -mdfp=$(DFP_DIR) -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp $(INC)
LFLAGS    := -mwarn=-3 -Wa,-a $(COMMON_FLAGS) -std=c90 -gdwarf-3 -mstack=compiled:auto:auto
CFLAGS	  := -mwarn=-3 -Wa,-a -DXPRJ_default=default $(COMMON_FLAGS)
LD_PRE    := -Wl,-Map=$(BINDIR)/$(PROJECT_NAME).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1
LD_POST	  := -Wl,--memorysummary,$(BINDIR)/memoryfile.xml

LIB       :=

all: debug
#debug: CFLAGS += -g
debug: $(TARGET)
release: $(TARGET)
release: CFLAGS += -O3

all: $(TARGET)

clean:
	rm $(BUILDDIR) $(BINDIR) -rf

$(TARGET): $(BINDIR) $(BUILDDIR) $(OBJECTS)
	@echo "Linking object files..."
	$(CC) -mcpu=$(CPU) $(LD_PRE) $(FLAGS) $(LFLAGS) $(LD_POST) -o $(TARGET).elf $(OBJECTS) $(LIB)
	@echo "Finished building target: $(PROJECT_NAME)"

$(BUILDDIR) :
	@mkdir $(BUILDDIR)

$(BINDIR):
	@mkdir $(BINDIR)
	
$(BUILDDIR)/%.p1: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) -mcpu=$(CPU) -c $(FLAGS) $(CFLAGS) $(GFLAGS) -o $@ $<
	@mv $(basename $@).d $(basename $@).p1.d

-include $(DEPS)

.PHONY: clean all
