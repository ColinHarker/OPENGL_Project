#include <GL/glew.h>
#include <gl/GLU.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */


    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
  
    if (glewInit() != GLEW_OK) {
        std::cout << "error! \n";
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << "\n";

    std::array<float, 6> positions = {
     -0.5f, -0.5f,
      0.0f,  0.5f,
      0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), &positions, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0 );


    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

       /* glColor3f(1, 0, 0);
        GLUquadric* quad;
        quad = gluNewQuadric();
        glTranslatef(2, 2, 2);
        gluSphere(quad, 25, 100, 20);
        */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}