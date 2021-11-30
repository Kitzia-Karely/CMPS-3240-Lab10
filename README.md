# Lab-10

Average run time (of three trials) of a totally unoptimized FAXPY:
```shell
$ for i in {1..3}; do time ./faxpy.out; done;
Running FAXPY operation of size 2000000 

real	0m0.017s
user	0m0.017s
sys	0m0.000s
Running FAXPY operation of size 2000000 

real	0m0.017s
user	0m0.013s
sys	0m0.004s
Running FAXPY operation of size 2000000 

real	0m0.016s
user	0m0.012s
sys	0m0.004s
```
Average run time of loop unrolled (x2) FAXPY
```shell
for i in {1..3}; do time ./faxpy.out; done;
Running FAXPY operation of size 2000000 

real	0m0.013s
user	0m0.008s
sys	0m0.005s
Running FAXPY operation of size 2000000 

real	0m0.009s
user	0m0.009s
sys	0m0.000s
Running FAXPY operation of size 2000000 

real	0m0.014s
user	0m0.013s
sys	0m0.000s
```
Average run time of SIMD (SSE2) FAXPY
```shell
for i in {1..3}; do time ./faxpy.out; done;
Running FAXPY operation of size 2000000 

real	0m0.013s
user	0m0.004s
sys	0m0.009s
Running FAXPY operation of size 2000000 

real	0m0.013s
user	0m0.013s
sys	0m0.000s
Running FAXPY operation of size 2000000 

real	0m0.014s
user	0m0.010s
sys	0m0.004s
```
Average run time of loop unrolled (x2) and SIMD (SSE2) FAXPY
```shell
for i in {1..3}; do time ./faxpy.out; done;
Running FAXPY operation of size 2000000 

real	0m0.016s
user	0m0.012s
sys	0m0.004s
Running FAXPY operation of size 2000000 

real	0m0.009s
user	0m0.008s
sys	0m0.000s
Running FAXPY operation of size 2000000 

real	0m0.009s
user	0m0.008s
sys	0m0.000s


