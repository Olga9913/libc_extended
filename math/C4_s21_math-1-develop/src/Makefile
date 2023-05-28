CC =gcc
FLAG_C = -c
FLAG_O = -o
CFLAGS =-Wall -Werror -Wextra -pedantic -std=c11
GCOVF =-fprofile-arcs -ftest-coverage

all: s21_gcov_math.a test gcov_report

clean:
	rm -rf *.o *.a test *.out *.gcda *.gcno *.html *.css tests_s21_math.c

test: s21_gcov_math.a tests_s21_math.c
	$(CC) $(CFLAGS) $(GCOVF) -lcheck $? $(FLAG_O) $@

tests_s21_math.c:
	checkmk tests_s21_math > $@

s21_gcov_math.a: s21_*.c
	$(CC) $(CFLAGS) $(GCOVF) $(FLAG_C) $?
	ar -rcs $@ *.o
	rm -f *.o

s21_math.a: s21_*.c
	$(CC) $(FLAG_C) $(CFLAGS) $?
	ar -rcs $@ *.o
	rm -f *.o

rebuild: clean all

gcov_report: test
	./$?
	gcovr -r . --html --html-details $(FLAG_O) coverage_report.html
	rm -f *.gcda *.gcno
	open coverage_report.html

linter:
	python3 ../materials/linters/cpplint.py *.c *.h
