#ifndef __GATE_H
#define __GATE_H

typedef int Pin;
typedef bool Signal;

class Gate
{
	public:
		Gate();
		void connect(Gate& gate, Pin input_pin);
		void input(Pin pin, Signal signal);
		Signal input(Pin pin);
		Signal output();
	private:
		Signal _input1;
		Signal _input2;
		Gate* to_gate;
		Pin to_pin;
};

class And : public Gate
{
	public:
		Signal output();
};

class Or : public Gate
{
	public:
		Signal output();
};

#endif
