// The frequecy of the CPU
const int Frequency = 1790000;

typedef uint8_t register;

typedef uint16_t special_register;

class CPU() {
	CPU();
	// Run the cpu with the given program. A program is represented by a vector of instructions.
	void Run();

private:
	// The NES CPU is 17.9 MgHZ frequency
	const int frequency_ = 1790000;

	// General purpose registers
	register A_;
	register X_;
	register Y_;

	register P_;
	register SP_;
	special_register PC_;

	// Memory contains the memory of the program.
	unordered_map<byte, byte> M;
}
