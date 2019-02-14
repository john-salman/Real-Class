Assignment: CS460 Homework 4

Author: John Salman

What works: Everything that was specified, all operators have been tested extensively. 

What doesn't work: Tryed to find all possible edge cases, some may still allude me.

Issues encountered (and resolved):
       Numerous logic errors, most recent was an accidental add by 1 that pushed the unsigned chars into uncharted territory (modification of (current + carry > 9) -> (current > 9).
       Made multiply() capable of modifying parameters, inducing errors after return from recursion (change from (multiply(Real &self, Real &other)) -> (multiply(const Real &_self, const Real &_other)).
       Tryed to utilize memcmp() in numerous bool function, before I realized the gaps in the logic.
