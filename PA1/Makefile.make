all: test
test: test.cpp Stack.h ArrayStack.h DoublingArrayStack.h LinkedStack.h Timer.h
	g++ test.cpp