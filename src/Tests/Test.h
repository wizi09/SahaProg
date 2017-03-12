/*
 * Test.h
 *
 *  Created on: 03 - 11 - 2017
 *      Author: Abdallah Benkadja
 */

#ifndef TEST_H_
#define TEST_H_

// Dependences
// STL
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// Boost
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/thread/thread.hpp>

// Gnu Scientific Library
#include <gsl/gsl_sf_bessel.h>

// dLIB
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <dlib/image_transforms.h>
#include <dlib/bayes_utils.h>
#include <dlib/graph_utils.h>
#include <dlib/graph.h>
#include <dlib/directed_graph.h>

// Namespaces
using namespace std;
using namespace dlib;


/**
 * Classe statique permettant d'effectuer les tests des classes et fonctions generale a eKin.
 */
class Test
{
public:
	static void testGSL();
	static void testTest();
	static void testDlib();
	static void testBoost();
	static void hello();
};

#endif /* TEST_H_ */
