unsigned int Disabled=0, AutoBegin = 1, TeleStart = 2, SpinUp = 3, SpinDown = 4, Fire = 5, Red = 6, Blue = 7;
typedef int Mode;
class Blinker{
public:
	Blinker(): num_outputs(3){
		outputs = new DigitalOutput*[num_outputs];
		//outputs 1, 2, 3.
		for(int i=0;i<num_outputs;i++){
			outputs[i]=new DigitalOutput(i+1);
		}
	}
private:
	DigitalOutput** outputs;
public:
	const int num_outputs;
	void send(Mode in){
		//write(in);
	}
	void write(Mode in){
		write(in);
	}
	void write(bool v1, bool v2, bool v3){
		outputs[0]->Set(v1);
		outputs[1]->Set(v2);
		outputs[2]->Set(v3);
	}
	void write(unsigned int val){
		bool b1 = val%2;
		bool b2 = (val/2)%2;
		bool b3 = (val/4)%2;
		write(b1,b2,b3);
	}
};
