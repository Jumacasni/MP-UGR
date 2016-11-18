CXX=g++
CXXFLAGS=-I$(INC) -Wall -g
INC=include/
SRC=src/
OBJ=obj/
BIN=bin/

$(BIN)conecta: $(OBJ)conecta.o $(OBJ)jugador.o $(OBJ)matriz.o $(OBJ)tablero.o
	$(CXX) -o $(BIN)conecta $(OBJ)conecta.o $(OBJ)jugador.o $(OBJ)matriz.o $(OBJ)tablero.o

$(OBJ)jugador.o: $(INC)jugador.h $(INC)tablero.h $(SRC)jugador.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)jugador.o $(SRC)jugador.cpp

$(OBJ)conecta.o: $(INC)jugador.h $(SRC)conecta.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)conecta.o $(SRC)conecta.cpp

$(OBJ)matriz.o: $(INC)matriz.h $(SRC)matriz.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)matriz.o $(SRC)matriz.cpp

$(OBJ)tablero.o: $(INC)tablero.h $(INC)matriz.h $(SRC)tablero.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)tablero.o $(SRC)tablero.cpp

clean:
	echo "Limpiando ..."
	rm $(OBJ)/*.o

mrproper:
	rm $(BIN)/conecta
