PROJECT_NAME := PWM_Limiter.X.production
CC        := "C:/Tools/Microchip/xc8/v2.40/bin/xc8-cc.exe"
DFP       := "C:/Tools/Microchip/MPLABX/v6.00/packs/Microchip/PIC10-12Fxxx_DFP/1.5.61/xc8"
CPU       := 10F322
SRCDIR    := src
BUILDDIR  := build/default/production/src
BINDIR    := dist/default/production
TARGET    := $(BINDIR)/$(PROJECT_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f \( -name *.c* -o -name *.s \))
HEDEARS   := $(shell find $(SRCDIR) -type f -name *.h*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .p1,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -mdfp=$(DFP) -fno-short-double -fno-short-float -O2 -fasmfile -maddrqual=ignore -xassembler-with-cpp
FLAGS	  := -mwarn=-3 -Wa,-a -DXPRJ_default=default -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto
FLAGS1    := -Wl,-Map=$(BINDIR)/$(PROJECT_NAME).map -DXPRJ_default=default -Wl,--defsym=__MPLAB_BUILD=1
FLAGS2	  := -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto -Wl,--memorysummary,$(BINDIR)/memoryfile.xml
LIB       :=
INC       := $(patsubst %,-I"%",$(subst /., ,$(wildcard $(SRCDIR)/*/.)))


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
	$(CC) -mcpu=$(CPU) $(FLAGS1) $(CFLAGS) $(INC) $(FLAGS2) -o $(TARGET).elf $(OBJECTS) $(LIB)
	@echo "Finished building target: $(PROJECT_NAME)"

$(BUILDDIR) :
	@mkdir $(BUILDDIR)

$(BINDIR):
	@mkdir $(BINDIR)
	
$(BUILDDIR)/%.p1: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) -mcpu=$(CPU) -c $(CFLAGS) $(INC) $(FLAGS) -o $@ $<
	@mv $(basename $@).d $(basename $@).p1.d

-include $(DEPS)

.PHONY: clean all
