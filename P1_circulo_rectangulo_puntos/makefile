AR=ar
CXX=g++
CXXFLAGS=-I$(INC) -Wall -g
LDFLAGS=-Llib/
LDLIBS=-lformas
INC=include/
SRC=src/
OBJ=obj/
LIB=lib/
BIN=bin/

all: $(BIN)central $(BIN)area $(BIN)longitud $(BIN)delimitar

$(BIN)central: $(OBJ)central.o $(LIB)libformas.a
	$(CXX) -o $(BIN)central $(OBJ)central.o $(LDFLAGS) $(LDLIBS)

$(BIN)area: $(OBJ)area.o $(LIB)libformas.a
	$(CXX) -o $(BIN)area $(OBJ)area.o $(LDFLAGS) $(LDLIBS)

$(BIN)longitud: $(OBJ)longitud.o $(LIB)libformas.a
	$(CXX) -o $(BIN)longitud $(OBJ)longitud.o $(LDFLAGS) $(LDLIBS)

$(BIN)delimitar: $(OBJ)delimitar.o $(LIB)libformas.a
	$(CXX) -o $(BIN)delimitar $(OBJ)delimitar.o $(LDFLAGS) $(LDLIBS)

$(OBJ)central.o: $(INC)punto.h $(INC)circulo.h $(SRC)circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)central.o $(SRC)central.cpp

$(OBJ)delimitar.o: $(INC)punto.h $(INC)rectangulo.h $(SRC)delimitar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)delimitar.o $(SRC)delimitar.cpp

$(OBJ)punto.o: $(INC)punto.h $(SRC)punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)punto.o $(SRC)punto.cpp

$(OBJ)circulo.o: $(INC)punto.h $(INC)circulo.h $(SRC)circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)circulo.o $(SRC)circulo.cpp

$(OBJ)rectangulo.o: $(INC)punto.h $(INC)rectangulo.h $(SRC)rectangulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)rectangulo.o $(SRC)rectangulo.cpp

$(OBJ)longitud.o: $(INC)punto.h $(SRC)longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)longitud.o $(SRC)longitud.cpp

$(OBJ)area.o: $(INC)circulo.h $(SRC)area.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)area.o $(SRC)area.cpp

$(LIB)libformas.a: $(OBJ)punto.o $(OBJ)circulo.o $(OBJ)rectangulo.o
	$(AR) rvs $(LIB)libformas.a $(OBJ)punto.o $(OBJ)circulo.o $(OBJ)rectangulo.o

clean:
	echo "Limpiando ..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper:
	rm $(BIN)/central
