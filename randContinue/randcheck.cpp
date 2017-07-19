#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

class Rand01{
	static int m_ranges[3][2];
	static double m_rates[];

	double m_current;

	int randRateWithRangeIndex(){
		int rangeWithInt[3];
		int total = 0;
		for (int i=0;i<3;i++){
			rangeWithInt[i] = int(m_rates[i]*100);
			total += rangeWithInt[i];
		}
		int r = random() % total;
		if(r < rangeWithInt[0])
			return 0;
		else if(r >= rangeWithInt[0] + rangeWithInt[1])
			return 2;
		else
			return 1;
	}
	double rand_001(){
		int rangeIndex = randRateWithRangeIndex();
		int* rng = m_ranges[rangeIndex];
		int r = random() % (rng[1] - rng[0]) + rng[0];
		return r*0.01;
	}

public:
	Rand01(double currval){
		srandom(time(NULL));	
		m_current = currval;
	}
	
	void check(int count){
		int c1 = 0, c2 = 0,c3 = 0;
		for(int i=0; i< count; ++i){
			double randplus = rand_001();
			if(randplus < 0.05)
				c1++;
			else if(randplus >= 0.08)
				c3++;
			else
				c2++;
		}
		printf("%5d %5d %5d", c1,c2,c3);
	}
};

int Rand01::m_ranges[3][2] = {{0,5},{5,8},{8,10}};
double Rand01::m_rates[] = {0.5,0.35,0.15};	// 10:7:3

int main(){
	Rand01* r = new Rand01(80.12);
	r->check(1000);

	return 0;
}
