SOURCE_FOLDER=./src
MATH_FOLDER=$(SOURCE_FOLDER)/math
INCLUDES_FOLDER=./src/includes
TEST_FOLDER=./tests/src
BUILD_FOLDER=./tests/.build
TEMPORAL_FOLDER=./tests/.temp
TEST_OUTPUT_NAME=cmlMainTest


#################################
# Compilation options
#################################
# Optimization: -O0 baja, -O1 normal, -O2 optimizado, -O3 alta
# Show all warnings
# Compiles in gnu11 std
CFLAGS=-O3 -Wall -std=gnu11

# Uncomment to debug
DEBUG=-g

##################################
# Rules

.PHONY:	all clean folders test
all:	folders c.o

c.o:
	gcc $(TEST_FOLDER)/main.c $(SOURCE_FOLDER)/core.c $(MATH_FOLDER)/oop/Field.c $(MATH_FOLDER)/oop/Real.c $(MATH_FOLDER)/oop/Rational.c $(MATH_FOLDER)/oop/Complex.c $(MATH_FOLDER)/usefull_functions.c $(MATH_FOLDER)/general_functions.c $(MATH_FOLDER)/euclidean_trigonometry.c $(MATH_FOLDER)/non_euclidean_trigonometry.c $(MATH_FOLDER)/euclidean_geometry.c $(MATH_FOLDER)/non_euclidean_geometry.c $(MATH_FOLDER)/calculus.c -o $(BUILD_FOLDER)/$(TEST_OUTPUT_NAME) $(CFLAGS) $(DEBUG)


clean:
	rm -rf $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

folders:
	-mkdir $(TEMPORAL_FOLDER) $(BUILD_FOLDER)

test:
	$(BUILD_FOLDER)/$(TEST_OUTPUT_NAME)
