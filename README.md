# Hypercut
Hypercut is the implementation of paper [Packet Classification Using Multidimensional Cutting](http://cseweb.ucsd.edu/~susingh/papers/hyp-sigcomm03.pdf).

Original source code is from [Evaluation of Packet Classification Algorithms](http://www.arl.wustl.edu/~hs1/PClassEval.html).

Throughput test is added by Kun as marked.

# Usage
./hypercut [-s space-factor] [-b bucket-size] [-d] [-p filter-push-levels] [-r filter-set] [-t header-trace]

Due to the big memory usage when dealing with large filters(e.g. fw1_10K), "-p" is recommended to use.
