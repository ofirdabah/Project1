#include "Helper.h"
#include <crtdbg.h>
using namespace std;
#include <crtdbg.h>
using namespace std;

#define new MYDEBUG_NEW

#ifdef _DEBUG
#define MYDEBUG_NEW new( NORMAL_BLOCK, __FILE, __LINE_)
#else
#define MYDEBUG_NEW new
#endif


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Facebook meta;
	Helper UX;
	UX.console(meta);
}