APP_NAME = main
CFLAGS = -Wall
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS = 

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)


SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR).$(SRC_EXT)=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(APP_PATH)

$(APP_PATH): $(APP_OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS) 

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

	
.PHONY: clean
clean:
	$(RM) $(APP_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

.PHONY: run
run:
	./$(APP_PATH)
