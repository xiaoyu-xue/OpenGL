#pragma once

#include <GL/glew.h>
#include "ForwardDecl.h"

namespace OpenGL
{

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))


    void GLClearError();
    bool GLLogCall(const char* function, const char* file, int line);

    class Renderer
    {
    private:
        Camera* mpCamera;
        Scene* mpScene;
        int mWidth, mHeight;
		bool mMouseLeftDown;
		bool mMouseRightDown;
		bool mMouseMiddleDown;
        bool mDrawWireFrame;
		float mMouseX, mMouseY;
    public:
        Renderer();
        void Init();
        void Resize(int width, int height);
        void SetSize(int width, int height);
        void SetScene(Scene *scene);
        void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
        void DrawFaces(const DrawableObject &object) const;
        void DrawWireFrame(const DrawableObject& object) const;
        void DrawFaces() const;
        void DrawWireFrame() const;
        void SetCamera(Camera *camera);
        void Clear() const;
        void EnableDepthTest() const;
        void DisableDepthTest() const;

        inline Camera* GetCamera() const { return mpCamera; }

		void MouseButtonEvent(int button, int action, int mods);
		void KeyBoardEvent(int key, int event, int mods, float deltaTime);
		void CursorEvent(float x, float y);

        static unsigned int IsReady();

    private:
        void MouseRightDrag(float x, float y);
        void MouseLeftDrag(float x, float y);
        void MouseMiddleDrag(float x, float y);
        void MouseLeftRightDrag(float x, float y);
    };

}