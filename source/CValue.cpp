#include "../headers/CValue.h"

CValue::CValue(char *str)
	:string(str)
{
}

// dd/mm/yyyy hh:mn:sc.ms
// yyyy 	0,4
// yy		2,2
// dd		8,2
// mm		5,2
// hh		11,2
// mn		14,2
// sc		17,2
// ms		20,length()
const char* CValue::toDate(string format){
	string out = "";
	for( int i = 0; i < format.length(); i++ ){
		if( toupper(format[i]) == 'Y' && toupper(format[i+1]) == 'Y' ){
			i += 2;
			if( toupper(format[i]) == 'Y' && toupper(format[i+1]) == 'Y' ){
				out += substr(0,4);
				i++;
			}
			else{
				out += substr(2,2);
			}
		}
		else if( toupper(format[i]) == 'D' && toupper(format[i+1]) == 'D' ){
			out += substr(8,2);
			i++;
		}
		else if( toupper(format[i]) == 'M' && toupper(format[i+1]) == 'M' ){
			i++;
			out += substr(5,2);
		}
		else if( toupper(format[i]) == 'H' && toupper(format[i+1]) == 'H' ){
			i++;
			out += substr(11,2);
		}
		else if( toupper(format[i]) == 'M' && toupper(format[i+1]) == 'N' ){
			i++;
			out += substr(14,2);
		}
		else if( toupper(format[i]) == 'S' && toupper(format[i+1]) == 'C' ){
			i++;
			out += substr(17,2);
		}
		else if( toupper(format[i]) == 'M' && toupper(format[i+1]) == 'S' ){
			i++;
			out += substr(20, length());
		}
		else{
			out += format[i];
		}
	}
	return out.c_str();
}

int CValue::toInt(){
	return atoi(c_str());
}

double CValue::toDouble(){
	return atof(c_str());
}
