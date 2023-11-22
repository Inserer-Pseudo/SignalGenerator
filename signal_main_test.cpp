#include <iostream>

//----------------------------------------------------------------------
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN	/*! Use if doctest with its own main function*/
#include "doctest.h"		// Get the last version online
//----------------------------------------------------------------------
/*
#define TEST_ACCESSEURS
#define TEST_2
#define TEST_3
#define TEST_4_BIS
#define TEST_4
#define TEST_5
#define TEST_6
#define TEST_7 */

#include "Dummy.hpp"
#include "Sinus.hpp"
//----------------------------------------------------------------------
#ifdef TEST_ACCESSEURS
TEST_CASE("1. Signal Class (virtual) - Concrete class = Sinus - Basic accessors and low-level Signal parameters") {
	Sinus	mySinus{};
	float 	testValue{2.0};
	
	CHECK(mySinus.getA0() == doctest::Approx(defaultA0));
	
	mySinus.setA0(testValue);
	CHECK(mySinus.getA0() == doctest::Approx(testValue));
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_2 // faire un setter pour avoir un fichier par type de signal
TEST_CASE("2. Signal Class (virtual) - Concrete class = Sinus / default value / non const obj - generate function") {

	Sinus	mySinus{};
		
	REQUIRE(mySinus.getA0() == doctest::Approx(defaultA0));
	REQUIRE(mySinus.getAmplitude() == doctest::Approx(defaultAmplitude));
	REQUIRE(mySinus.getOmega() == doctest::Approx(defaultOmega));
	REQUIRE(mySinus.getPhi0() == doctest::Approx(defaultPhi0));
	
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1800};
	
	unsigned int FileSize = mySinus.generate();
	
	//CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	//CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_3
TEST_CASE("3. Signal Class (virtual) - Concrete class = Dummy / default value / const obj - generate function") {

	const Sinus		mySinus{};
		
	REQUIRE(mySinus.getA0() == doctest::Approx(defaultA0));
	REQUIRE(mySinus.getAmplitude() == doctest::Approx(defaultAmplitude));
	REQUIRE(mySinus.getOmega() == doctest::Approx(defaultOmega));
	REQUIRE(mySinus.getPhi0() == doctest::Approx(defaultPhi0));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1849};
	
	unsigned int FileSize = mySinus.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_4_BIS

TEST_CASE("Test du constructeur paramétrique"){
	Sinus mySinus;

	mySinus.setA0(0.5);
	mySinus.setAmplitude(2.0);
	mySinus.setOmega(1.0);
	mySinus.setPhi0(3.0);

	CHECK(mySinus.getA0() == doctest::Approx(0.5));
	CHECK(mySinus.getAmplitude() == doctest::Approx(2.0));
	CHECK(mySinus.getOmega() == doctest::Approx(1.0));
	CHECK(mySinus.getPhi0() == doctest::Approx(3.0));


	SinusParam ParamSinus2{1.0,2.5,3.0,4.0};
	Sinus mySinus2{ParamSinus2};

	CHECK(mySinus2.getA0() == doctest::Approx(1.0));
	CHECK(mySinus2.getAmplitude() == doctest::Approx(2.5));
	CHECK(mySinus2.getOmega() == doctest::Approx(3.0));
	CHECK(mySinus2.getPhi0() == doctest::Approx(4.0));

}


const Sinus mySinus{};




#endif 
#ifdef TEST_4
TEST_CASE("4. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / non const obj - generate function") {
	
	DummyParam 	dc12{12.0};
	
	Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_5
TEST_CASE ("5. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / const obj - generate function") {
	
	DummyParam 	dc12{12.0};
	
	const Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_6
TEST_CASE("6. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / non const obj - generate function - FileName = dummy.data") {
	
	DummyParam 	dc12{12.0};
	
	Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{"./dummy.data"};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate(FileName);
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
#ifdef TEST_7
TEST_CASE("7. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / const obj - generate function - FileName = dummy.data") {
	
	DummyParam 	dc12{12.0};
	
	const Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{"./dummy.data"};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate(FileName);
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
#endif
//----------------------------------------------------------------------
