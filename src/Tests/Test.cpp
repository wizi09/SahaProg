/*
 * Test.cpp
 *
 *  Created on: 03 - 11 -  2017
 *      Author: Abdallah Benkadja
 *       Email: abdou9989@gmail.com
 */

#include "Test.h"

/**
 * Fonction de test rapide ...
 */
void Test::testTest()
{
	std::cout << ">> ================== Testing " << __FUNCTION__ << " =========================" << endl;

	std::cout << ">> ===========================================================================" << endl;
}
/*
 * Fonction de test de la librairie Dlib
 */
void Test::testDlib()
{


}
/*
 * Fonction de test de la librairie Boost
 */
void Test::testBoost()
{
	cout << endl;
	boost::thread thrd(&Test::hello);
	thrd.join();
	cout << ">> Main DOne." << endl << endl;

}
/*
 * Fonction hello qui affiche un message informant le bon fonctionnement de Boost
 */
void Test::hello()
{
	   // Recupere le nom d'utilisateur en fonction de la plateforme.
	#ifdef _WIN32
	    string username(getenv("USERNAME"));
	#elif LINUX || __linux__ || __APPLE__
	    string username(getenv("USER"));
	#endif

	    cout << ">> Thread : Hey " << username << ",  Boost fonctionne correctement :-) !!" << endl << endl;


}
