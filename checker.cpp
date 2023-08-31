#include <iostream>
#include <assert.h>
#include <unistd.h>

using namespace std;

void flush()
{
	for (int i = 0; i < 6; i++)
	{
		cout << "\r* " << flush;
		sleep(1);
		cout << "\r *" << flush;
		sleep(1);
	}
}

int TemperatureCheck(float temperature)
{
	if (temperature > 102 || temperature < 95) 
	{
		cout << "Temperature critical!\n";
		flush();
		return 0;
	}
	return 1;
}

int PulseCheck(float pulseRate)
{
	if (pulseRate < 60 || pulseRate > 100)
	{
		cout << "Pulse Rate is out of range!\n";
		flush();
		return 0;
	}
	return 1;
}

int OxygenCheck(float spo2)
{
	if (spo2 < 90) 
	{
		cout << "Oxygen Saturation out of range!\n";
		flush();
		return 0;
	}
	return 1;
}

bool vitalsOk(float temperature, float pulseRate, float spo2) 
{
	return (TemperatureCheck(temperature) && PulseCheck(pulseRate) && OxygenCheck(spo2));
}

int main() {
  assert(!vitalsOk(99, 102, 70));
  assert(vitalsOk(98.1, 70, 98));
  cout << "Done\n";
}
