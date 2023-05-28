CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
SOURCES=s21_create_matrix.c \
	s21_calc_complements.c \
    s21_determinant.c \
	s21_eq_matrix.c \
	s21_inverse_matrix.c \
	s21_mult_matrix.c \
	s21_mult_number.c \
	s21_remove_matrix.c \
	s21_sub_matrix.c \
	s21_sum_matrix.c \
	s21_transpose.c
OBJECTS=$(SOURCES:.c=.o)
OS = $(shell uname)
TEST_FILE_NAME = test.c
LIB = s21_matrix.a

ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
endif

all: $(LIB) test gcov_report

s21_matrix.a: $(OBJECTS)
	ar rc s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

style:
	cp ../materials/linters/.clang-format ../src/.clang-format; \
	clang-format -style=Google -n *.c *.h; \
	rm .clang-format

test: $(TEST_FILE_NAME) s21_matrix.a
	$(CC) $(CFLAGS) $(TEST_FILE_NAME) $(SOURCES) -o test $(TEST_LIBS) -L. --coverage
	./test

gcov_report: test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM

install lcov:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
