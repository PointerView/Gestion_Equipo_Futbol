#########################
# DATOS DE COMPILACIÓN
#########################

TARGET := main




#########################
# OPCIONES DE COMPILACIÓN
#########################


CC     := g++
CFLAGS := -g '-std=c++17'



########################
# FICHEROS
########################

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o, $(SRC))
DEP := $(OBJ)



$(TARGET): $(DEP)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: info clean

info:
	$(info Source files: $(SRC))
	$(info Object files: $(OBJ))

clean:
	$(RM) $(OBJ)
