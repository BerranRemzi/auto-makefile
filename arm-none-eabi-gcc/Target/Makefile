PROJECT_NAME := Test103
EXTENSION := elf
CC        := arm-none-eabi-gcc
SRCDIR    := ../Src
BUILDDIR  := build
BINDIR    := bin
TARGET    := $(BINDIR)/$(PROJECT_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f \( -name *.c* -o -name *.s \))
HEDEARS   := $(shell find $(SRCDIR) -type f -name *.h*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c
FLAGS1	  := -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP
FLAGS2	  := --specs=nano.specs -mfloat-abi=soft -mthumb
ASFLAGS   := -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP
LIB       :=
INC 	  := $(patsubst %,-I%,$(shell find $(SRCDIR) -type d))
LD		  := STM32F103C8TX_FLASH.ld

all: debug
#debug: CFLAGS += -g
debug: $(TARGET)
release: $(TARGET)
release: CFLAGS += -O3

rebuild: 
	$(MAKE) clean
	$(MAKE) all
    
all: $(TARGET)
	arm-none-eabi-size "$(TARGET).$(EXTENSION)"
	arm-none-eabi-objdump -h -S "$(TARGET).$(EXTENSION)" > "$(TARGET).list"
	@echo Finished building: $(PROJECT_NAME).list

clean:
	@rm $(BUILDDIR) $(BINDIR) -rf

$(TARGET): $(BINDIR) $(BUILDDIR) $(OBJECTS)
	@echo "Linking object files..."
	$(CC) -o "$(TARGET).$(EXTENSION)" $(OBJECTS) $(LIB) -T"$(SRCDIR)/$(LD)" --specs=nosys.specs -Wl,-Map="$(BINDIR)/$(PROJECT_NAME).map" -Wl,--gc-sections -static $(FLAGS2) -Wl,--start-group -lc -lm -Wl,--end-group
	@echo "Finished building target: $(PROJECT_NAME)"

$(BUILDDIR) :
	@mkdir $(BUILDDIR)

$(BINDIR):
	@mkdir $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) "$<" $(CFLAGS) $(INC) $(FLAGS1) -MF"$(@:.o=.d)" -MT"$@" $(FLAGS2) -o "$@"
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.s
	$(CC) $(ASFLAGS) -MF"$(@:.o=.d)" -MT"$@" $(FLAGS2) -o "$@" "$<"
	

-include $(DEPS)

.PHONY: clean all
