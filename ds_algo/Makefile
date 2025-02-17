BUILD_DIR = build
SRC_DIR = ./

MAIN_FILE = $(SRC_DIR)/main.cpp
GRAPH_FILE = $(SRC_DIR)/graph.cpp
GRAPH_OBJ = $(BUILD_DIR)/graph.o

all: run

# Compile graph.cpp to object file
$(GRAPH_OBJ): $(GRAPH_FILE)
	g++ -c $(GRAPH_FILE) -o $@

# Link object files to create executable
$(BUILD_DIR)/a.out: $(GRAPH_OBJ) $(MAIN_FILE)
	g++ -o $@ $(GRAPH_OBJ) $(MAIN_FILE)

# Create debug executable
debug: $(GRAPH_OBJ) $(MAIN_FILE)
	g++ -g $(MAIN_FILE) $(GRAPH_OBJ) -o $(BUILD_DIR)/debug.out

# Run the executable
run: $(BUILD_DIR)/a.out
	./$(BUILD_DIR)/a.out

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
