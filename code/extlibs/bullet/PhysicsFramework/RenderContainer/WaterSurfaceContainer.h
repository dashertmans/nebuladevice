/* [SCE CONFIDENTIAL DOCUMENT]
 * PLAYSTATION(R)3 Programmer Tool Runtime Library 280.001
 *                Copyright (C) 2006 Sony Computer Entertainment Inc.
 *                                                All Rights Reserved.
 */

#ifndef __WATERSURFACE_CONTAINER_H__
#define __WATERSURFACE_CONTAINER_H__

#include "PhysicsFramework/RenderShape.h"
#include "PhysicsFramework/RenderContainer/RenderContainer.h"

///////////////////////////////////////////////////////////////////////////////
// WaterSurfaceContainer class

class WaterSurfaceContainer : public RenderContainer
{
private:
	ShaderProgramMesh *mShader;
	
	enum {
		VBO_VERTEX=0,
		VBO_NORMAL,
		VBO_TEXCOORD,
		VBO_ELEMENT,
		VBO_COUNT
	};

	RenderShape *mShape;	// 形状
	
	// 頂点バッファオブジェクト
	GLuint mVbo[VBO_COUNT];// 頂点属性

public:
	WaterSurfaceContainer(RenderShape *shape);
	virtual ~WaterSurfaceContainer();
	
	ContainerType getContainerType() {return ContainerTypeWaterSurface;}
	
	void setShader(const ShaderProgramBase *shader);
	ShaderProgramBase *getShader() {return mShader;}

	void printShape() {if(mShape) mShape->print();}

	// ※ 以下のメソッドはすべてmObjListを設定してから呼ぶこと
	
	void init();	// 初期化
	void release();	// 開放
	void reset();	// パラメータをセット

	// 描画
	void drawContainer(const Matrix4 &wvpMatrix,const Vector3 &lightPos,const Vector3 &eyePos);
};

#endif /* __WATERSURFACE_CONTAINER_H__ */
