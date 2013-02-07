Quantum Random Bit Generator Service
====================================

The work on `QRBG Service`_ has been motivated by scientific necessity
(primarily of local scientific community) of running various simulations, whose
results are often greatly affected by quality (distribution, nondeterminism,
entropy, etc.) of used random numbers. Since true random numbers are impossible
to generate with a finite state machine (such as today's computers), scientists
are forced to either use specialized expensive hardware number generators, or,
more frequently, to content themselves with suboptimal solutions (like
pseudo-random numbers generators). 

The Service has begun as a result of an attempt to fulfill the scientists' needs
for quality random numbers, but has now grown to a global (public) high-quality
random numbers service. 

Design requirements for our service [1]_ were:

- true randomness of data served (high per-bit-entropy of served data) 
- high speed of data generation and serving 
- high availability of the service (including easy and transparent access to
  random data),
- great robustness of the service, and 
- high security for users that require it. 

So far, all these features, except the last one, have been implemented. And the
solution developed tops other currently available random number acquisition
methods (including existing Internet services) in at least one of the numbered
categories. 

To ensure high-quality of the supplied random numbers (true randomness) and high
speed of serving, we have used fast non-deterministic, stand-alone hardware
number generator relying on photonic emission in semiconductors. The used
`Quantum Random Bit Generator`_ was previously developed at Rudjer Boskovic
Institute, in Laboratory for Stochastic Signals and Process Research.


QRBG C++ Client
---------------

The C++ interface to QRBG service is provided through ``QRBG`` class, as defined
in `src`_.


Installation
------------

The library can be directly linked with your source, or it can be compiled and
installed as a shared Linux library (``libqrbgcpp.so``).

To install as a shared lib, you should have ``autotools`` and ``libtool``
installed. The library build and install is then simple::

   $ git clone https://github.com/randomir/qrbg-cpp
   $ cd qrbg-cpp
   $ ./autogen.sh
   $ ./configure && make
   $ sudo make install


Example Usage
-------------

.. code-block:: c++

    #include "QRBG.h"
    
    int main() {
        QRBG rndService;
        rndService.defineServer("random.irb.hr", 1227);
        rndService.defineUser("username", "password");
    
        int a = rndService.getInt();
        double b = rndService.getDouble();
    }

For more examples, see `test`_.


Build
-----

You can embed the library, or link it with a system-wide shared lib. To
illustrate, we'll build ``example0.cpp``::

    $ cd test
    $ g++ -Wall -O6 example0.cpp ../src/*.cpp -I ../src -o example0.out

or, use ``make``::

    $ make linked

To link it with shared library::

    $ g++ -Wall -O6 example0.cpp -l qrbgcpp  -o example0.out

or::

    $ make shared


Copyright and License
---------------------

QRBG service C++ library is Copyright (c) 2007 Radomir Stevanovic and Rudjer
Boskovic Institute. Licensed under the MIT license. See the LICENSE file for
full details.


.. _`QRBG Service`: http://random.irb.hr/

.. _`Quantum Random Bit Generator`: http://qrbg.irb.hr/

.. [1] R. Stevanovic, G. Topic, K. Skala, M. Stipcevic and B.M. Rogina,
       "Quantum Random Bit Generator Service for Monte Carlo and Other
       Stochastic Simulations," in Lecture Notes in Computer Science, Vol. 4818,
       I. Lirkov, S. Margenov, J. Wasniewski (Eds.), Springer-Verlag: Berlin
       Heidelberg, 2008, pp. 508-515. (http://www.springer.com/computer/theoretical+computer+science/book/978-3-540-78825-6)

.. _`src`: https://github.com/randomir/qrbg-cpp/tree/master/src

.. _`test`: https://github.com/randomir/qrbg-cpp/tree/master/test
