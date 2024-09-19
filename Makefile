CC=g++
CFLAGS=-I include
OBJS= main.o cards.o cutscenes.o
BUILD_DIR = build

all: $(BUILD_DIR) $(addprefix $(BUILD_DIR)/, $(OBJS))
	$(CC) -o $(BUILD_DIR)/redscape $(addprefix $(BUILD_DIR)/, $(OBJS))

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/cards.o: src/cards.cpp
	$(CC) $(CFLAGS) -c src/cards.cpp -o $@

$(BUILD_DIR)/cutscenes.o: src/cutscenes.cpp
	$(CC) $(CFLAGS) -c src/cutscenes.cpp -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/redscape
