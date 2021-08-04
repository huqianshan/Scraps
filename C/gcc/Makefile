all: dotproductstandard dotproduct builtin
dotproductstandard: dotproduct.c benchmark.h
	cc -O3 -o dotproductstandard dotproduct.c -march=native 
dotproduct: dotproduct.c benchmark.h
	cc -O3 -o dotproduct dotproduct.c -march=native -ffp-contract=off
#-ffast-math
builtin: builtin.c 
	cc -O3 -o builtin builtin.c -march=native -ffp-contract=off

test:dotproduct
	./dotproduct

clean:
	rm -r -f dotproduct dotproductstandard builtin