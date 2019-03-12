//
//  MC33063A_calculator.cpp
//  
//
//  Created by Grant Giesbrecht on 25/2/19.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <sstream>
#include "KTable.hpp"
#include <IEGA/string_manip.hpp>

//CXCOMPILE clang++ -o calc MC33063A_calculator.cpp -lIEGA KTable.o -std=c++11
//CXCOMPILE ./calc
//CXGENRUN FALSE

using namespace std;

int main(int argc, char** argv){

	//Values used in design for GEQ2.M1A.R1
//	double Vsat = 1;
//	double Vfrwd = .45;
//	double Vin_min = 5;
//	double Vin_max = 12;
//	double Vout = -12;
//	double Iout = .1;
//	double f = 100e3;
//	double Vripple = .1;
	
	double Vsat = 1;
	double Vfrwd = .4;
	double Vin_min = 5;
	double Vin_max = 12;
	double Vout = -12;
	double Iout = .1;
	double f = 100e3;
	double Vripple = .1;
	
	double to_tof_min = (abs(Vout)+Vfrwd)/(Vin_min-Vsat);
	double to_tof_max = (abs(Vout)+Vfrwd)/(Vin_max-Vsat);
	
	double period = 1./f;
	
	double toff_min = period/(to_tof_min+1);
	double toff_max = period/(to_tof_max+1);
	
	double ton_min = period - toff_min;
	double ton_max = period - toff_max;
	
	double Ct_min = 4e-5*ton_min;
	double Ct_max = 4e-5*ton_max;
	
	double f_approx_min = 59.57447e-6/Ct_min;
	double f_approx_max = 59.57447e-6/Ct_max;
	
	double Ipk_min = 2*Iout*(to_tof_min + 1);
	double Ipk_max = 2*Iout*(to_tof_max + 1);
	
	double Rsc_min = .3/Ipk_min;
	double Rsc_max = .3/Ipk_max;
	
	double Lmin_min = (Vin_min - Vsat)/Ipk_min*ton_min;
	double Lmin_max = (Vin_max - Vsat)/Ipk_max*ton_max;
	
	double Co_min = 9*Iout*ton_min/Vripple;
	double Co_max = 9*Iout*ton_max/Vripple;
	
	//----------------------- Print table -------------------------------
	//
	
	KTable kt;
	kt.table_title("Calculation Results");
	kt.row({"", "Value (Vin = min)", "Value (Vin = max)"});
	kt.row({"Ton/Toff", dtos(to_tof_min), dtos(to_tof_max)});
	kt.row({"Ton (us)", dtos(ton_min*1e6), dtos(ton_max*1e6)});
	kt.row({"Toff (us)", dtos(toff_min*1e6), dtos(toff_max*1e6)});
	kt.row({"Ct (pF)", dtos(Ct_min*1e12), dtos(Ct_max*1e12)});
	kt.row({"Ipk (mA)", dtos(Ipk_min), dtos(Ipk_max)});
	kt.row({"Rsc", dtos(Rsc_min), dtos(Rsc_max)});
	kt.row({"Lmin (uH)", dtos(Lmin_min), dtos(Lmin_max)});
	kt.row({"Co (uF)", dtos(Co_min), dtos(Co_max)});
	kt.row({"Freq (kHz)", dtos(f_approx_min), dtos(f_approx_max)});
	kt.row({"Power (mW)", dtos(Ipk_min*Vin_min*to_tof_min/(to_tof_min+1)*1e3), dtos(Ipk_max*Vin_max*to_tof_max/(to_tof_max+1)*1e3)});
	
	KTable mini;
	mini.table_title("User Define Parameters:");
	mini.row({"Vsat = ", dtos(Vsat)});
	mini.row({"Vfrwd", dtos(Vfrwd)});
	mini.row({"Vin_min", dtos(Vin_min)});
	mini.row({"Vin_max", dtos(Vin_max)});
	mini.row({"Vout", dtos(Vout)});
	mini.row({"Iout", dtos(Iout)});
	mini.row({"f", dtos(f)});
	mini.row({"Vripple", dtos(Vripple)});
	mini.set(KTABLE_HBARCHAR, '*');
	mini.set(KTABLE_INTERWALLS, false);
	mini.set(KTABLE_SIDEWALLS, false);
	mini.set(KTABLE_TOPBOTTOMHBAR, false);
	mini.set(KTABLE_HEADERINTERWALLS, false);
	mini.set(KTABLE_HEADERHBAR, false);
	mini.alignh(0, 'l');
	mini.alignh(1, 'r');
	mini.alignc(0, 'l');
	
//	size_t count = 0;
//	while(true){
//		if (kt.nxtgood()){
//			cout << kt.nxtstr();
//		}
//		if (count++ >= 2 && mini.nxtgood()){
//			cout << "\t\t" << mini.nxtstr();
//		}
//		cout << endl;
//		if (!kt.nxtgood() && !mini.nxtgood()){
//			break;
//		}
//	}
	
	cout << KTable::parallel({kt, mini}, {"\t\t"}, {0, 2}) << endl;

	return 0;
}
