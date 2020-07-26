#include "FamilyTree.hpp"
#include <iostream>
#include "doctest.h"
using namespace std;
/**
TEST_CASE("Test relation and add and find")
{
	family::Tree T("josh");			 // Yosef is the "root" of the tree (the youngest person).
	T.addFather("josh", "daniel")	 // Tells the tree that the father of Yosef is Yaakov.
		.addMother("josh", "Rachel") // Tells the tree that the mother of Yosef is Rachel.
		.addFather("daniel", "drake")
		.addMother("daniel", "eve")
		.addFather("Rachel", "russel")
		.addMother("Rachel", "goldy")
		.addFather("drake", "carol")
		.addMother("drake", "shanon")
		.addFather("carol", "micheal")
		.addMother("carol", "shere")
		.addFather("shanon", "jack")
		.addMother("shanon", "lara")
		.addFather("micheal", "mike")
		.addMother("micheal", "laila")
		.addFather("jack", "jackal")
		.addMother("jack", "christine")
		.addFather("lara", "sam")
		.addFather("mike", "fred")
		.addMother("lara", "samantha");
	CHECK(T.relation("daniel") == string("father"));
	CHECK(T.relation("Rachel") == string("mother"));
	CHECK(T.relation("drake") == string("grandfather"));
	CHECK(T.relation("eve") == string("grandmother"));
	CHECK(T.relation("russel") == string("grandfather"));
	CHECK(T.relation("goldy") == string("grandmother"));
	CHECK(T.relation("carol") == string("great-grandfather"));
	CHECK(T.relation("shanon") == string("great-grandmother"));
	CHECK(T.relation("micheal") == string("great-great-grandfather"));
	CHECK(T.relation("shere") == string("great-great-grandmother"));
	CHECK(T.relation("lara") == string("great-great-grandmother"));
	CHECK(T.relation("jack") == string("great-great-grandfather"));
	CHECK(T.relation("laila") == string("great-great-great-grandmother"));
	CHECK(T.relation("mike") == string("great-great-great-grandfather"));
	CHECK(T.relation("jackal") == string("great-great-great-grandfather"));
	CHECK(T.relation("christine") == string("great-great-great-grandmother"));
	CHECK(T.relation("jackal") == string("great-great-great-grandfather"));
	CHECK(T.relation("sam") == string("great-great-great-grandfather"));
	CHECK(T.relation("samantha") == string("great-great-great-grandmother"));
	CHECK(T.find("father") == string("daniel"));
	CHECK(T.relation("mother") == string("Rachel"));
	CHECK(T.relation("grandfather") == string("drake"));
	CHECK(T.relation("grandmother") == string("eve"));
	CHECK(T.relation("great-grandfather") == string("carol"));
	CHECK(T.relation("great-grandmother") == string("shanon"));
	CHECK(T.relation("great-great-grandfather") == string("micheal"));
	CHECK(T.relation("great-great-grandmother") == string("shere"));
	CHECK(T.relation("great-great-great-grandmother") == string("laila"));
	CHECK(T.relation("great-great-great-grandfather") == string("mike"));
	CHECK(T.relation("great-great-great-grandfather") == string("fred"));
}
*/

TEST_CASE("Test remove if removed parents all should be removed except for josh")
{
	family::Tree T("josh");			 // Yosef is the "root" of the tree (the youngest person).
	T.addFather("josh", "daniel")	 // Tells the tree that the father of Yosef is Yaakov.
		.addMother("josh", "Rachel") // Tells the tree that the mother of Yosef is Rachel.
		.addFather("daniel", "drake")
		.addMother("daniel", "eve")
		.addFather("Rachel", "russel")
		.addMother("Rachel", "goldy")
		.addFather("drake", "carol")
		.addMother("drake", "shanon")
		.addFather("carol", "micheal")
		.addMother("carol", "shere")
		.addFather("shanon", "jack")
		.addMother("shanon", "lara")
		.addFather("micheal", "mike")
		.addMother("micheal", "laila")
		.addFather("jack", "jackal")
		.addMother("jack", "christine")
		.addFather("lara", "sam")
		.addFather("mike", "fred")

		.addMother("lara", "samantha");

	T.remove("daniel");
	T.remove("Rachel");

	CHECK(T.relation("daniel") == string("unrelated"));
	CHECK(T.relation("Rachel") == string("unrelated"));
	CHECK(T.relation("drake") == string("unrelated"));
	CHECK(T.relation("eve") == string("unrelated"));
	CHECK(T.relation("russel") == string("unrelated"));
	CHECK(T.relation("goldy") == string("unrelated"));
	CHECK(T.relation("carol") == string("unrelated"));
	CHECK(T.relation("shanon") == string("unrelated"));
	CHECK(T.relation("micheal") == string("unrelated"));
	CHECK(T.relation("shere") == string("unrelated"));
	CHECK(T.relation("jack") == string("unrelated"));
	CHECK(T.relation("lara") == string("unrelated"));
	CHECK(T.relation("mike") == string("unrelated"));
	CHECK(T.relation("laila") == string("unrelated"));
	CHECK(T.relation("jackal") == string("unrelated"));
	CHECK(T.relation("christine") == string("unrelated"));
	CHECK(T.relation("sam") == string("unrelated"));
	CHECK(T.relation("fred") == string("unrelated"));
	CHECK(T.relation("jackal") == string("unrelated"));
	CHECK(T.relation("samantha") == string("unrelated"));
	family::Tree T1("mike");
	T1.addFather("mike","mark");
	T1.addMother("mike","sara");
	T1.addMother("sara","jorg");
	
	
	
}
TEST_CASE("Test for Family Tree") 
{
    family::Tree T ("fabio"); 
	T.addFather("fabio", "nissan")   
	 .addMother("fabio", "hefzi")  
	 .addFather("nissan", "Samuel")
	 .addMother("nissan", "Rivka")
	 .addFather("Samuel", "Isaac")
     .addMother("Samuel", "Sarah");
	
    CHECK( T.relation("nissan") == string("father"));
    CHECK( T.relation("hefzi") == string("mother"));
    CHECK( T.relation("Samuel") == string("grandfather"));
    CHECK( T.relation("Rivka") == string("grandmother"));
    CHECK( T.relation("Isaac") == string("great-grandfather"));
    CHECK( T.relation("Sarah") == string("great-grandmother"));
    CHECK(T.relation("fabio")== string("me"));

    CHECK(T.find("mother")==string("hefzi"));
    CHECK(T.find("father")==string("nissan"));
    CHECK(T.find("grandmother")==string("Rivka"));
    CHECK(T.find("grandfather")==string("Samuel"));
    CHECK(T.find("me")==string("fabio")); 
    CHECK(T.find("great-grandmother")==string("Sarah"));          
    CHECK(T.find("great-grandfather")==string("Isaac"));               
    
     T.remove("Isaac") ;              
    CHECK(T.relation("Isaac")==string("unrelated"));
    CHECK(T.relation("Terah")==string("unrelated"));
    CHECK(T.relation("haim")==string("unrelated"));
    CHECK(T.relation("yosi")==string("unrelated"));
    CHECK(T.relation("kobi")==string("unrelated"));
    CHECK(T.relation("afi")==string("unrelated"));
}
TEST_CASE("Building the tree - avi") 
{
    family::Tree T ("avi"); 
	T.addFather("avi", "dani")   
	 .addMother("avi", "rachel")  
	 .addFather("dani", "kobi")
	 .addMother("dani", "rina")
	 .addFather("kobi", "rahamim")
     .addMother("kobi", "Sarah");

     CHECK( T.relation("dani") == string("father"));
    CHECK( T.relation("rachel") == string("mother"));
    CHECK( T.relation("kobi") == string("grandfather"));
    CHECK( T.relation("rina") == string("grandmother"));
    CHECK( T.relation("rahamim") == string("great-grandfather"));
    CHECK( T.relation("Sarah") == string("great-grandmother"));
    CHECK(T.relation("avi")== string("me"));

    
    CHECK(T.find("mother")==string("rachel"));
    CHECK(T.find("father")==string("dani"));
    CHECK(T.find("grandmother")==string("rina"));
    CHECK(T.find("grandfather")==string("kobi"));
    CHECK(T.find("me")==string("avi")); 
    CHECK(T.find("great-grandmother")==string("Sarah"));          
    CHECK(T.find("great-grandfather")==string("rahamim"));  

     T.remove("rahamim");               
    CHECK(T.relation("rahamim")==string("unrelated"));
    CHECK(T.relation("Terah")==string("unrelated"));
    CHECK(T.relation("haim")==string("unrelated"));
    CHECK(T.relation("yoske")==string("unrelated"));
    CHECK(T.relation("kobib")==string("unrelated"));
    CHECK(T.relation("afi")==string("unrelated"));
}

TEST_CASE("Building the tree - mati") 
{
    family::Tree T("mati");
    T.addFather("mati", "or");
    T.addFather("or", "haim");
    T.addFather("haim", "leiv");
    T.addFather("leiv", "kobi");
    T.addFather("kobi", "momo");
    T.addMother("mati", "orli");
    T.addMother("orli", "titi");
    T.addMother("titi", "bell");
    T.addMother("bell", "gori");
    T.addMother("gori", "chlsea");

    CHECK(T.relation("mati") == string("me"));
    CHECK(T.relation("or") == string("father"));
    CHECK(T.relation("haim") == string("grandfather"));
    CHECK(T.relation("leiv") == string("great-grandfather"));
    CHECK(T.relation("kobi") == string("great-great-grandfather"));
    CHECK(T.relation("momo") == string("great-great-great-grandfather"));
    CHECK(T.relation("orli") == string("mother"));
    CHECK(T.relation("titi") == string("grandmother"));
    CHECK(T.relation("bell") == string("great-grandmother"));
    CHECK(T.relation("gori") == string("great-great-grandmother"));
    CHECK(T.relation("chlsea") == string("great-great-great-grandmother"));
    CHECK(T.relation("avi") == string("unrelated"));
    CHECK(T.relation("didi") == string("unrelated"));
    CHECK(T.relation("avshi") == string("unrelated"));
    CHECK(T.relation("avshi") == string("unrelated"));
    CHECK(T.relation("dror") == string("unrelated"));
    CHECK(T.relation("tzah") == string("unrelated"));
    CHECK(T.relation("tomer") == string("unrelated"));

    CHECK(T.find("me") == string("mati"));
    CHECK(T.find("father") == string("or"));
    CHECK(T.find("grandfather") == string("haim"));
    CHECK(T.find("great-grandfather") == string("leiv"));
    CHECK(T.find("great-great-grandfather") == string("kobi"));
    CHECK(T.find("great-great-great-grandfather") == string("momo"));
    CHECK(T.find("mother") == string("orli"));

    T.remove("bell");
    CHECK(T.relation("mati") == string("me"));
    CHECK(T.relation("or") == string("father"));
    CHECK(T.relation("haim") == string("grandfather"));
    CHECK(T.relation("leiv") == string("great-grandfather"));
    CHECK(T.relation("kobi") == string("great-great-grandfather"));
    CHECK(T.relation("momo") == string("great-great-great-grandfather"));
    CHECK(T.relation("orli") == string("mother"));
    CHECK(T.relation("titi") == string("grandmother"));
    CHECK(T.relation("bell") == string("unrelated"));
    CHECK(T.relation("gori") == string("unrelated"));
    CHECK(T.relation("chlsea") == string("unrelated"));
}
TEST_CASE("A Tree for Gorg") 
{
    family::Tree T ("gorg"); 
	T.addFather("gorg", "mike")   
	 .addMother("gorg", "sarah")  
	 .addFather("mike", "sasi")
	 .addMother("mike", "carla")
	 .addFather("sarah", "kobi")
     .addMother("sarah", "kati");

     CHECK( T.relation("mike") == string("father"));
    CHECK( T.relation("sarah") == string("mother"));
    CHECK( T.relation("sasi") == string("grandfather"));
    CHECK( T.relation("carla") == string("grandmother"));
    CHECK( T.relation("kobi") == string("grandfather"));
    CHECK( T.relation("kati") == string("grandmother"));
    CHECK(T.relation("gorg")== string("me"));

    CHECK(T.find("mother")==string("sarah"));
    CHECK(T.find("father")==string("mike"));
    CHECK(T.find("grandmother")==string("carla"));
    CHECK(T.find("grandfather")==string("sasi"));
    
    CHECK(T.find("me")==string("gorg")); 
    CHECK(T.find("grandmother")==string("carla"));          
    CHECK(T.find("grandfather")==string("sasi"));  

   T.remove("kobi");               
    CHECK(T.relation("Isaac")==string("unrelated"));
    CHECK(T.relation("Terah")==string("unrelated"));
    CHECK(T.relation("haim")==string("unrelated"));
    CHECK(T.relation("yosi")==string("unrelated"));
    CHECK(T.relation("kobi")==string("unrelated"));
    CHECK(T.relation("afi")==string("unrelated"));
    CHECK(T.relation("miko")==string("unrelated"));
    CHECK(T.relation("didi")==string("unrelated"));
    CHECK(T.relation("moki")==string("unrelated"));
    CHECK(T.relation("daniel")==string("unrelated"));
	
	
    CHECK( T.relation("mike") == string("father"));
    CHECK( T.relation("sarah") == string("mother"));
    CHECK( T.relation("sasi") == string("grandfather"));
    CHECK( T.relation("carla") == string("grandmother"));
    CHECK( T.relation("kobi") != string("great-grandfather"));
    CHECK( T.relation("kati") != string("great-grandmother"));
    CHECK(T.relation("gorg")== string("me"));

}
