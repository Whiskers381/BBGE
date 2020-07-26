# BBGE
## Description
Bases Between Given Exponents (BBGE) is an esoteric, non-Turing complete language dedicated to printing the results of problems of the nature: “Output all bases between these bounds for which the product of raising the base(s) to a given exponent is also a whole number for which another base can be raised to a second exponent”. Hence Bases Between Given Exponents(BBGE).
## BNF
<program>		::=
					<bases><between><given><exponents>
<bases>			::=
					b
<between> 		::=
					<lowerBound>“-”<upperBound>
<lowerBound> 	::=
					<numberValue>
<upperBound> 	::=
					<numberValue>
<given> 		::=
					"^"
<exponents> 	::=
					<exponent><exponent>
<exponent> 		::=
					<numberValue>e
<numberValue> 	::=
					<digit>
					|<digit><numberValue>
<digit> 		::=
					0|1|2|3|4|5|6|7|8|9