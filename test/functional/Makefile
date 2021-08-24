CC = g++
# Extension #
EXT = cpp
# Flags #
CFLAGS = -Wall -g
# Dynamic Link Libraries #
DLLS = stock_lib.dll flow_lib.dll  model_lib.dll
# Libraries #
LIBS = -lstock_lib -lflow_lib -lmodel_lib 
# Executable # 
EXE = test
# Source directory #
SRC_DIR = ../../src
# Bin directory #
BIN_DIR = ../../bin

# dlls: $(DLLS) functional using_dll 
dlls: system_dll functional exec_dll 

exec_dll:
	$(CC) main.cpp -L$(BIN_DIR) -lsystem_lib $(BIN_DIR)/functional_tests.o -o $(BIN_DIR)\$(EXE).exe

system_dll:
	$(CC) -shared $(SRC_DIR)/stock_impl.cpp $(SRC_DIR)/flow_impl.cpp $(SRC_DIR)/model_impl.cpp -o $(BIN_DIR)/system_lib.dll

model_lib.dll: 
	$(CC) -shared $(SRC_DIR)/model_impl.cpp -o $(BIN_DIR)/model_lib.dll

stock_lib.dll: 
	$(CC) -shared $(SRC_DIR)/stock_impl.cpp -o $(BIN_DIR)/stock_lib.dll

flow_lib.dll: 
	$(CC) -shared $(SRC_DIR)/flow_impl.cpp -o $(BIN_DIR)/flow_lib.dll

using_dll:
	$(CC) main.cpp -L$(BIN_DIR) $(LIBS) $(BIN_DIR)/functional_tests.o -o $(BIN_DIR)\$(EXE).exe

functional: functional_tests.$(EXT)
	$(CC) -c functional_tests.$(EXT) -o $(BIN_DIR)/functional_tests.o