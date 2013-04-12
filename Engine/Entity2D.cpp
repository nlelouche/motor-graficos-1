//----------------------------------------------------------------
#include "Entity2D.h"
#include "Renderer.h"
//----------------------------------------------------------------
Entity2D::Entity2D()
:
m_kName(""),
m_fPosX(0),
m_fPosY(0),
m_fPosZ(0),
m_fWidth(0),
m_fHeigh(0),
m_fRotation(0),
m_bVisible(true)
{

}
//----------------------------------------------------------------
void Entity2D::draw (Renderer * rkRenderer)
{
	// set the world matrix
	rkRenderer->setMatrixMode(WORLD);

/*	//Dibujo la AABB
	if (m_bVisibleBB)
	{
		// reset the matrix
		rkRenderer->loadIdentity();
		// apply transformation
		rkRenderer->translate(m_fX, m_fY);
		rkRenderer->translate(m_fBBX, m_fBBY);
		rkRenderer->scale(m_fBBW, m_fBBH);
		rkRenderer->unbindTexture();
		rkRenderer->Draw(m_akAABBVertices, Renderer::LINE_STRIP, 5);
	}
	*/
	//Dibujo entidad
	// reset the matrix
	rkRenderer->loadIdentity();
	// apply transformation
	rkRenderer->translate(m_fPosX, m_fPosY, m_fPosZ);
	rkRenderer->rotateZ(m_fRotation * 3.14159f / 180.0f);
	/*if (m_bHFlip)
		rkRenderer->rotateX(D3DX_PI);
	else
		rkRenderer->rotateX(0);

	if (m_bVFlip)
		rkRenderer->rotateY(D3DX_PI);
	else
		rkRenderer->rotateY(0);
		*/
	if (m_bVisible)
		rkRenderer->scale(m_fWidth, m_fHeigh);
	else
		rkRenderer->scale(0, 0);

}
//----------------------------------------------------------------
void Entity2D::setName (string kName)
{
	m_kName = kName;
}
//----------------------------------------------------------------
const string& Entity2D::getName () const
{
	return m_kName;
}
//--------------------------------------------------------------
//----------------------------------------------------------------
