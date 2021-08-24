CC = g++
# Extension #
EXT = cpp
# Flags #
CFLAGS = -Wall -g
# Object Files #
OBJECTS = ../../bin/unit_tests.o ../../bin/unit_stock.o ../../bin/unit_flow.o ../../bin/unit_model.o
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

dlls: $(DLLS) $(OBJECTS) using_dll 

model_lib.dll: 
	$(CC) -shared $(SRC_DIR)/model_impl.cpp -o $(BIN_DIR)/model_lib.dll

stock_lib.dll: 
	$(CC) -shared $(SRC_DIR)/stock_impl.cpp -o $(BIN_DIR)/stock_lib.dll

flow_lib.dll: 
	$(CC) -shared $(SRC_DIR)/flow_impl.cpp -o $(BIN_DIR)/flow_lib.dll

using_dll:
	$(CC) main.cpp -L$(BIN_DIR) $(LIBS) $(OBJECTS) -o $(BIN_DIR)\$(EXE).exe

$(BIN_DIR)/unit_tests.o: unit_tests.$(EXT)
	$(CC) -c unit_tests.$(EXT) -o $(BIN_DIR)/unit_tests.o

$(BIN_DIR)/unit_model.o: unit_model.$(EXT)
	$(CC) -c unit_model.$(EXT) -o $(BIN_DIR)/unit_model.o

$(BIN_DIR)/unit_stock.o: unit_stock.$(EXT)
	$(CC) -c unit_stock.$(EXT) -o $(BIN_DIR)/unit_stock.o

$(BIN_DIR)/unit_flow.o: unit_flow.$(EXT)
	$(CC) -c unit_flow.$(EXT) -o $(BIN_DIR)/unit_flow.o

# DELETE/CLEAN
.PHONY : clean remove info
clean:
	del -f $(BIN_DIR)*.o

remove:
	rm -f $(OBJECTS)

info:
	@echo "Trabalho Pratico Engenharia de Software -> $@"
	@echo "Aluno Rafael Coelho Monte Alto          -> author"
