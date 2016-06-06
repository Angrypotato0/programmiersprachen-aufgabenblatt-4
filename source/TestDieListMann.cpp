

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "List.hpp"



TEST_CASE("Construktor", "[aufgabe4.1]") {
  List<int> list1 {};
  REQUIRE(list1.empty() == true);
}

TEST_CASE("size überprüfen", "[aufgabe4.1]") {
  List<int> list1 {};
  REQUIRE(list1.size() == 0);
}


TEST_CASE("push_front", "[aufgabe4.2]") {
  List<int> list; 
  list.push_front(42); 
  REQUIRE(42 == list.front() );

  List<int> list2;
  list2.push_front(42);
  list2.push_front(345);
  list2.push_front(13);
  REQUIRE(13 == list2.front());

  List<int> list3;
  list3.push_front(42);
  list3.push_front(84);
  list3.push_front(11);
  list3.push_front(20);
  REQUIRE(20 == list3.front());
} 

TEST_CASE("push_back", "[aufgabe4.2]") {
  List<int> list {}; 
  list.push_back(42); 
  REQUIRE(42 == list.last());

  List<int> list2 {};
  list2.push_back(12);
  list2.push_back(15);
  list2.push_back(69);
  REQUIRE(69 == list2.last());

  List<int> list3 {};
  list3.push_back(1);
  list3.push_back(12);
  list3.push_back(42);
  list3.push_back(69);
  REQUIRE(69 == list3.last());
} 

TEST_CASE("pop_front", "[aufgabe4.2]") {
  List<int> list {}; 
  list.push_back(42); 
  list.pop_front();
  REQUIRE(true == list.empty());

  List<int> list1 {};
  list1.push_back(4);
  list1.push_back(69);
  list1.pop_front();
  REQUIRE(69 == list1.front());

  List<int> list2 {};
  list2.push_back(42);
  list2.push_back(98);
  list2.push_back(8);
  list2.push_back(65);
  list2.push_back(4);
  list2.pop_front();
  REQUIRE(98 == list2.front());
} 

TEST_CASE("pop_back", "[aufgabe4.2]") {
  List<int> list {}; 
  list.push_back(42); 
  list.pop_back();
  REQUIRE(true == list.empty());

  List<int> list1 {};
  list1.push_back(42);
  list1.push_back(69);
  list1.pop_back();
  REQUIRE(42 == list1.last());

  List<int> list2 {};
  list2.push_back(42);
  list2.push_back(182);
  list2.push_back(74);
  list2.push_back(3);
  list2.pop_back();
  REQUIRE(74 == list2.last());
} 

TEST_CASE("clear", "[aufgabe4.3]") {
  List<int> list; 
  list.push_front(1); 
  list.push_front(2); 
  list.push_front(3); 
  list.push_front(4); 
  list.push_front(5);
  list.push_front(6);
  list.clear(); 
  REQUIRE(list.empty());

  List<int> list1; 
  list1.push_front(30); 
  list1.push_front(21); 
  list1.push_front(199); 
  list1.push_front(136); 
  list1.push_front(19);
  list1.push_front(221);
  list1.clear(); 
  REQUIRE(list1.empty());
}


TEST_CASE("begin and end", "[aufgabe4.5]") {
  List<int> list;
  auto b = list.begin(); 
  auto e = list.end(); 
  REQUIRE(b == e);
}

TEST_CASE("pointer begin", "[aufgabe4.5]") {
  List<int> list; 
  list.push_front(42); 
  REQUIRE(42 == *list.begin());

  List<int> list1; 
  list1.push_back(69); 
  list1.push_back(101);
  list1.push_back(36);
  list1.push_back(46);
  REQUIRE(69 == *list1.begin());
}

TEST_CASE("2 Listen vergleichen ==", "[aufgabe4.6]") {
  List<int> list1 {};
  list1.push_back(42); 
  list1.push_back(69);
  list1.push_back(101);

  List<int> list2 {};
  list2.push_back(42);
  list2.push_back(69);
  list2.push_back(101);
  REQUIRE(list1 == list2);

  List<int> list3 {};
  List<int> list4 {};
  REQUIRE(list3 == list4);

  List<int> list5 {};
  list5.push_back(678); 
  list5.push_back(144);
  list5.push_back(123);
  list5.push_back(42);
  list5.push_back(69);
  
  List<int> list6 {};
  list6.push_back(678); 
  list6.push_back(144);
  list6.push_back(123);
  list6.push_back(42);
  list6.push_back(69);
  REQUIRE(list5 == list6);
}

TEST_CASE("2 listen vergleichen !=", "[aufgabe4.6]") {
  List<int> list1 {};
  list1.push_back(42); 
  list1.push_back(69);
  list1.push_back(101);

  List<int> list2 {};
  list2.push_back(42);
  list2.push_back(4);
  list2.push_back(101);
  REQUIRE(list1 != list2);

  List<int> list3 {};
  list3.push_back(3);
  List<int> list4 {};
  REQUIRE(list3 != list4);

  List<int> list5 {};
  list5.push_back(876); 
  list5.push_back(441);
  list5.push_back(234);
  list5.push_back(24);
  list5.push_back(96);


  List<int> list6 {};
  list6.push_back(678); 
  list6.push_back(144);
  list6.push_back(123);
  list6.push_back(42);
  list6.push_back(69);
  REQUIRE(list5 != list6);
}

TEST_CASE("Liste übergeben", "[aufgabe4.7]") {
  List<int> list; 
  list.push_front(1); 
  list.push_front(2); 
  list.push_front(3); 
  list.push_front(4); 
  List<int> l2{list}; 
  REQUIRE(list == l2);

  List<int> list1; 
  list1.push_front(69); 
  list1.push_front(42); 
  list1.push_front(101); 
  list1.push_front(264); 
  list1.push_front(9); 
  List<int> list2{list1}; 
  REQUIRE(list1 == list2);
}

TEST_CASE("insert", "[aufgabe4.8]") {
  List<int> list; 
  list.push_front(69); 
  list.push_front(42); 
  list.push_front(101); 
  list.push_front(264); 
  list.push_front(9); 
  list.insert(list.begin(), 13);
  REQUIRE(6 == list.size());
  REQUIRE(13 == list.front());
  REQUIRE(69 == list.last());

  List<int> list2; 
  list2.push_front(69); 
  list2.push_front(42); 
  list2.push_front(101); 
  list2.push_front(264); 
  list2.push_front(9); 
  list2.insert(list2.end(), 69);
  REQUIRE(6 == list2.size());
  REQUIRE(9 == list2.front());
  REQUIRE(69 == list2.last());

  List<int> list3; 
  list3.push_front(69); 
  list3.push_front(42); 
  list3.push_front(101); 
  list3.push_front(264); 
  list3.push_front(9); 
  ListIterator<int> pos = list3.begin();
  pos++; 
  ++pos;
  ++pos; 
  list3.insert(pos, 13);
  REQUIRE(6 == list3.size());
  REQUIRE(9 == list3.front());
  REQUIRE(69 == list3.last());
  ListIterator<int> it = list3.begin();
  REQUIRE(9 == *it); 
  ++it; 
  REQUIRE(264 == *it); 
  ++it;
  REQUIRE(101 == *it); 
  ++it;
  REQUIRE(13 == *it); 
}

TEST_CASE("ListIterator", "[aufgabe4.9]") {
    
  List<int> list; 
  list.push_back(1); 
  list.push_back(2); 
  list.push_back(3); 
  list.push_back(4); 
  list.push_back(5);
  list.reverse();
  ListIterator<int> it = list.begin();
  REQUIRE(5 == *it);
  ++it;
  REQUIRE(4 == *it);
  ++it; 
  REQUIRE(3 == *it);
  ++it;
  REQUIRE(2 == *it);
  ++it; 
  REQUIRE(1 == *it);

    
  reverse(list);
  ListIterator<int> i = list.begin();
  REQUIRE(5 == *i);
  ++i;
  REQUIRE(4 == *i);
  ++i; 
  REQUIRE(3 == *i);
  ++i;
  REQUIRE(2 == *i);
  ++i; 
  REQUIRE(1 == *i);

}

TEST_CASE("vektor übergabe", "[aufgabe4.10]") {
  List<int> list; 
  list.push_back(1); 
  list.push_back(2); 
  list.push_back(3); 
  list.push_back(4); 
  list.push_back(5);
  std::vector<unsigned int> v1(list.size());
  std::copy(list.begin(), list.end(), std::begin(v1));
  
  REQUIRE(1 == v1[0]);
  REQUIRE(2 == v1[1]);
  REQUIRE(3 == v1[2]);
  REQUIRE(4 == v1[3]);
  REQUIRE(5 == v1[4]);
}

TEST_CASE("übergeben und ListIterator", "[aufgabe4.11]") {
    
  List<int> list1 {}; 
  list1.push_back(1); 
  list1.push_back(2); 
  list1.push_back(3); 
  list1.push_back(4); 
  list1.push_back(5);

  List<int> list2 {}; 
  list2.push_back(10); 
  list2.push_back(20); 
  list2.push_back(30); 
  list2.push_back(40); 
  list2.push_back(50);

  list1.swap(list2);
  ListIterator<int> i = list1.begin();
  REQUIRE(10 == *i);
  ++i;
  REQUIRE(20 == *i);
  ++i; 
  REQUIRE(30 == *i);
  ++i;
  REQUIRE(40 == *i);
  ++i; 
  REQUIRE(50 == *i);

    
  List<int> list5 {}; 
  list5.push_back(1); 
  list5.push_back(2); 
  list5.push_back(3); 
  list5.push_back(4); 
  list5.push_back(5);

  List<int> list6 {}; 
  list6.push_back(10); 
  list6.push_back(20); 
  list6.push_back(30); 
  list6.push_back(40); 
  list6.push_back(50);

  swap(list5, list6);
  ListIterator<int> iter = list5.begin();
  REQUIRE(10 == *iter);
  ++iter;
  REQUIRE(20 == *iter);
  ++iter; 
  REQUIRE(30 == *iter);
  ++iter;
  REQUIRE(40 == *iter);
  ++iter; 
  REQUIRE(50 == *iter);

  ListIterator<int> itera = list6.begin();
  REQUIRE(1 == *itera);
  ++itera;
  REQUIRE(2 == *itera);
  ++itera; 
  REQUIRE(3 == *itera);
  ++itera;
  REQUIRE(4 == *itera);
  ++itera; 
  REQUIRE(5 == *itera);

    
  List<int> list3 {};
  list3.push_back(1); 
  list3.push_back(2); 
  list3.push_back(3); 
  list3.push_back(4); 
  list3.push_back(5);

  List<int> list4 {}; 

  list4 = list3;
  ListIterator<int> ite = list4.begin();
  REQUIRE(1 == *ite);
  ++ite;
  REQUIRE(2 == *ite);
  ++ite; 
  REQUIRE(3 == *ite);
  ++ite;
  REQUIRE(4 == *ite);
  ++ite; 
  REQUIRE(5 == *ite);

}

TEST_CASE("Destruktor + Moves", "[aufgabe4.12]") {
  List<int> list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.push_front(5);
  list.push_front(6);
  list.push_front(7);


  List<int> list2(std::move(list));
  REQUIRE(0 == list.size());
  REQUIRE(list.empty());
  REQUIRE(7 == list2.size());
}



int main(int argc, char * argv[]) {

  return Catch::Session().run(argc, argv);

}

