// Singleton.cpp
//
// Header file for modified Singleton pattern in which the destruction
// of the Singleton takes place in a Destroyer object, thus resolving
// a major problem in the classic Gamma Singleton pattern.
//
// The Destroyer class is templated while clients can create subclasses 
// of Singleton to suit their needs.
//
// Last modification dates:
//
// 1998-7-7		DD	Kick-off date
// 1998-9-15	RD	Code review, polishing up
//
// (C) Datasim Education BV 1998


#ifndef Singleton_cpp
#define Singleton_cpp

#include "Singleton.hpp"

template<class TYPE> 
Destroyer<TYPE>::Destroyer()
{ // Default constructor

	doomed_object = nullptr;
}

template<class TYPE> 
Destroyer<TYPE>::Destroyer(TYPE* t)	
{ // Constructor with reference to object to be destroyed

	doomed_object=t;
}

template<class TYPE>
Destroyer<TYPE>::Destroyer(const Destroyer<TYPE>& source)
{ // Copy constructor. Not allowed
}

template<class TYPE>
Destroyer<TYPE>& Destroyer<TYPE>::operator = (const Destroyer<TYPE>& source)
{ // Assignment operator. Not allowed

	return *this;
}

template<class TYPE> 
Destroyer<TYPE>::~Destroyer()	
{ // Destructor 
 
	delete doomed_object;
}

template<class TYPE> 
void Destroyer<TYPE>::doomed(TYPE* t)	
{ // Set the doomed object 

	doomed_object=t;
}


// Templated Singleton code
template<class TYPE> TYPE* Singleton<TYPE>::ins = nullptr;
template<class TYPE> Destroyer<TYPE> Singleton<TYPE>::des;


template<class TYPE>
Singleton<TYPE>::Singleton()
{ // Default constructor
}

template<class TYPE>
Singleton<TYPE>::Singleton(const Singleton<TYPE>& source)
{ // Copy constructor
}

template<class TYPE>
Singleton<TYPE>::~Singleton()
{ // Destructor

	int x;
	x=0;
}

template<class TYPE> 
TYPE* Singleton<TYPE>::instance()
{ // Return the singleton instance

	if (ins == nullptr)
	{
		ins=new TYPE;
		des.doomed(ins);
	}

	return ins;
}

template<class TYPE>
Singleton<TYPE>& Singleton<TYPE>::operator = (const Singleton<TYPE>& source)
{ // Assignment operator
	
	return *this;
}

#endif	// Singleton_cpp