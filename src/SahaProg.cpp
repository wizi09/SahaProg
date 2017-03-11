/*
 *  SahaProg.cpp
 *  
 *      Author : Abdallah Benkadja
 *  	Email  : abdou9989@gmail.com
 */


//STL
#include <iostream>
// Config
#include "SahaProgCmakeConfig.h"
// Qt
#include <QApplication>
#include <QTextCodec>

#if SAHAPROG_BUILD_TEST_VERSION
#include "Tests/Test.h"
#endif

using namespace std;
/**
 * Set les codecs pour permettre la lecture des accents.
 */
void setAppCodecs()
{
#ifdef _WIN32
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1252"));
#elif LINUX || __linux__ || __APPLE__
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
}


#if SAHAPROG_BUILD_TEST_VERSION
/**
 * Lance les fonctions de test.
 * \param int \b argc : nombre d'arguments passe au programme (le programme represente lui meme le premier argument).
 * \param char** \b argv : tableau a une dimension de chaines de caracteres contenant les arguments du programme sous forme de string.
 * \return int : retourne le statut de l'application apres execution : 0.
 */
int runTests(int argc, char* argv[])
{
    cout << "*********************************** Start eKin Tests ******************************************" << endl;
    QApplication app(argc, argv);

    setAppCodecs();
    //checkLocale("en_US.UTF-8");
    //Test::testTest();
    //Test::testBoost();
    //Test::testGSL();
    Test::testDlib();
    // ************** TestServer ************
    
    cout << endl << ">> --- Test(s) Done ---" << endl;
    return app.exec();
}
#endif


/**
 * Main de l'application.
 * \param int \b argc : nombre d'arguments passe au programme (le programme represente lui meme le premier argument).
 * \param char** \b argv : tableau a une dimension de chaines de caracteres contenant les arguments du programme sous forme de string.
 * \return int : retourne le statut de l'application apres execution.
 */
int main(int argc, char** argv)
{
    /*
#ifdef __APPLE__
    cout << "--- MAC_OS_X_VERSION_MIN_REQUIRED defined : " << MAC_OS_X_VERSION_MIN_REQUIRED << " ---" << endl;
#endif
    */

    int state = 0;
    bool bRunTests = true;
    

#if SAHAPROG_BUILD_TEST_VERSION
    if(bRunTests) state = runTests(argc, argv);
#endif
    
    std::cout << "*********************************** End Ekin **************************************************" << endl;
    
    return state;
}
