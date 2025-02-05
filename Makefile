
CXX = g++

CXX_FLAGS = -c -I include/


BUILD_DIR = build

SRC_DIR = src

SRCS = ${SRC_DIR}/main.cpp \
		${SRC_DIR}/AbstractExpression.cpp \
		${SRC_DIR}/Terminal.cpp

OBJS = ${BUILD_DIR}/AbstractExpression.o \
		${BUILD_DIR}/Terminal.o

all: ${BUILD_DIR}/main.o

${BUILD_DIR}:
	mkdir -p build

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${OBJS}
	${CXX} $^ -I include/ -o $@ 

${BUILD_DIR}/NonTerminal.o: ${BUILD_DIR}/AbstractExpression.o ${SRC_DIR}/NonTerminal.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@

${BUILD_DIR}/Terminal.o: ${BUILD_DIR}/AbstractExpression.o ${SRC_DIR}/Terminal.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@


${BUILD_DIR}/AbstractExpression.o: ${SRC_DIR}/AbstractExpression.cpp
	${CXX} ${CXX_FLAGS} $^ -o $@
