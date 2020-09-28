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
		virtual Signal output() = 0;
	protected:
		Signal _input1;
		Signal _input2;
	private:
		Gate* _to_gate;
		Pin _to_pin;
};

class And : public Gate
{
	public:
		Signal output() override {return _input1 && _input2;}
};

class Or : public Gate
{
	public:
		Signal output() override {return _input1 || _input2;}
};

#endif
