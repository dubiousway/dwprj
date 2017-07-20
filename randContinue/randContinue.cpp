#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RATESNUM 4
class Rand01{
	static int m_ranges[RATESNUM][2];
	static double m_rates[RATESNUM];

	double m_current;

	int randRateWithRangeIndex(){
		int ratesWithInt[RATESNUM];
		int total = 0;
		for (int i=0;i<RATESNUM;i++){
			ratesWithInt[i] = int(m_rates[i]*100);
			total += ratesWithInt[i];
		}
		int r = random() % total;
		int sumRates = ratesWithInt[0];
		if(r < sumRates)
			return 0;
		else if(r >= sumRates && r < (sumRates+=ratesWithInt[1]))
			return 1;
		else if(r >= sumRates && r < (sumRates+=ratesWithInt[2]))
			return 2;
		else
			return 3;
	}
	//double rand_001(int* srange){
	//	int r = random() % (srange[1] - srange[0]) + srange[0];
	//	return r * 0.001;
	//}
	double rand_001(){
		int rangeIndex = randRateWithRangeIndex();
		int* rng = m_ranges[rangeIndex];
		int r = random() % (rng[1] - rng[0]) + rng[0];
		int pm = random()%2;
		double r2 = r*0.001;
		return pm ? r2 : -r2;
	}

public:
	Rand01(double currval){
		srandom(time(NULL));	
		m_current = currval;
	}
	
	void save2file(int count){
		for(int i=0; i< count; ++i){
			double randplus = rand_001();
			m_current+= randplus;
			printf("%lf\n", m_current);
		}
	}
};

int Rand01::m_ranges[4][2] = {{0,5},{5,8},{8,10},{10,15}};
double Rand01::m_rates[] = {0.5,0.35,0.10,0.05};	// 10:7:2:1

int main(int argc, char* argv[]){
	double  initval = 80.12;
	int		ticknum = 1000;
// parameters processing
	if (argc > 1)
		ticknum = atoi(argv[1])	;
	if (argc > 2)
		initval = atof(argv[2])	;
	
	Rand01* r = new Rand01(initval);
	r->save2file(ticknum);

	return 0;
}
