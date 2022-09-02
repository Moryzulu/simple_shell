#include <stdio.h>
#include <unistd.h>
/**
 * Main - function to print laptop details that are in stock
 *
 * Return: void
 */ 
int main(void)
{
	struct laptop {

		char model[20];
		float cpu_speed;
		int hdd_size;
		float cost;
	
	};

	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();

	struct laptop detail1 = {"ASUS", 1.6, 250, 1800};
	struct laptop detail2 = {"Toshiba Satelite", 2.0, 500, 4500};
	struct laptop detail3 = {"HP Probook", 1.6, 250, 4000};

	printf("\nHere is what your laptop details are:\n\n");
	printf("Model: %s\n Cpu: %0.2fghz\n Hdd: %dGB\n Cost: K%6.2f\n\n", detail1.model, detail1.cpu_speed, detail1.hdd_size, detail1.cost);
	printf("Model: %s\n Cpu: %0.2fghz\n Hdd: %dGB\n Cost: K%6.2f\n\n", detail2.model, detail2.cpu_speed, detail2.hdd_size, detail2.cost);	
	printf("Model: %s\n Cpu: %0.2fghz\n Hdd: %dGB\n Cost: K%6.2f\n\n", detail3.model, detail3.cpu_speed, detail3.hdd_size, detail3.cost);
	printf("pid is %u\n\n", pid);
	printf("ppid is %u\n\n", ppid);
	return (0);
}	

