
CXX = g++

CXX_FLAGS = -c -I include/


BUILD_DIR = build

SRC_DIR = src

SRCS = ${SRC_DIR}/main.cpp \
		${SRC_DIR}/AbstractExpression.cpp \
		${SRC_DIR}/Terminal.cpp \
		${SRC_DIR}/NonTerminal.cpp \
		${SRC_DIR}/Scanner.cpp \

OBJS = ${BUILD_DIR}/AbstractExpression.o \
		${BUILD_DIR}/Terminal.o \
		${BUILD_DIR}/NonTerminal.o \
		${BUILD_DIR}/Scanner.o

all: ${BUILD_DIR}/main.o

${BUILD_DIR}:
	mkdir -p build

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${OBJS}
	${CXX} $^ -I include/ -o $@ 

${BUILD_DIR}/NonTerminal.o: ${BUILD_DIR}/AbstractExpression.o ${SRC_DIR}/NonTerminal.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Terminal.o: ${BUILD_DIR}/AbstractExpression.o ${SRC_DIR}/Terminal.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Scanner.o: ${BUILD_DIR}/AbstractExpression.o ${SRC_DIR}/Scanner.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/AbstractExpression.o: ${SRC_DIR}/AbstractExpression.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@
