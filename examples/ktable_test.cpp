//
//  KTable.cpp
//  
//
//  Created by Grant Giesbrecht on 27/2/19.
//

//CXCOMPILE make
//CXCOMPILE ./ktable_test
//CXGENRUN FALSE

#include "KTable.hpp"
#include <iostream>
#include <stdio.h>

#include <sstream>
#include <cmath>

#include <IEGA/string_manip.hpp>

using namespace std;

int main(){

	KTable kt;
	
	kt.row({"", "Time 1", "Time 2"});
	kt.row({"Voltage In:", dtos(1.34), dtos(1.5)});
	kt.row({"Voltage:", dtos(1.12345678997987, 8), dtos(1.5)});
	
	kt.table_title("TE-001");
	kt.ttl_alignment('l');
	kt.hdr_alignment(1, 'r');
	kt.hdr_alignment(2, 'r');
	kt.col_alignment(0, 'c');
	
	kt.set(KTABLE_SIDEWALLS, true);
	kt.set(KTABLE_HEADERINTERWALLS, true);
	kt.set(KTABLE_INTERWALLS, true);
	kt.set(KTABLE_TITLEHBAR, true);
	kt.set(KTABLE_INTERHBARS, true);
//	kt.set(KTABLE_COLPADDING, 3.0);
	kt.set(KTABLE_JOINTCHAR, '*');
	kt.set(KTABLE_HBARCHAR, '=');
	kt.set(KTABLE_WALLCHAR, 'I');
	
	
	cout << kt.str() << endl;
	
//	KTable table;
	
	//First step: data entry
	// With calls to the "row" command, you can add elements to the table
	// row by row. It accepts stings or doubles as input.
	
//	table.row("Vq1 (Vpp)", -17.4, " thanks ", -.000732, 1e15, -.08);
//	table.row("Vq2 (Vpp)", -100.3, " thanked ", "-", 30e3, -.22);
	
	//The input data are stored in columns. Alternatively, you can enter the
	// data column by column...
	
//	table.clear();
//	table.col("Vc1", "Vc2", "Vc3");
//	table.col(-12.4, -19.8);
	
	//The second step is to specify formats
	// Each column can have formats assigned such as how to display numbers,
	// (scientific notation vs fix vs float, decimal precision, and if error
	// ranges are to be specified), alignment of values, and if #/string are
	// to be aligned differently, if $ is to be prefixed, or units appended,
	// or OOM shifted w/ appropriately changed units
	
//	table.frmt(2, "Center", "float"); //Col IDX,
	
	//The third stip is to give the command to generate the table.
	
	return 0;
}
