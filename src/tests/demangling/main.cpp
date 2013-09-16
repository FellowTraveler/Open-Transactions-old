#include <iostream>
#include <execinfo.h>
#include <cxxabi.h>


using namespace std;

std::string get_backtraced_name() { // will be mangled

  void* array[50];
	size_t size = backtrace(array, 50);
  char ** messages = backtrace_symbols(array, size);

	size_t nr=1;
	if (size<=nr) return "(none)";

	std::string mangled_name( messages[nr] );

	int status;
	char * real_name = abi::__cxa_demangle(mangled_name.c_str(), 0, 0, &status);

	std::string name = (status==0 
		? std::string("demangled:") + real_name 
		: std::string("mangled:") + mangled_name);

	if (real_name) free(real_name);
	// TODO free array and messages

	return name;
}

template <int N=2011, class T>
void foo( const T &obj ) {
	std::cout << "In function " << __FUNCTION__ << " as " << get_backtraced_name() << " "<<N<<" "<<obj<<std::endl;
}

int main() {
	foo<5555>(4242);
	foo<5555>(3.14);
	foo<7777>(3.14);
	foo<1337>(3.14);
	foo(4242);

}

