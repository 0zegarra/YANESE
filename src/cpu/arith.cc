// File contains all logical and arithmetic commands defined by the 6502 instruction set

void ORA(byte M[addr]) {
	A = A | M[addr];
}

void AND(byte M[addr]) {
	A = A & M[addr];
}

void EOR(byte M[addr]) {
	A = A ^ M[addr];
} 

void ADC(byte M[addr]) {
	A = A + M[addr];
}

void SBC(byte M[addr]) {
	A = A - M[addr]; // TODO: Figure out semantics of minus
}

void DEC(byte M[addr]) {
	M[addr] = M[addr] - 1;
}

void DEX(byte M[addr]) {
	X = X - 1;
}

void DEY(byte M[addr]) {
	Y = Y - 1;
}


// ...
