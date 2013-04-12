#ifndef ENTITY2D_H
#define ENTITY2D_H
//-----------------------------------------------------------
//Includes
#include "Defines.h"
#include "Structs.h"
//-----------------------------------------------------------
class Renderer;
//-----------------------------------------------------------
class ENGINE_API Entity2D {

// constructor y destructor
protected:
	Entity2D();
public:
	virtual ~Entity2D () { /***/ }
//-----------------------------------------------------------
// seteo y devuelvo el nombre
	void setName (string kName);
	const string& getName () const;
//-----------------------------------------------------------
// interface

	virtual void draw (Renderer * rkRenderer);
	//virtual void update (float fTimeBetweenFrames);
//----------------------------------------------------------------
private:
	string m_kName;
	// posicion, rotacion y dimension
	float m_fPosX, m_fPosY, m_fPosZ;
	float m_fWidth, m_fHeigh;
	float m_fRotation;
	bool m_bVisible;
//-----------------------------------------------------------

};
#endif //ENTITY2D_H