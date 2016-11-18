SRC = src
INC = include
OBJ = obj

CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)


# ************ Compilación de módulos ************
all: ocultar revelar

ocultar: $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o
	$(CXX) -o ocultar $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o

revelar: $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o
	$(CXX) -o revelar $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o

$(OBJ)/ocultar.o: $(INC)/codificar.h $(INC)/imagenES.h $(SRC)/ocultar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/ocultar.o $(SRC)/ocultar.cpp

$(OBJ)/revelar.o: $(INC)/codificar.h $(INC)/imagenES.h $(SRC)/revelar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/revelar.o $(SRC)/revelar.cpp

$(OBJ)/codificar.o: $(INC)/codificar.h $(INC)/imagenES.h $(SRC)/codificar.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/codificar.o $(SRC)/codificar.cpp

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
