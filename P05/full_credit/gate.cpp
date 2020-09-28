#include <iostream> 
#include "gate.h"

Gate::Gate() : _input1{1}, _input2{1},_to_pin{1}
{

}

void Gate::connect(Gate& gate, Pin input_pin)
{
	_to_gate = &gate;
	_to_pin = input_pin;
}

Signal Gate::input(Pin pin)
{
	if(pin==1)
		return _input1;
	else
		return _input2;
}

void Gate::input(Pin pin, Signal signal)
{
	if(pin==1)
		_input1 = signal;
	else
		_input2 = signal;

	if(_to_gate != NULL){}//do nothing
	else
	{
		_to_gate->input(_to_pin,output());
	}
}


