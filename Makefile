CC=g++
CFLAGS=-I include -Wall
OBJS= main.o cards.o cutscenes.o utils.o engine.o
BUILD_DIR = build

start: $(BUILD_DIR)/redscape
	$(BUILD_DIR)/redscape

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

$(BUILD_DIR)/utils.o: src/utils.cpp
	$(CC) $(CFLAGS) -c src/utils.cpp -o $@

$(BUILD_DIR)/engine.o: src/engine.cpp
	$(CC) $(CFLAGS) -c src/engine.cpp -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/redscape
