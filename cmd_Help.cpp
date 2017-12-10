#include <iostream>
#include "headers.h"
#include "cmd_Handlers.h"
#include "cmd_Parse.h"
#include "tree_Node.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Help(const Options & options)
{
	return[command = options.path](Node * node, std::ostream & out)
	{
		out << "help..." << std::endl;


		if (command == "/")
			out << "zoznam prikazov:\nquit\list\size\tree\dump\rm\mkdir\link\touch" << std::endl;

		else if (command == "quit")
			out << "ukoncenie prace s aplikaciou" << std::endl;

		else if (command == "list")
			out << "vypis definovaneho adresara (path) alebo hlaveho adresara (default), s moznostou sledovat linky (follow) alebo sa rekurzivne vnarat do adresarov (recursive)" << std::endl;

		else if (command == "size")
			out << "vypis velkosti suboru/adresara, je moznost zahrnut odkazovane subory/adresare (follow) alebo rekurzivne pridat vnorene adresare (recursive)" << std::endl;

		else if (command == "tree")
			out << "zobrazenie stromovej štruktury pre danu cestu (path) alebo pre hlavny adresar (default); zobrazenie podobne ako prikaz tree pre MS Windows" << std::endl;

		else if (command == "dump")
			out << "vypis hierarchie danej cesty (default - hlavny adresar) v json formate" << std::endl;

		else if (command == "rm")
			out << "zmazanie suboru/adresara/odkazu" << std::endl;

		else if (command == "mkdir")
			out << "vytvorenie adresara" << std::endl;

		else if (command == "link")
			out << "vytvorenie odkazu" << std::endl;

		else if (command == "touch")
			out << "vytvorenie suboru (default velkost je 0B)" << std::endl;

		else
			out << "nespravny prikaz" << std::endl;


		return true;

	};

}