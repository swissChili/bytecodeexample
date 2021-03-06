===========
Bytecodelib
===========
A libary for generating, and parsing bytecode designed for use in high-level virtual machines.


Bytecode Specification
----------------------
Bytecode in this library is split into different commands. Each command consists of a call, an integer value
corresponding to it's function (this is, of course dependent on the usage of the bytecode, in a virtual machine
for instance a certain call with the ID of ``1`` may be used to push an item to the stack.)

Each call must consist of exactly one byte, no more, and no less is permitted. For instance, the above example
of pushing an integer to the stack may look something like this, represented in an arbitrary plain-text format::
	CALL 1
		ARG 23
It is worth noting that a similar format is used by this library for displaying such structures for debugging
purposes. Here is how this command would be represented in bytecode::
	0x01 0x17
(this is hexadecimal so 17 = 16 + 7, so 23).

This is pretty much what you'd expect, but things get slightly more complicated with more arguments. Let's say
for instance this is a register based virtual machine, and the user would like to push the integer ``23`` to the
1st register. This would look something like::
	CALL 1
		ARG 1
		ARG 23
Where the first argument is the register, and the second is the quantity to push to it. This would be represented
as the following bytecode::
	0x01 0x02 0x00 0x18 0x00 0x00
The first byte ``0x01`` is the call, and since it must take precisely one byte, the second byte must be an argument.
Note that the byte is actually ``0x02`` not ``0x01`` because, since ``0x00`` is reserved, all the values are shifted
down by one. In other words, what used to be 1 is now 0.

The third byte is a null byte used to separate arguments. The fourth byte is again an argument equal to 23.
The fifth and sixth bytes are both null signifying an end of command. After this other commands' bytes could be
inserted afterwards and the parser would know when one command ends and another begins.