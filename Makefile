SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c 

all:$(BIN)/letras

$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Bolsa_letras.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Bolsa_letras.o $(OBJ)/Letra.o

$(OBJ)/letras.o: $(SRC)/letras.cpp $(INC)/Diccionario.h $(INC)/Bolsa_letras.h
	$(CXX) $(CPPFLAGS) $(SRC)/letras.cpp -o $(OBJ)/letras.o -I$(INC)

# ************ Cantidad de letras *************
testdiccionario:$(BIN)/testdiccionario

$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/testdiccionario.cpp -o $(OBJ)/testdiccionario.o -I$(INC)

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o -I$(INC)

# ************ Cantidad de letras *************
cantidad:$(BIN)/cantidad_letras

$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Bolsa_letras.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Bolsa_letras.o $(OBJ)/Letra.o

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp $(INC)/Diccionario.h $(INC)/Bolsa_letras.h
	$(CXX) $(CPPFLAGS) $(SRC)/cantidad_letras.cpp -o $(OBJ)/cantidad_letras.o -I$(INC)

$(OBJ)/Bolsa_letras.o: $(SRC)/Bolsa_letras.cpp $(INC)/Bolsa_letras.h $(INC)/Letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/Bolsa_letras.cpp -o $(OBJ)/Bolsa_letras.o -I$(INC)

$(OBJ)/Letra.o: $(SRC)/Letra.cpp $(INC)/Letra.h
	$(CXX) $(CPPFLAGS) $(SRC)/Letra.cpp -o $(OBJ)/Letra.o -I$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxygen


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
