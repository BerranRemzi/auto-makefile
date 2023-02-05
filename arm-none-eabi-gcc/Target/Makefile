PROJECT_NAME := example-project
CC        := arm-none-eabi-gcc
SRCDIR    := ../Src
BUILDDIR  := build
BINDIR    := bin
TARGET    := $(BINDIR)/$(PROJECT_NAME)
SOURCES   := $(shell find $(SRCDIR) -type f -name *.c*)
HEDEARS   := $(shell find $(SRCDIR) -type f -name *.h*)
OBJECTS   := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .o,$(basename $(SOURCES))))
DEPS      := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(addsuffix .d,$(basename $(SOURCES))))
CFLAGS    := -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c
FLAGS1	  := -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP
FLAGS2	  := --specs=nano.specs -mfloat-abi=soft -mthumb

LIB       :=
#INC		  := $(patsubst %,-I%,$(subst /., ,$(wildcard $(SRCDIR)/*/.)))
INC 	  := $(patsubst %,-I%,$(shell find $(SRCDIR) -type d))

all: debug
#debug: CFLAGS += -g
debug: $(TARGET)
release: $(TARGET)
release: CFLAGS += -O3

GREEN=#'tput setaf 2`
RESET=#`tput sgr0`

define print_green
	@echo "$(GREEN)$(1)$(RESET)"
endef

rebuild: 
	$(MAKE) clean
	clear
	$(MAKE) all
    
all: $(TARGET)

clean:
	rm $(BUILDDIR) $(BINDIR) -rf

$(TARGET): $(BINDIR) $(BUILDDIR) $(OBJECTS)
	$(call print_green,"Linking object files...")
	@$(CC) $(OBJECTS) -o $(TARGET) $(LIB)
	$(call print_green,"Finished building target: $(PROJECT_NAME)")

$(BUILDDIR) :
	mkdir $(BUILDDIR)

$(BINDIR):
	mkdir $(BINDIR)
	
$(BUILDDIR)/%.o: $(SRCDIR)/%.c*
	@mkdir -p $(dir $@)
	$(CC) "$<" $(CFLAGS) $(INC) $(FLAGS1) -MF"$(@:.o=.d)" -MT"$@" $(FLAGS2) -o "$@"
	@$(CC) $(CFLAGS) $(INC) -M $< -MT $@ > $(@:.o=.td)
	@cp $(@:.o=.td) $(@:.o=.d); 
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.td) >> $(@:.o=.d); 
	@rm -f $(@:.o=.td)


-include $(DEPS)

.PHONY: clean all
